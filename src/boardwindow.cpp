#include "boardwindow.h"
#include "ui_boardwindow.h"

#define AI 1

boardwindow::boardwindow(QWidget *parent) :
        QMainWindow(parent), fla2000TC(true),
        ui(new Ui::boardwindow) {
    ui->setupUi(this);

    /// 初始化更新信号
    timer500 = new QTimer;
    timer500->start(500);
    connect(timer500, &QTimer::timeout, this, &boardwindow::timeoutSlot500);

    timer1000 = new QTimer;
    timer1000->start(1000);
    connect(timer1000, &QTimer::timeout, this, &boardwindow::timeoutSlot2000);

    /// 初始化表格
    initTable();

    /// 初始化数据
    initDbData();

    /// 初始化任务图表
    taskChart = new QChart;
    taskSeries = new QPieSeries;
    initTaskChart();

    /// 初始化内存图表
    memoChart = new QChart;
    memoSeries = new QPieSeries;
    initMemoChart();

    /// 初始化显存图表
    gpuChart = new QChart;
    gpuSeries = new QPieSeries;
    initGpuChart();

    /// 任务首次分配
    initDistributeTask(taskArray);
}

boardwindow::~boardwindow() {
    timer500->stop();
    timer1000->stop();

    delete ui;
    delete timer500;
    delete timer1000;
    delete m3;
    delete taskChart;
    delete memoChart;
    delete gpuChart;
    delete taskSeries;
    delete memoSeries;
    delete gpuSeries;
}

#if AI

void boardwindow::initDistributeTask(QVector<Task> &taskArr) {
    for (auto &task: taskArr) {
        int flag = 0;
        // 修复1：添加资源有效性检查
        if (task.cpu <= 0 || task.gpu <= 0 || task.disk <= 0 || task.bandwidth <= 0) {
            qDebug() << "Invalid task requirements:" << task.id;
            continue;
        }

        // 现有工作服务器分配
        for (auto &server: workingArray) {
            // 修复2：添加服务器状态检查
            if (server.status &&
                server.cpu - server.free_cpu + task.cpu <= CEIL_OP(server.cpu) &&
                server.gpu - server.free_gpu + task.gpu <= CEIL_OP(server.gpu) &&
                server.disk - server.free_disk + task.disk <= CEIL_OP(server.disk) &&
                server.bandwidth - server.free_bandwidth + task.bandwidth <= CEIL_OP(server.bandwidth))
            {
                // 修复3：添加资源更新验证
                if (server.free_cpu >= task.cpu) {
                    server.free_cpu -= task.cpu;
                    server.free_gpu -= task.gpu;
                    server.free_disk -= task.disk;
                    server.free_bandwidth -= task.bandwidth;
                    server.tasks.emplace(task);
                    flag = 1;
                    break; // 找到可用服务器后跳出循环
                }
            }
        }

        if (flag) continue;

        // 新增服务器分配
        for (int i = 0; i < serverArray.size(); i++) { // 修复4：改为从0开始遍历
            // 修复5：添加服务器激活状态检查
            if (!serverArray[i].status &&
                    serverArray[i].cpu - serverArray[i].free_cpu + task.cpu <= CEIL_OP(serverArray[i].cpu) &&
                    serverArray[i].gpu - serverArray[i].free_gpu + task.gpu <= CEIL_OP(serverArray[i].gpu) &&
                    serverArray[i].disk - serverArray[i].free_disk + task.disk <= CEIL_OP(serverArray[i].disk) &&
                    serverArray[i].bandwidth - serverArray[i].free_bandwidth + task.bandwidth <= CEIL_OP(serverArray[i].bandwidth))
            {
                // 修复6：深度拷贝服务器对象
                Server newServer = serverArray[i];
                newServer.free_cpu -= task.cpu;
                newServer.free_gpu -= task.gpu;
                newServer.free_disk -= task.disk;
                newServer.free_bandwidth -= task.bandwidth;
                newServer.tasks.emplace(task);
                workingArray.emplace_back(newServer);
                activateServer(serverArray[i]);
                flag = 1;
                break; // 找到可用服务器后跳出循环
            }
        }

        // 修复7：处理分配失败的任务
        if (!flag) {
            qDebug() << "Task" << task.id << "failed to allocate";
            failedArray.emplace_back(task); // 添加到失败队列
        }
    }
}

#else

void boardwindow::initDistributeTask(QVector<Task> &taskArr) {
    for (auto &task: taskArr) {
        int flag = 0;
        for (auto &server: workingArray) {
            if (task.cpu <= CEIL_OP(server.free_cpu) &&
                task.gpu <= CEIL_OP(server.free_gpu) &&
                task.disk <= CEIL_OP(server.free_disk) &&
                task.bandwidth <= CEIL_OP(server.free_bandwidth)) {
                server.free_cpu -= task.cpu;
                server.free_gpu -= task.gpu;
                server.free_disk -= task.disk;
                server.free_bandwidth -= task.bandwidth;
                server.tasks.emplace(task); // 工作组中服务器已激活 无需再激活
                flag = 1;
            }
        }

        if (flag) continue;
        else flag = 0;

        for (int i = (int) workingArray.size(); i < serverArray.size(); i++) {
            if (task.cpu <= CEIL_OP(serverArray[i].free_cpu) &&
                task.gpu <= CEIL_OP(serverArray[i].free_gpu) &&
                task.disk <= CEIL_OP(serverArray[i].free_disk) &&
                task.bandwidth <= CEIL_OP(serverArray[i].free_bandwidth)) {
                workingArray.emplace_back(serverArray[i]);
                workingArray.back().free_cpu -= task.cpu;
                workingArray.back().free_gpu -= task.gpu;
                workingArray.back().free_disk -= task.disk;
                workingArray.back().free_bandwidth -= task.bandwidth;
                workingArray.back().tasks.emplace(task);
                activateServer(serverArray[i]); // 新增服务器 需要激活
                flag = 1;
            }
        }

        if (flag) continue;

        todoTasks.emplace(task); // 对所有服务首次分发任务 若有剩余任务添加至to do数组
    }
}

#endif

void boardwindow::timeoutSlot500() {
    /// 更新数据
    updateDataSlot();
}

void boardwindow::timeoutSlot2000() {
    /// 更新任务图表
    updateTaskChartSlot();
    /// 更新内存
    updateMemoChartSlot();
    /// 更新显存
    updateGpuChartSlot();
}

void boardwindow::initTable() {
    m3 = new QSqlTableModel;
    m3->setTable("sta");
    //m3->setFilter("status = 0");
    // total_weight (下标8列)降序排序
    m3->setSort(13, Qt::DescendingOrder);
    m3->select();

    ui->leftTable->setModel(m3);
    ui->leftTable->verticalHeader()->setHidden(true); // 隐藏行号
    ui->leftTable->setColumnHidden(1, true);
    ui->leftTable->setColumnHidden(2, true);
    ui->leftTable->setColumnHidden(3, true);
    ui->leftTable->setColumnHidden(4, true);
    ui->leftTable->setColumnHidden(5, true);
    ui->leftTable->setColumnHidden(6, true);
    ui->leftTable->setColumnHidden(12, true);
    ui->leftTable->setColumnHidden(13, true);
}

void boardwindow::initDbData() {
    /// 任务数组初始化
    QSqlQuery taskQuery("SELECT id, cpu, gpu, disk, bandwidth, start, during, status "
                        "FROM task WHERE status = 0 ORDER BY start ASC");
    while (taskQuery.next()) {
        taskArray.emplace_back(Task{taskQuery.value("id").toString(),
                                    taskQuery.value("cpu").toInt(),
                                    taskQuery.value("gpu").toInt(),
                                    taskQuery.value("disk").toInt(),
                                    taskQuery.value("bandwidth").toInt(),
                                    taskQuery.value("start").toLongLong(),
                                    taskQuery.value("during").toLongLong(),
                                    taskQuery.value("status").toBool()
        });
    }

    /// 服务器数组初始化
    QSqlQuery serverQuery("SELECT id, ip, port, "
                          "cpu, gpu, disk, bandwidth, "
                          "free_cpu, free_gpu, free_disk, free_bandwidth, "
                          "status "
                          "FROM sta WHERE status = 0 ORDER BY total_weight DESC");

    while (serverQuery.next()) {
        serverArray.emplace_back(Server{serverQuery.value("id").toString(),
                                        serverQuery.value("ip").toString(),
                                        serverQuery.value("port").toInt(),
                                        serverQuery.value("cpu").toInt(),
                                        serverQuery.value("gpu").toInt(),
                                        serverQuery.value("disk").toInt(),
                                        serverQuery.value("bandwidth").toInt(),
                                        OPERATE(serverQuery.value("cpu").toInt()),
                                        OPERATE(serverQuery.value("gpu").toInt()),
                                        OPERATE(serverQuery.value("disk").toInt()),
                                        OPERATE(serverQuery.value("bandwidth").toInt()),
                                        serverQuery.value("status").toBool(), 0
        });
    }

    /// 服务器工作数组初始化
    if (!serverArray.empty()) {
        workingArray.emplace_back(serverArray[0]);
        activateServer(serverArray[0]); // 激活服务器
    }
}

void boardwindow::initTaskChart() {
    taskSeries->append("已完成", finishCnt);
    taskSeries->append("已失败", failedCnt);
    taskSeries->append("进行中", ingCnt);
    taskSeries->append("待处理", todoCnt);
    taskSeries->setPieSize(1.2);
    taskSeries->setHoleSize(0.6);

    taskChart->addSeries(taskSeries);
    taskChart->setTitle("任务完成情况");
    taskChart->setAnimationOptions(QChart::AllAnimations); // 打开动画
    taskChart->setLocalizeNumbers(false);

    // 设置图例靠左对齐
    taskChart->legend()->setAlignment(Qt::AlignLeft);

    // 调整图表边距留出标签空间
    taskChart->setMargins(QMargins(40, 0, 20, 0)); // 左边界加大

    {// 设置背景??
        taskChart->setBackgroundBrush(QBrush(Qt::transparent)); // 使QChart背景透明
        taskChart->setPlotAreaBackgroundVisible(false); // 隐藏绘图区背景
//        slice->setPen(Qt::NoPen);       // 取消边界线
//        for (auto slice: taskSeries->slices()) {
//            slice->setBorderColor(Qt::transparent);
//        }
    }

    ui->taskView->setChart(taskChart);
    ui->taskView->setRenderHint(QPainter::Antialiasing); // 抗锯齿
}

void boardwindow::initMemoChart() {
    memoSeries->append("可用", freeMemo);
    memoSeries->append("已用", occupyMemo);
    memoSeries->setPieSize(2.0);
    memoSeries->setHoleSize(0.6);

    memoChart->addSeries(memoSeries);
    memoChart->setTitle("内存占用");
    memoChart->setAnimationOptions(QChart::AllAnimations); // 打开动画
    memoChart->setLocalizeNumbers(false);

    ui->memoView->setChart(memoChart);
    ui->memoView->setRenderHint(QPainter::Antialiasing); // 抗锯齿
}

void boardwindow::initGpuChart() {
    gpuSeries->append("可用", freeGpu);
    gpuSeries->append("已用", occupyGpu);
    gpuSeries->setPieSize(2.0);
    gpuSeries->setHoleSize(0.6);

    gpuChart->addSeries(gpuSeries);
    gpuChart->setTitle("显存占用");
    gpuChart->setAnimationOptions(QChart::AllAnimations); // 打开动画
    gpuChart->setLocalizeNumbers(false);

    ui->gpuView->setChart(gpuChart);
    ui->gpuView->setRenderHint(QPainter::Antialiasing); // 抗锯齿
}


void boardwindow::updateDataSlot() {
    /// 更新所有服务器状态
    for (auto &server: workingArray) {
        server.last += 500;
        int flag = 0; // 判断是否有任务完成
        while (!server.tasks.empty() && server.tasks.top().during <= server.last) {
            server.free_cpu += server.tasks.top().cpu;
            server.free_gpu += server.tasks.top().gpu;
            server.free_disk += server.tasks.top().disk;
            server.free_bandwidth += server.tasks.top().bandwidth;
            activateTask(server.tasks.top());
            server.tasks.pop();
            flag = 1;
        }

        if (flag == 0) continue;

        /// 添加待完成任务
        while (!todoTasks.empty()) { // 贪心策略 由于服务器由性能高到低 前面的任务不能完成 后面服务器大概率也不能完成
            if (todoTasks.top().start <= server.last) { // 任务理应开始时间若小于服务器已运行时间 判定任务失败
                server.tasks.emplace(todoTasks.top());
                server.free_cpu -= todoTasks.top().cpu;
                server.free_gpu -= todoTasks.top().gpu;
                server.free_disk -= todoTasks.top().disk;
                server.free_bandwidth -= todoTasks.top().bandwidth;
            }
            //failedArray.emplace_back(todoTasks.top());
            todoTasks.pop();
        }
        /// @这可能是任务2s即没的原因
        /// @关闭窗口会崩溃

        /// 更新数据库
        QSqlQuery updateServer;
        updateServer.prepare(
                "UPDATE sta SET "
                "free_cpu = ?, free_gpu = ?, "
                "free_disk = ?, free_bandwidth = ? "
                "WHERE id = ?"
        );
        updateServer.addBindValue(server.free_cpu);
        updateServer.addBindValue(server.free_gpu);
        updateServer.addBindValue(server.free_disk);
        updateServer.addBindValue(server.free_bandwidth);
        updateServer.addBindValue(server.id);
        if (!updateServer.exec()) {
            qDebug() << "database update failed!" << updateServer.lastError().text();
        }

    }

    /// 更新表格
    m3->select();
}

void boardwindow::updateTaskChartData() {
    QSqlQuery countQuery("SELECT COUNT(*) FROM task");
    if (countQuery.next()) {
        taskCnt = countQuery.value(0).toInt();
    }

    if (!countQuery.exec()) {
        qDebug() << "Count query failed:" << countQuery.lastError();
    }

    QSqlQuery finishedQuery("SELECT COUNT(*) FROM task WHERE status = 1");
    if (finishedQuery.next()) {
        finishCnt = finishedQuery.value(0).toInt();
    }

    if (!finishedQuery.exec()) {
        qDebug() << "Count query failed:" << countQuery.lastError();
    }

    todoCnt = (int) todoTasks.size();
    failedCnt = (int) failedArray.size();
    ingCnt = taskCnt - finishCnt - failedCnt - todoCnt;
}

void boardwindow::updateTaskChartSlot() {
    /// 更新数据
    updateTaskChartData();

    ui->finishTaskLabel->setText("完成任务数：" + QString::number(finishCnt));
    ui->todoTaskLabel->setText("待完成任务数：" + QString::number(todoCnt));
    ui->failTaskLabel->setText("失败任务数：" + QString::number(failedCnt));
    ui->finishTaskLabel->setAlignment(Qt::AlignCenter);
    ui->todoTaskLabel->setAlignment(Qt::AlignCenter);
    ui->failTaskLabel->setAlignment(Qt::AlignCenter);

    QList<QPieSlice *> slices = taskSeries->slices();
    if (slices.empty()) return;
    int flag = 0;
    if (slices[0]->value() != finishCnt) slices[0]->setValue(finishCnt);
    else ++flag;
    if (slices[1]->value() != failedCnt) slices[1]->setValue(failedCnt);
    else ++flag;
    if (slices[2]->value() != ingCnt) slices[2]->setValue(ingCnt);
    else ++flag;
    if (slices[3]->value() != todoCnt) slices[3]->setValue(todoCnt);
    else ++flag;
    if (flag == 4) fla2000TC = false;
}

void boardwindow::updateMemoChartData() {
    QSqlQuery sumQuery;
    sumQuery.prepare("SELECT SUM(free_cpu), SUM(cpu) FROM sta WHERE status = 1");

    if (sumQuery.exec() && sumQuery.next()) {
        freeMemo = sumQuery.value(0).isNull() ? 0 : sumQuery.value(0).toInt();
        allMemo = sumQuery.value(1).isNull() ? 0 : sumQuery.value(1).toInt();
    } else
        qDebug() << "Memo query failed:" << sumQuery.lastError();

    occupyMemo = allMemo - freeMemo;
}

void boardwindow::updateMemoChartSlot() {
    updateMemoChartData(); // 更新数据

    ui->memoLabel->setText("内存：" + QString::number(occupyMemo) + " MB");
    ui->memoLabel->setAlignment(Qt::AlignCenter);

    QList<QPieSlice *> slices = memoSeries->slices();
    if (slices.empty()) return;
    int flag = 0;
    if (slices[0]->value() != freeMemo) slices[0]->setValue(freeMemo);
    else ++flag;
    if (slices[1]->value() != occupyMemo) slices[1]->setValue(occupyMemo);
    else ++flag;
    if (flag == 2) fla2000MC = false;
}

void boardwindow::updateGpuChartData() {
    QSqlQuery sumQuery;
    sumQuery.prepare("SELECT SUM(free_gpu), SUM(gpu) FROM sta WHERE status = 1");

    if (sumQuery.exec() && sumQuery.next()) {
        freeGpu = sumQuery.value(0).isNull() ? 0 : sumQuery.value(0).toInt();
        allGpu = sumQuery.value(1).isNull() ? 0 : sumQuery.value(1).toInt();
    } else
        qDebug() << "Gpu query failed:" << sumQuery.lastError();

    occupyGpu = allGpu - freeGpu;
}

void boardwindow::updateGpuChartSlot() {
    updateGpuChartData(); // 更新数据

    ui->gpuLabel->setText("显存：" + QString::number(occupyGpu) + " MB");
    ui->gpuLabel->setAlignment(Qt::AlignCenter);

    QList<QPieSlice *> slices = gpuSeries->slices();
    if (slices.empty()) return;
    int flag = 0;
    if (slices[0]->value() != freeGpu) slices[0]->setValue(freeGpu);
    else ++flag;
    if (slices[1]->value() != occupyGpu) slices[1]->setValue(occupyGpu);
    else ++flag;
    if (flag == 2) fla2000GC = false;
}

void boardwindow::activateServer(Server &ser) {
    // ser.status = true;
    QSqlQuery updateServer;
    updateServer.prepare("UPDATE sta SET status = ? WHERE id = ?");
    updateServer.addBindValue(1);
    updateServer.addBindValue(ser.id);
    if (!updateServer.exec()) {
        qDebug() << "servers:sta update failed!" << updateServer.lastError().text();
    }
}

void boardwindow::activateTask(const Task &tas) {

    QSqlQuery updateTask;
    updateTask.prepare("UPDATE task SET status = ? WHERE id = ?");
    updateTask.addBindValue(1); //在数据库中更新任务状态
    updateTask.addBindValue(tas.id);
    if (!updateTask.exec()) {
        qDebug() << "servers:task update failed!" << updateTask.lastError().text();
    }
}
