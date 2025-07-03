#ifndef SERVERMANAGER_MAINWINDOW_H
#define SERVERMANAGER_MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QStyledItemDelegate>
#include <QApplication>
#include <QDebug>
#include "addwindow.h"
#include "boardwindow.h"
#include "imitatewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

    void setStaTableStyle();


private slots:

    void on_allButton_clicked();

    void on_dashButton_clicked();

    void on_addPushButton_clicked();

    void on_distriButton_clicked();

    void on_imitateButton_clicked();

private:
    Ui::mainwindow *ui;
    QTcpSocket *socket;
    QSqlDatabase db;
    QSqlTableModel *m, *m2;
};

class MyTableStyle : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    void drawPercent(QPainter *painter, const QStyleOptionViewItem &option, double percent) const;

    void drawLeftText(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void drawProgressBar(QPainter *painter, const QStyleOptionViewItem &option, double percent) const;

};


#endif //SERVERMANAGER_MAINWINDOW_H
