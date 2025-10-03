/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QAction *actiondsA;
    QWidget *centralwidget;
    QGroupBox *menuBox;
    QLabel *logoLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *allButton;
    QPushButton *dashButton;
    QPushButton *distriButton;
    QPushButton *imitateButton;
    QWidget *pageWidget;
    QPushButton *addPushButton;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QGroupBox *storBox;
    QProgressBar *storProBar;
    QLabel *storLabel;
    QFrame *storFrame;
    QWidget *layoutWidget_3;
    QHBoxLayout *storLayout;
    QLabel *storgbLabel;
    QLabel *diskLabel;
    QLabel *vituLabel;
    QLabel *diskIcon;
    QGroupBox *machBox;
    QProgressBar *memoProBar;
    QLabel *machLabel;
    QFrame *machFrame;
    QWidget *layoutWidget_4;
    QHBoxLayout *machLayout;
    QLabel *memogbLabel;
    QLabel *styLabel;
    QLabel *procsLabel;
    QLabel *memoIcon;
    QGroupBox *grapBox;
    QGraphicsView *grapView;
    QGroupBox *clocBox;
    QFrame *clocFrame;
    QWidget *layoutWidget_5;
    QHBoxLayout *duriLayout;
    QLabel *hLabel;
    QLabel *mLabel;
    QLabel *sLabel;
    QGroupBox *procBox;
    QProgressBar *cpuProBar;
    QLabel *procLabel;
    QFrame *procFrame;
    QWidget *layoutWidget_6;
    QHBoxLayout *procLayout;
    QLabel *coreLabel;
    QLabel *ghzLabel;
    QLabel *bitLabel;
    QLabel *cpuIcon;
    QTableView *tableView;
    QWidget *allWidget;
    QTableView *allTableView;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
        mainwindow->resize(800, 600);
        mainwindow->setMinimumSize(QSize(800, 600));
        mainwindow->setMaximumSize(QSize(900, 600));
        actiondsA = new QAction(mainwindow);
        actiondsA->setObjectName(QString::fromUtf8("actiondsA"));
        centralwidget = new QWidget(mainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        menuBox = new QGroupBox(centralwidget);
        menuBox->setObjectName(QString::fromUtf8("menuBox"));
        menuBox->setGeometry(QRect(0, 0, 800, 70));
        logoLabel = new QLabel(menuBox);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setGeometry(QRect(50, 15, 50, 50));
        logoLabel->setMinimumSize(QSize(48, 50));
        logoLabel->setMaximumSize(QSize(50, 50));
        layoutWidget = new QWidget(menuBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(390, 10, 391, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        allButton = new QPushButton(layoutWidget);
        allButton->setObjectName(QString::fromUtf8("allButton"));
        allButton->setMinimumSize(QSize(0, 30));
        allButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(allButton);

        dashButton = new QPushButton(layoutWidget);
        dashButton->setObjectName(QString::fromUtf8("dashButton"));
        dashButton->setMinimumSize(QSize(0, 30));
        dashButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(dashButton);

        distriButton = new QPushButton(layoutWidget);
        distriButton->setObjectName(QString::fromUtf8("distriButton"));
        distriButton->setMinimumSize(QSize(0, 30));
        distriButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(distriButton);

        imitateButton = new QPushButton(menuBox);
        imitateButton->setObjectName(QString::fromUtf8("imitateButton"));
        imitateButton->setGeometry(QRect(210, 22, 111, 41));
        pageWidget = new QWidget(centralwidget);
        pageWidget->setObjectName(QString::fromUtf8("pageWidget"));
        pageWidget->setGeometry(QRect(0, 80, 791, 521));
        addPushButton = new QPushButton(pageWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));
        addPushButton->setGeometry(QRect(40, 10, 261, 41));
        layoutWidget_2 = new QWidget(pageWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(340, 0, 451, 511));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setSpacing(25);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        storBox = new QGroupBox(layoutWidget_2);
        storBox->setObjectName(QString::fromUtf8("storBox"));
        storProBar = new QProgressBar(storBox);
        storProBar->setObjectName(QString::fromUtf8("storProBar"));
        storProBar->setGeometry(QRect(100, 70, 90, 25));
        storProBar->setMinimumSize(QSize(90, 0));
        storProBar->setMaximumSize(QSize(90, 16777215));
        storProBar->setValue(58);
        storLabel = new QLabel(storBox);
        storLabel->setObjectName(QString::fromUtf8("storLabel"));
        storLabel->setGeometry(QRect(20, 5, 150, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        storLabel->setFont(font);
        storFrame = new QFrame(storBox);
        storFrame->setObjectName(QString::fromUtf8("storFrame"));
        storFrame->setGeometry(QRect(0, 113, 212, 40));
        storFrame->setFrameShape(QFrame::StyledPanel);
        storFrame->setFrameShadow(QFrame::Raised);
        layoutWidget_3 = new QWidget(storFrame);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 10, 161, 18));
        storLayout = new QHBoxLayout(layoutWidget_3);
        storLayout->setObjectName(QString::fromUtf8("storLayout"));
        storLayout->setContentsMargins(0, 0, 0, 0);
        storgbLabel = new QLabel(layoutWidget_3);
        storgbLabel->setObjectName(QString::fromUtf8("storgbLabel"));

        storLayout->addWidget(storgbLabel);

        diskLabel = new QLabel(layoutWidget_3);
        diskLabel->setObjectName(QString::fromUtf8("diskLabel"));

        storLayout->addWidget(diskLabel);

        vituLabel = new QLabel(layoutWidget_3);
        vituLabel->setObjectName(QString::fromUtf8("vituLabel"));

        storLayout->addWidget(vituLabel);

        diskIcon = new QLabel(storBox);
        diskIcon->setObjectName(QString::fromUtf8("diskIcon"));
        diskIcon->setGeometry(QRect(20, 55, 40, 40));
        diskIcon->setMinimumSize(QSize(40, 40));
        diskIcon->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(storBox, 1, 0, 1, 1);

        machBox = new QGroupBox(layoutWidget_2);
        machBox->setObjectName(QString::fromUtf8("machBox"));
        memoProBar = new QProgressBar(machBox);
        memoProBar->setObjectName(QString::fromUtf8("memoProBar"));
        memoProBar->setGeometry(QRect(100, 70, 90, 25));
        memoProBar->setMinimumSize(QSize(90, 0));
        memoProBar->setMaximumSize(QSize(90, 16777215));
        memoProBar->setValue(69);
        machLabel = new QLabel(machBox);
        machLabel->setObjectName(QString::fromUtf8("machLabel"));
        machLabel->setGeometry(QRect(20, 5, 150, 40));
        machLabel->setFont(font);
        machFrame = new QFrame(machBox);
        machFrame->setObjectName(QString::fromUtf8("machFrame"));
        machFrame->setGeometry(QRect(0, 113, 211, 40));
        machFrame->setFrameShape(QFrame::StyledPanel);
        machFrame->setFrameShadow(QFrame::Raised);
        layoutWidget_4 = new QWidget(machFrame);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(30, 10, 161, 18));
        machLayout = new QHBoxLayout(layoutWidget_4);
        machLayout->setObjectName(QString::fromUtf8("machLayout"));
        machLayout->setContentsMargins(0, 0, 0, 0);
        memogbLabel = new QLabel(layoutWidget_4);
        memogbLabel->setObjectName(QString::fromUtf8("memogbLabel"));

        machLayout->addWidget(memogbLabel);

        styLabel = new QLabel(layoutWidget_4);
        styLabel->setObjectName(QString::fromUtf8("styLabel"));

        machLayout->addWidget(styLabel);

        procsLabel = new QLabel(layoutWidget_4);
        procsLabel->setObjectName(QString::fromUtf8("procsLabel"));

        machLayout->addWidget(procsLabel);

        memoIcon = new QLabel(machBox);
        memoIcon->setObjectName(QString::fromUtf8("memoIcon"));
        memoIcon->setGeometry(QRect(20, 55, 40, 40));
        memoIcon->setMinimumSize(QSize(40, 40));
        memoIcon->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(machBox, 0, 1, 1, 1);

        grapBox = new QGroupBox(layoutWidget_2);
        grapBox->setObjectName(QString::fromUtf8("grapBox"));
        grapView = new QGraphicsView(grapBox);
        grapView->setObjectName(QString::fromUtf8("grapView"));
        grapView->setGeometry(QRect(10, 10, 431, 131));

        gridLayout->addWidget(grapBox, 2, 0, 1, 2);

        clocBox = new QGroupBox(layoutWidget_2);
        clocBox->setObjectName(QString::fromUtf8("clocBox"));
        clocFrame = new QFrame(clocBox);
        clocFrame->setObjectName(QString::fromUtf8("clocFrame"));
        clocFrame->setGeometry(QRect(20, 40, 181, 80));
        clocFrame->setFrameShape(QFrame::StyledPanel);
        clocFrame->setFrameShadow(QFrame::Raised);
        layoutWidget_5 = new QWidget(clocFrame);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(20, 20, 134, 42));
        duriLayout = new QHBoxLayout(layoutWidget_5);
        duriLayout->setObjectName(QString::fromUtf8("duriLayout"));
        duriLayout->setContentsMargins(0, 0, 0, 0);
        hLabel = new QLabel(layoutWidget_5);
        hLabel->setObjectName(QString::fromUtf8("hLabel"));
        hLabel->setMinimumSize(QSize(40, 40));
        hLabel->setMaximumSize(QSize(40, 40));

        duriLayout->addWidget(hLabel);

        mLabel = new QLabel(layoutWidget_5);
        mLabel->setObjectName(QString::fromUtf8("mLabel"));
        mLabel->setMinimumSize(QSize(40, 40));
        mLabel->setMaximumSize(QSize(40, 40));

        duriLayout->addWidget(mLabel);

        sLabel = new QLabel(layoutWidget_5);
        sLabel->setObjectName(QString::fromUtf8("sLabel"));
        sLabel->setMinimumSize(QSize(40, 40));
        sLabel->setMaximumSize(QSize(40, 40));

        duriLayout->addWidget(sLabel);


        gridLayout->addWidget(clocBox, 1, 1, 1, 1);

        procBox = new QGroupBox(layoutWidget_2);
        procBox->setObjectName(QString::fromUtf8("procBox"));
        cpuProBar = new QProgressBar(procBox);
        cpuProBar->setObjectName(QString::fromUtf8("cpuProBar"));
        cpuProBar->setGeometry(QRect(100, 70, 90, 25));
        cpuProBar->setMinimumSize(QSize(90, 0));
        cpuProBar->setMaximumSize(QSize(90, 16777215));
        cpuProBar->setValue(15);
        procLabel = new QLabel(procBox);
        procLabel->setObjectName(QString::fromUtf8("procLabel"));
        procLabel->setGeometry(QRect(20, 5, 150, 40));
        procLabel->setFont(font);
        procFrame = new QFrame(procBox);
        procFrame->setObjectName(QString::fromUtf8("procFrame"));
        procFrame->setGeometry(QRect(0, 113, 212, 40));
        procFrame->setFrameShape(QFrame::StyledPanel);
        procFrame->setFrameShadow(QFrame::Raised);
        layoutWidget_6 = new QWidget(procFrame);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(30, 10, 161, 18));
        procLayout = new QHBoxLayout(layoutWidget_6);
        procLayout->setObjectName(QString::fromUtf8("procLayout"));
        procLayout->setContentsMargins(0, 0, 0, 0);
        coreLabel = new QLabel(layoutWidget_6);
        coreLabel->setObjectName(QString::fromUtf8("coreLabel"));

        procLayout->addWidget(coreLabel);

        ghzLabel = new QLabel(layoutWidget_6);
        ghzLabel->setObjectName(QString::fromUtf8("ghzLabel"));

        procLayout->addWidget(ghzLabel);

        bitLabel = new QLabel(layoutWidget_6);
        bitLabel->setObjectName(QString::fromUtf8("bitLabel"));

        procLayout->addWidget(bitLabel);

        cpuIcon = new QLabel(procBox);
        cpuIcon->setObjectName(QString::fromUtf8("cpuIcon"));
        cpuIcon->setGeometry(QRect(20, 55, 40, 40));
        cpuIcon->setMinimumSize(QSize(40, 40));
        cpuIcon->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(procBox, 0, 0, 1, 1);

        tableView = new QTableView(pageWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 80, 300, 430));
        allWidget = new QWidget(centralwidget);
        allWidget->setObjectName(QString::fromUtf8("allWidget"));
        allWidget->setGeometry(QRect(0, 70, 791, 521));
        allTableView = new QTableView(allWidget);
        allTableView->setObjectName(QString::fromUtf8("allTableView"));
        allTableView->setGeometry(QRect(30, 20, 741, 471));
        mainwindow->setCentralWidget(centralwidget);
        menuBox->raise();
        allWidget->raise();
        pageWidget->raise();

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "mainwindow", nullptr));
        actiondsA->setText(QCoreApplication::translate("mainwindow", "dsA", nullptr));
        menuBox->setTitle(QString());
        logoLabel->setText(QCoreApplication::translate("mainwindow", "LOGO", nullptr));
        allButton->setText(QCoreApplication::translate("mainwindow", "\346\237\245\347\234\213\345\205\250\351\203\250", nullptr));
        dashButton->setText(QCoreApplication::translate("mainwindow", "\344\273\252\350\241\250\347\233\230", nullptr));
        distriButton->setText(QCoreApplication::translate("mainwindow", "\344\273\273\345\212\241\345\210\206\351\205\215", nullptr));
        imitateButton->setText(QCoreApplication::translate("mainwindow", "\345\257\274\345\205\245\346\250\241\346\213\237\346\225\260\346\215\256", nullptr));
        addPushButton->setText(QCoreApplication::translate("mainwindow", "\346\267\273\345\212\240\346\234\215\345\212\241\345\231\250", nullptr));
        storBox->setTitle(QString());
        storLabel->setText(QCoreApplication::translate("mainwindow", "Storage", nullptr));
        storgbLabel->setText(QCoreApplication::translate("mainwindow", "GiB", nullptr));
        diskLabel->setText(QCoreApplication::translate("mainwindow", "Disk", nullptr));
        vituLabel->setText(QCoreApplication::translate("mainwindow", "GiBSwap", nullptr));
        diskIcon->setText(QCoreApplication::translate("mainwindow", "TextLabel", nullptr));
        machBox->setTitle(QString());
        machLabel->setText(QCoreApplication::translate("mainwindow", "Machine", nullptr));
        memogbLabel->setText(QCoreApplication::translate("mainwindow", "Gib", nullptr));
        styLabel->setText(QCoreApplication::translate("mainwindow", "DDR3", nullptr));
        procsLabel->setText(QCoreApplication::translate("mainwindow", "Procs", nullptr));
        memoIcon->setText(QCoreApplication::translate("mainwindow", "TextLabel", nullptr));
        grapBox->setTitle(QString());
        clocBox->setTitle(QString());
        hLabel->setText(QCoreApplication::translate("mainwindow", "Hours", nullptr));
        mLabel->setText(QCoreApplication::translate("mainwindow", "Mins", nullptr));
        sLabel->setText(QCoreApplication::translate("mainwindow", "Seconds", nullptr));
        procBox->setTitle(QString());
        procLabel->setText(QCoreApplication::translate("mainwindow", "Processor", nullptr));
        coreLabel->setText(QCoreApplication::translate("mainwindow", "Cores", nullptr));
        ghzLabel->setText(QCoreApplication::translate("mainwindow", "GHz", nullptr));
        bitLabel->setText(QCoreApplication::translate("mainwindow", "64-bit", nullptr));
        cpuIcon->setText(QCoreApplication::translate("mainwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
