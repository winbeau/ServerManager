#include "imitatewindow.h"
#include "ui_imitatewindow.h"


imitatewindow::imitatewindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::imitatewindow) {
    ui->setupUi(this);

}

imitatewindow::~imitatewindow() {
    delete ui;
}

void imitatewindow::on_clcButton_clicked() {
    ui->cntSerEdit->clear();
    ui->cntTasEdit->clear();
}

void imitatewindow::on_importButton_clicked() {
    QString cntSer = ui->cntSerEdit->text();
    QString cntTas = ui->cntTasEdit->text();
    if (cntSer.isEmpty() || cntTas.isEmpty()) {
        qDebug() << "number is empty";
        return;
    }

    serverNum = cntSer.toInt();
    taskNum = cntTas.toInt();

    int flagSer = 0;
    for (int i = 0; i < serverNum; i++) {
        flagSer += insertRandomServer();
    }

    qDebug() << QString::number(flagSer) + " servers added to Table:sta";
    if (flagSer != serverNum) {
        qDebug() << QString::number(serverNum - flagSer) + " servers insert failed";
    }

    int flagTas = 0;
    for (int i = 0; i < taskNum; i++) {
        flagTas += insertRandomTask();
    }

    qDebug() << QString::number(flagTas) + " tasks added to Table:task";
    if (flagTas != taskNum) {
        qDebug() << QString::number(taskNum - flagTas) + " tasks insert failed";
    }

    this->close();
}

QString imitatewindow::generateRandomID() {
    const QString charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    QString id;
    for (int i = 0; i < LENGTH; i++) {
        id.append(charset.at(QRandomGenerator::global()->bounded(charset.length())));
    }
    return id;
}

QString imitatewindow::generateRandomIP() {
    return QString("%1.%2.%3.%4")
            .arg(QRandomGenerator::global()->bounded(0, 256))
            .arg(QRandomGenerator::global()->bounded(0, 256))
            .arg(QRandomGenerator::global()->bounded(0, 256))
            .arg(QRandomGenerator::global()->bounded(0, 256));
}

int imitatewindow::insertRandomServer() {
    QSqlQuery query;
    query.prepare("INSERT INTO sta (id, ip, port, cpu, gpu, disk, bandwidth, "
                  "free_cpu, free_gpu, free_disk, free_bandwidth, "
                  "status, power) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    QString id = generateRandomID();
    QString ip = generateRandomIP();
    int port = QRandomGenerator::global()->bounded(0, 49152); // 0~49151
    int cpu = 1024 * QRandomGenerator::global()->bounded(1, 65); // 1~64
    int gpu = 1024 * QRandomGenerator::global()->bounded(1, 97); // 1~96
    int disk = QRandomGenerator::global()->bounded(100, 10000); // 100~9999
    int bandwidth = QRandomGenerator::global()->bounded(20, 1025); // 20~1024

    int power = QRandomGenerator::global()->bounded(50, 700);

    query.addBindValue(id);
    query.addBindValue(ip);
    query.addBindValue(port);
    query.addBindValue(cpu);
    query.addBindValue(gpu);
    query.addBindValue(disk);
    query.addBindValue(bandwidth);

    query.addBindValue(cpu);
    query.addBindValue(gpu);
    query.addBindValue(disk);
    query.addBindValue(bandwidth);

    query.addBindValue(0);
    query.addBindValue(power);

    if (!query.exec()) return 0;
    return 1;
}

int imitatewindow::insertRandomTask() {
    QSqlQuery query;
    query.prepare("INSERT INTO task (id, cpu, gpu, disk, bandwidth, "
                  "start, during, status) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    QString id = generateRandomID();
    int cpu = QRandomGenerator::global()->bounded(1, 1024 * 1); //
    int gpu = QRandomGenerator::global()->bounded(1, 1024 * 2); //
    int disk = QRandomGenerator::global()->bounded(0, 100);
    int bandwidth = QRandomGenerator::global()->bounded(1, 512); // 20~1024

    long long start = QRandomGenerator::global()->bounded(0, (int) (100 * 1e3)); // 0 ~ 100 s
    int during = QRandomGenerator::global()->bounded(500, (int) (10 * 1e3)); // 0.5 ~ 10 s

    query.addBindValue(id);
    query.addBindValue(cpu);
    query.addBindValue(gpu);
    query.addBindValue(disk);
    query.addBindValue(bandwidth);

    query.addBindValue(start);
    query.addBindValue(during);
    query.addBindValue(0);

    if (!query.exec()) return 0;
    return 1;
}

void imitatewindow::on_clearButton_clicked() {
    QSqlQuery query;
    if (query.exec("DELETE FROM sers")) {
        qDebug() << "sers table cleared, affected rows:" << query.numRowsAffected();
    } else
        qDebug() << "Clear sers failed:" << query.lastError().text();

    if (query.exec("DELETE FROM sta")) {
        qDebug() << "sta table cleared, affected rows:" << query.numRowsAffected();
    } else
        qDebug() << "Clear sta failed:" << query.lastError().text();

    if (query.exec("DELETE FROM task")) {
        qDebug() << "task table cleared, affected rows:" << query.numRowsAffected();
    } else
        qDebug() << "Clear task failed:" << query.lastError().text();
}



