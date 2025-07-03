#ifndef SERVERMANAGER_IMITATEWINDOW_H
#define SERVERMANAGER_IMITATEWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <QRandomGenerator>

#define LENGTH 10

QT_BEGIN_NAMESPACE
namespace Ui { class imitatewindow; }
QT_END_NAMESPACE

class imitatewindow : public QMainWindow {
Q_OBJECT

public:
    explicit imitatewindow(QWidget *parent = nullptr);

    ~imitatewindow() override;

    QString generateRandomID();

    QString generateRandomIP();

    int insertRandomServer();

    int insertRandomTask();

private slots:
    void on_clearButton_clicked();

    void on_clcButton_clicked();

    void on_importButton_clicked();

private:
    Ui::imitatewindow *ui;
    int serverNum;
    int taskNum;
};


#endif //SERVERMANAGER_IMITATEWINDOW_H
