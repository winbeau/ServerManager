#include "addwindow.h"
#include "ui_addwindow.h"

addwindow::addwindow(QTcpSocket *s, QWidget *parent) :
        QMainWindow(parent), ui(new Ui::addwindow) {
    ui->setupUi(this);
    socket = s;
}

addwindow::~addwindow() {
    delete ui;
}

void addwindow::on_saveButton_clicked() {
    QString _id = ui->idLineEdit->text();
    QString _ip = ui->ipLineEdit->text();
    QString _port = ui->portLineEdit->text();

    QString sql = QString("INSERT INTO sers (id, ip, port) \
    VALUES ('%1', '%2', '%3');").arg(_id).arg(_ip).arg(_port.toInt());

    QSqlQuery query;
    if (query.exec("USE servers;" + sql)) {
        qDebug() << "data added successfully";
    } else {
        qDebug() << "data not added";
    }

    this->close();
}

void addwindow::on_clearButton_clicked() {
    ui->idLineEdit->clear();
    ui->ipLineEdit->clear();
    ui->portLineEdit->clear();
}


