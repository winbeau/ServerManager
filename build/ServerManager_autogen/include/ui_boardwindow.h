/********************************************************************************
** Form generated from reading UI file 'boardwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARDWINDOW_H
#define UI_BOARDWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boardwindow
{
public:
    QWidget *centralwidget;
    QWidget *rightWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QChartView *taskView;
    QHBoxLayout *horizontalLayout_2;
    QChartView *memoView;
    QChartView *gpuView;
    QWidget *statWidget;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *memoLabel;
    QLabel *gpuLabel;
    QLabel *finishTaskLabel;
    QLabel *todoTaskLabel;
    QLabel *failTaskLabel;
    QTableView *leftTable;

    void setupUi(QMainWindow *boardwindow)
    {
        if (boardwindow->objectName().isEmpty())
            boardwindow->setObjectName(QString::fromUtf8("boardwindow"));
        boardwindow->resize(1200, 800);
        boardwindow->setMinimumSize(QSize(1200, 800));
        boardwindow->setMaximumSize(QSize(1200, 800));
        centralwidget = new QWidget(boardwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(1200, 800));
        centralwidget->setMaximumSize(QSize(1200, 800));
        rightWidget = new QWidget(centralwidget);
        rightWidget->setObjectName(QString::fromUtf8("rightWidget"));
        rightWidget->setEnabled(true);
        rightWidget->setGeometry(QRect(610, 10, 580, 660));
        rightWidget->setMinimumSize(QSize(580, 660));
        rightWidget->setMaximumSize(QSize(580, 650));
        widget = new QWidget(rightWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 514, 644));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        taskView = new QChartView(widget);
        taskView->setObjectName(QString::fromUtf8("taskView"));
        taskView->setMinimumSize(QSize(510, 300));
        taskView->setMaximumSize(QSize(510, 300));

        verticalLayout->addWidget(taskView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        memoView = new QChartView(widget);
        memoView->setObjectName(QString::fromUtf8("memoView"));
        memoView->setMinimumSize(QSize(250, 330));
        memoView->setMaximumSize(QSize(250, 330));

        horizontalLayout_2->addWidget(memoView);

        gpuView = new QChartView(widget);
        gpuView->setObjectName(QString::fromUtf8("gpuView"));
        gpuView->setMinimumSize(QSize(250, 330));
        gpuView->setMaximumSize(QSize(250, 330));

        horizontalLayout_2->addWidget(gpuView);


        verticalLayout->addLayout(horizontalLayout_2);

        statWidget = new QWidget(centralwidget);
        statWidget->setObjectName(QString::fromUtf8("statWidget"));
        statWidget->setGeometry(QRect(10, 690, 1180, 100));
        statWidget->setMinimumSize(QSize(1180, 100));
        statWidget->setMaximumSize(QSize(1180, 100));
        widget1 = new QWidget(statWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 30, 1201, 52));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        memoLabel = new QLabel(widget1);
        memoLabel->setObjectName(QString::fromUtf8("memoLabel"));
        memoLabel->setMinimumSize(QSize(235, 50));
        memoLabel->setMaximumSize(QSize(235, 50));
        QFont font;
        font.setKerning(false);
        memoLabel->setFont(font);

        horizontalLayout->addWidget(memoLabel);

        gpuLabel = new QLabel(widget1);
        gpuLabel->setObjectName(QString::fromUtf8("gpuLabel"));
        gpuLabel->setMinimumSize(QSize(235, 50));
        gpuLabel->setMaximumSize(QSize(235, 50));

        horizontalLayout->addWidget(gpuLabel);

        finishTaskLabel = new QLabel(widget1);
        finishTaskLabel->setObjectName(QString::fromUtf8("finishTaskLabel"));
        finishTaskLabel->setMinimumSize(QSize(235, 50));
        finishTaskLabel->setMaximumSize(QSize(235, 50));

        horizontalLayout->addWidget(finishTaskLabel);

        todoTaskLabel = new QLabel(widget1);
        todoTaskLabel->setObjectName(QString::fromUtf8("todoTaskLabel"));
        todoTaskLabel->setMinimumSize(QSize(235, 50));
        todoTaskLabel->setMaximumSize(QSize(235, 50));

        horizontalLayout->addWidget(todoTaskLabel);

        failTaskLabel = new QLabel(widget1);
        failTaskLabel->setObjectName(QString::fromUtf8("failTaskLabel"));
        failTaskLabel->setMinimumSize(QSize(235, 50));
        failTaskLabel->setMaximumSize(QSize(235, 50));

        horizontalLayout->addWidget(failTaskLabel);

        leftTable = new QTableView(centralwidget);
        leftTable->setObjectName(QString::fromUtf8("leftTable"));
        leftTable->setGeometry(QRect(20, 20, 580, 645));
        boardwindow->setCentralWidget(centralwidget);

        retranslateUi(boardwindow);

        QMetaObject::connectSlotsByName(boardwindow);
    } // setupUi

    void retranslateUi(QMainWindow *boardwindow)
    {
        boardwindow->setWindowTitle(QCoreApplication::translate("boardwindow", "boardwindow", nullptr));
        memoLabel->setText(QCoreApplication::translate("boardwindow", "\345\206\205\345\255\230", nullptr));
        gpuLabel->setText(QCoreApplication::translate("boardwindow", "\346\230\276\345\255\230", nullptr));
        finishTaskLabel->setText(QCoreApplication::translate("boardwindow", "\345\256\214\346\210\220\344\273\273\345\212\241\346\225\260", nullptr));
        todoTaskLabel->setText(QCoreApplication::translate("boardwindow", "\345\276\205\345\256\214\346\210\220\344\273\273\345\212\241", nullptr));
        failTaskLabel->setText(QCoreApplication::translate("boardwindow", "\345\244\261\350\264\245\344\273\273\345\212\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boardwindow: public Ui_boardwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDWINDOW_H
