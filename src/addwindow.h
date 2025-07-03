#ifndef SERVERMANAGER_ADDWINDOW_H
#define SERVERMANAGER_ADDWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QTcpSocket>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class addwindow; }
QT_END_NAMESPACE

class addwindow : public QMainWindow {
Q_OBJECT

public:
    explicit addwindow(QTcpSocket *s, QWidget *parent = nullptr);

    ~addwindow() override;

private slots:
    void on_saveButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::addwindow *ui;
    QTcpSocket *socket;
};


#endif //SERVERMANAGER_ADDWINDOW_H
