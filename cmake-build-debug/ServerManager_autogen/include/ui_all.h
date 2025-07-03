/********************************************************************************
** Form generated from reading UI file 'all.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALL_H
#define UI_ALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_all
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *all)
    {
        if (all->objectName().isEmpty())
            all->setObjectName("all");
        all->resize(400, 300);
        verticalLayout = new QVBoxLayout(all);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(all);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(all);

        QMetaObject::connectSlotsByName(all);
    } // setupUi

    void retranslateUi(QWidget *all)
    {
        all->setWindowTitle(QCoreApplication::translate("all", "all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class all: public Ui_all {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALL_H
