/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addwindow
{
public:
    QWidget *centralwidget;
    QGroupBox *buttBox;
    QPushButton *saveButton;
    QPushButton *clearButton;
    QGroupBox *inputBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QLabel *ipLabel;
    QLineEdit *ipLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;

    void setupUi(QMainWindow *addwindow)
    {
        if (addwindow->objectName().isEmpty())
            addwindow->setObjectName("addwindow");
        addwindow->resize(450, 520);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(45);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addwindow->sizePolicy().hasHeightForWidth());
        addwindow->setSizePolicy(sizePolicy);
        addwindow->setMinimumSize(QSize(450, 520));
        addwindow->setMaximumSize(QSize(450, 520));
        centralwidget = new QWidget(addwindow);
        centralwidget->setObjectName("centralwidget");
        buttBox = new QGroupBox(centralwidget);
        buttBox->setObjectName("buttBox");
        buttBox->setGeometry(QRect(5, 360, 440, 146));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttBox->sizePolicy().hasHeightForWidth());
        buttBox->setSizePolicy(sizePolicy1);
        buttBox->setMinimumSize(QSize(440, 0));
        buttBox->setMaximumSize(QSize(440, 16777215));
        saveButton = new QPushButton(buttBox);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(270, 50, 75, 40));
        QFont font;
        font.setPointSize(14);
        saveButton->setFont(font);
        clearButton = new QPushButton(buttBox);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(100, 50, 75, 40));
        clearButton->setFont(font);
        inputBox = new QGroupBox(centralwidget);
        inputBox->setObjectName("inputBox");
        inputBox->setGeometry(QRect(5, 5, 440, 350));
        inputBox->setMinimumSize(QSize(440, 350));
        inputBox->setMaximumSize(QSize(440, 350));
        layoutWidget = new QWidget(inputBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 70, 291, 142));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(30);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        idLabel = new QLabel(layoutWidget);
        idLabel->setObjectName("idLabel");
        idLabel->setMinimumSize(QSize(0, 40));
        idLabel->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        idLabel->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, idLabel);

        idLineEdit = new QLineEdit(layoutWidget);
        idLineEdit->setObjectName("idLineEdit");
        idLineEdit->setMinimumSize(QSize(0, 40));
        idLineEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(0, QFormLayout::FieldRole, idLineEdit);

        ipLabel = new QLabel(layoutWidget);
        ipLabel->setObjectName("ipLabel");
        ipLabel->setMinimumSize(QSize(0, 40));
        ipLabel->setMaximumSize(QSize(16777215, 40));
        ipLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, ipLabel);

        ipLineEdit = new QLineEdit(layoutWidget);
        ipLineEdit->setObjectName("ipLineEdit");
        ipLineEdit->setMinimumSize(QSize(0, 40));
        ipLineEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(1, QFormLayout::FieldRole, ipLineEdit);

        portLabel = new QLabel(layoutWidget);
        portLabel->setObjectName("portLabel");
        portLabel->setMinimumSize(QSize(0, 40));
        portLabel->setMaximumSize(QSize(16777215, 40));
        portLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, portLabel);

        portLineEdit = new QLineEdit(layoutWidget);
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setMinimumSize(QSize(0, 40));
        portLineEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(2, QFormLayout::FieldRole, portLineEdit);

        addwindow->setCentralWidget(centralwidget);

        retranslateUi(addwindow);

        QMetaObject::connectSlotsByName(addwindow);
    } // setupUi

    void retranslateUi(QMainWindow *addwindow)
    {
        addwindow->setWindowTitle(QCoreApplication::translate("addwindow", "addwindow", nullptr));
        buttBox->setTitle(QString());
        saveButton->setText(QCoreApplication::translate("addwindow", "\344\277\235\345\255\230", nullptr));
        clearButton->setText(QCoreApplication::translate("addwindow", "\346\270\205\347\251\272", nullptr));
        inputBox->setTitle(QString());
        idLabel->setText(QCoreApplication::translate("addwindow", "ID", nullptr));
        ipLabel->setText(QCoreApplication::translate("addwindow", "\345\234\260\345\235\200", nullptr));
        portLabel->setText(QCoreApplication::translate("addwindow", "\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addwindow: public Ui_addwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
