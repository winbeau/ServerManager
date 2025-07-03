#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addwindow.h"

mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::mainwindow) {
    ui->setupUi(this);
    ui->allWidget->hide();

    // .表示当前目录，..表示上一级目录
    // 当前目录在buidl文件夹下，所以要../转到ServerManager文件夹下
    QPixmap pixLogo("../icons/logo.png");

    if(!pixLogo.isNull()) { // 设置图片缩放
        pixLogo = pixLogo.scaled(100, 100, Qt::KeepAspectRatio);
        ui->logoLabel->setPixmap(pixLogo);
        ui->logoLabel->setScaledContents(true); // 自动缩放图片适应标签大小
    }

    QPixmap pixCpu("../icons/cpu.png");

    if(!pixCpu.isNull()) { // 设置图片缩放
        pixCpu = pixCpu.scaled(100, 100, Qt::KeepAspectRatio);
        ui->cpuIcon->setPixmap(pixCpu);
        ui->cpuIcon->setScaledContents(true); // 自动缩放图片适应标签大小
    }

    QPixmap pixDisk("../icons/disk.png");

    if(!pixDisk.isNull()) { // 设置图片缩放
        pixDisk = pixDisk.scaled(100, 100, Qt::KeepAspectRatio);
        ui->diskIcon->setPixmap(pixDisk);
        ui->diskIcon->setScaledContents(true); // 自动缩放图片适应标签大小
    }

// @distriButton变色
//    connect(board, &boardwindow::destroyed, this, [this]() {
//        qDebug() << "Board window closed";
//    });

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName("servers");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("@Geralt123");

    if (db.open()) {
        qDebug() << "database connected";

        m = new QSqlTableModel;
        m->setTable("sta");
        m->select();

        /// 样式自写
        setStaTableStyle();

    } else {
        qDebug() << "database not connected";
        qDebug() << db.lastError().text();
    }

    m2 = new QSqlTableModel;
    m2->setTable("sta");
    m2->select();
    ui->allTableView->setModel(m2);
    ui->allTableView->verticalHeader()->setVisible(false);

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::setStaTableStyle() {
    ui->tableView->setModel(m);
    ui->tableView->setItemDelegate(new MyTableStyle(this));
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->setColumnWidth(0, 50);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->setColumnWidth(2, 80);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->setColumnHidden(8, true);
    ui->tableView->setColumnHidden(9, true);
    ui->tableView->setColumnHidden(10, true);
    ui->tableView->setColumnHidden(11, true);
    ui->tableView->setColumnHidden(12, true);
    ui->tableView->setColumnHidden(13, true);
}

void mainwindow::on_addPushButton_clicked() {
    addwindow *add = new addwindow(socket, this);
    add->setAttribute(Qt::WA_DeleteOnClose); // 关闭窗口时自动删除对象

    connect(add, &addwindow::destroyed, this, [this]() {
        m->select();
    }); // 信号与槽

    add->show();

}

void mainwindow::on_allButton_clicked() {
    m2->select(); //刷新表格

    ui->pageWidget->hide();
    ui->allWidget->show();

    ui->allButton->setStyleSheet(
            "QPushButton {"
            "    color: rgb(0, 0, 0);"
            "    background-color: rgb(91, 221, 138);"
            "    border-color: rgb(91, 221, 138);"
            "    border-radius: 15px;"
            "    border-style: solid;"
            "    border-width: 1px;"
            "}"
    );

    ui->dashButton->setStyleSheet(
            "QPushButton {"
            "    alignment: center;"
            "    max-height: 35px;"
            "    min-height: 35px;"
            "    color: rgb(255, 255, 255);"
            "    font:200 20px;"
            "    background-color: rgb(46, 51, 57);"
            "    border: 1px solid rgb(46, 51, 57);"
            "    border-radius: 15px;"
            "}"
    );

}

void mainwindow::on_dashButton_clicked() {
    m->select(); //刷新表格

    ui->allWidget->hide();
    ui->pageWidget->show();

    ui->dashButton->setStyleSheet(
            "QPushButton {"
            "    color: rgb(0, 0, 0);"
            "    background-color: rgb(91, 221, 138);"
            "    border-color: rgb(91, 221, 138);"
            "    border-radius: 15px;"
            "    border-style: solid;"
            "    border-width: 1px;"
            "}"
    );

    ui->allButton->setStyleSheet(
            "QPushButton {"
            "    alignment: center;"
            "    max-height: 35px;"
            "    min-height: 35px;"
            "    color: rgb(255, 255, 255);"
            "    font:200 20px;"
            "    background-color: rgb(46, 51, 57);"
            "    border: 1px solid rgb(46, 51, 57);"
            "    border-radius: 15px;"
            "}"
    );
}

void mainwindow::on_distriButton_clicked() {
    ui->distriButton->setStyleSheet(
            "QPushButton {"
            "    alignment: center;"
            "    max-height: 35px;"
            "    min-height: 35px;"
            "    color: rgb(255, 255, 255);"
            "    font:200 20px;"
            "    background-color: rgb(114, 214, 214);"
            "    border: 1px solid rgb(114, 214, 214);"
            "    border-radius: 15px;"
            "}"
    );

    boardwindow *board = new boardwindow(this);
    board->setAttribute(Qt::WA_DeleteOnClose); // 关闭窗口时自动删除对象

    board->show();
}

void mainwindow::on_imitateButton_clicked() {
    imitatewindow *imitate = new imitatewindow;
    imitate->setAttribute(Qt::WA_DeleteOnClose); // 关闭窗口时自动删除对象
    imitate->show();
}

void MyTableStyle::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    int cpu = index.sibling(index.row(), 3).data().toInt();          // CPU列索引
    int free_cpu = index.sibling(index.row(), 7).data().toInt();     // free_cpu列索引
    double percent = (cpu - free_cpu) * 100.0 / cpu;
    switch (index.column()) {
        case 0: {
            drawPercent(painter, option, percent);
        }
            break;
        case 1: {
            drawLeftText(painter, option, index);
        }
            break;
        case 2: {
            drawProgressBar(painter, option, percent);
        }
            break;
    }
}

void MyTableStyle::drawPercent(QPainter *painter, const QStyleOptionViewItem &option, double percent) const {
    // 绘制圆角背景
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QRect rect = option.rect.adjusted(5, 5, -5, -5); // 控制边距大小
    QPainterPath path;
    path.addRoundedRect(rect, 5, 5);  // 圆角半径3px
    if (percent < 80) painter->fillPath(path, QColor(91, 221, 138));  // 背景色 -绿色
    else painter->fillPath(path, QColor(241, 13, 72)); // 背景色 -红色
    // 绘制百分比
    QFont font = painter->font();
    font.setWeight(QFont::Bold); // 设置粗体
    painter->setFont(font);
    painter->setPen(Qt::white);
    painter->drawText(rect, Qt::AlignCenter, QString::number(percent, 'f', 1) + "%");
    painter->restore();
}

void MyTableStyle::drawLeftText(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QRect rect = option.rect.adjusted(0, 6, 0, 0); //
    painter->drawText(rect, Qt::AlignLeft, // id在第0行列
                      index.sibling(index.row(), 0).data().toString());
}

void MyTableStyle::drawProgressBar(QPainter *painter, const QStyleOptionViewItem &option, double percent) const {
    // 绘制圆角背景
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QRect rect = option.rect.adjusted(5, 8, -5, -8); // 控制边距大小
    QPainterPath path;
    path.addRoundedRect(rect, 3, 3);  // 圆角半径3px
    painter->fillPath(path, QColor(240, 240, 240));  // 背景色

    // 绘制进度条
    QRect progressRect = rect.adjusted(0, 0, -rect.width() * (100 - percent) / 100, 0);
    QPainterPath progressPath;
    progressPath.addRoundedRect(progressRect, 3, 3);
    painter->fillPath(progressPath, QColor(100, 180, 255));  // 进度条颜色
}

