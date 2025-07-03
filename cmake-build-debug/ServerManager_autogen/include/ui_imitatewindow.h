/********************************************************************************
** Form generated from reading UI file 'imitatewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMITATEWINDOW_H
#define UI_IMITATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imitatewindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clcButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *importButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cntSerLabel;
    QLineEdit *cntSerEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *cntTasLabel;
    QLineEdit *cntTasEdit;

    void setupUi(QMainWindow *imitatewindow)
    {
        if (imitatewindow->objectName().isEmpty())
            imitatewindow->setObjectName("imitatewindow");
        imitatewindow->resize(600, 240);
        imitatewindow->setMinimumSize(QSize(600, 240));
        imitatewindow->setMaximumSize(QSize(600, 240));
        centralwidget = new QWidget(imitatewindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 160, 446, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        clearButton = new QPushButton(layoutWidget);
        clearButton->setObjectName("clearButton");
        clearButton->setMinimumSize(QSize(140, 40));
        clearButton->setMaximumSize(QSize(140, 40));
        QFont font;
        font.setPointSize(14);
        clearButton->setFont(font);

        horizontalLayout->addWidget(clearButton);

        horizontalSpacer_2 = new QSpacerItem(60, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        clcButton = new QPushButton(layoutWidget);
        clcButton->setObjectName("clcButton");
        clcButton->setMinimumSize(QSize(100, 40));
        clcButton->setMaximumSize(QSize(100, 40));
        clcButton->setFont(font);

        horizontalLayout->addWidget(clcButton);

        horizontalSpacer = new QSpacerItem(60, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        importButton = new QPushButton(layoutWidget);
        importButton->setObjectName("importButton");
        importButton->setMinimumSize(QSize(100, 40));
        importButton->setMaximumSize(QSize(100, 40));
        importButton->setFont(font);

        horizontalLayout->addWidget(importButton);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(70, 60, 466, 42));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        cntSerLabel = new QLabel(layoutWidget1);
        cntSerLabel->setObjectName("cntSerLabel");
        cntSerLabel->setMinimumSize(QSize(100, 40));
        cntSerLabel->setMaximumSize(QSize(100, 40));
        cntSerLabel->setFont(font);

        horizontalLayout_2->addWidget(cntSerLabel);

        cntSerEdit = new QLineEdit(layoutWidget1);
        cntSerEdit->setObjectName("cntSerEdit");
        cntSerEdit->setMinimumSize(QSize(100, 40));
        cntSerEdit->setMaximumSize(QSize(100, 40));

        horizontalLayout_2->addWidget(cntSerEdit);

        horizontalSpacer_3 = new QSpacerItem(60, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        cntTasLabel = new QLabel(layoutWidget1);
        cntTasLabel->setObjectName("cntTasLabel");
        cntTasLabel->setMinimumSize(QSize(80, 40));
        cntTasLabel->setMaximumSize(QSize(80, 40));
        cntTasLabel->setFont(font);

        horizontalLayout_2->addWidget(cntTasLabel);

        cntTasEdit = new QLineEdit(layoutWidget1);
        cntTasEdit->setObjectName("cntTasEdit");
        cntTasEdit->setMinimumSize(QSize(100, 40));
        cntTasEdit->setMaximumSize(QSize(100, 40));

        horizontalLayout_2->addWidget(cntTasEdit);

        imitatewindow->setCentralWidget(centralwidget);

        retranslateUi(imitatewindow);

        QMetaObject::connectSlotsByName(imitatewindow);
    } // setupUi

    void retranslateUi(QMainWindow *imitatewindow)
    {
        imitatewindow->setWindowTitle(QCoreApplication::translate("imitatewindow", "imitatewindow", nullptr));
        clearButton->setText(QCoreApplication::translate("imitatewindow", "\346\270\205\347\251\272\345\216\237\346\225\260\346\215\256", nullptr));
        clcButton->setText(QCoreApplication::translate("imitatewindow", "\346\270\205\347\251\272", nullptr));
        importButton->setText(QCoreApplication::translate("imitatewindow", "\345\257\274\345\205\245", nullptr));
        cntSerLabel->setText(QCoreApplication::translate("imitatewindow", "\346\234\215\345\212\241\345\231\250\346\225\260\351\207\217", nullptr));
        cntTasLabel->setText(QCoreApplication::translate("imitatewindow", "\344\273\273\345\212\241\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imitatewindow: public Ui_imitatewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMITATEWINDOW_H
