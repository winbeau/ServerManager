#ifndef SERVERMANAGER_BOARDWINDOW_H
#define SERVERMANAGER_BOARDWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QVector>
#include <QString>
#include <QTime>
#include <QTImer>
#include <QRandomGenerator>
#include <set>
#include <queue>

#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

#define CEIL       0.8
#define AVAIL      (0.98 + QRandomGenerator::global()->generateDouble() * 0.02 - 0.01)
#define OPERATE(x) ((int)(x * AVAIL))
#define CEIL_OP(x)    ((int)(x * CEIL))

QT_BEGIN_NAMESPACE
namespace Ui { class boardwindow; }
QT_END_NAMESPACE

class boardwindow : public QMainWindow {
Q_OBJECT

public:
    explicit boardwindow(QWidget *parent = nullptr);

    ~boardwindow() override;

    void initTable();

    void initDbData();

    void initTaskChart();

    void initMemoChart();

    void initGpuChart();

private:
    QTimer *timer500;
    QTimer *timer1000;
    int taskCnt, finishCnt, failedCnt, ingCnt, todoCnt;
    int allMemo, freeMemo, occupyMemo;
    int allGpu, freeGpu, occupyGpu;
    bool fla2000TC, fla2000MC, fla2000GC; // 2000ms图表刷新flag
    QChart *taskChart, *memoChart, *gpuChart;
    QPieSeries *taskSeries, *memoSeries, *gpuSeries;
    struct Task {
        QString id;
        int cpu;
        int gpu;
        int disk;
        int bandwidth;
        time_t start;
        time_t during;
        bool status;
    };
    struct cmpDuring {
        bool operator()(const Task& a, const Task& b) const {
            return a.during > b.during; // 小顶堆
        }
    };
    struct cmpStart {
        bool operator()(const Task& a, const Task& b) const {
            return a.start > b.start; // 小顶堆
        }
    };
    struct Server {
        QString id;
        QString ip;
        int port;
        int cpu;
        int gpu;
        int disk;
        int bandwidth;
        int free_cpu;
        int free_gpu;
        int free_disk;
        int free_bandwidth;
        bool status;
        time_t last;
        std::priority_queue<Task, std::vector<Task>, cmpDuring> tasks;
    };
    Ui::boardwindow *ui;
    QSqlDatabase db;
    QSqlTableModel *m3;
    QVector<Task> taskArray;
    QVector<Task> failedArray;
    QVector<Server> serverArray;
    QVector<Server> workingArray;
    std::priority_queue<Task, std::vector<Task>, cmpStart> todoTasks;

private slots:
    void initDistributeTask(QVector<Task> &taskArr);

    void timeoutSlot500();

    void timeoutSlot2000();

    void updateTaskChartData();

    void updateTaskChartSlot();

    void updateMemoChartData();

    void updateMemoChartSlot();

    void updateGpuChartData();

    void updateGpuChartSlot();

    void updateDataSlot();

public:
    static void activateServer(Server &ser);

    static void activateTask(const Task &tas);
};


#endif //SERVERMANAGER_BOARDWINDOW_H
