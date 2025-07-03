/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *inputBox;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *ipLabel;
    QLineEdit *ipLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QGroupBox *buttBox;
    QPushButton *saveButton;
    QPushButton *clearButton;

    void setupUi(QWidget *add)
    {
        if (add->objectName().isEmpty())
            add->setObjectName("add");
        add->resize(450, 520);
        add->setMinimumSize(QSize(450, 520));
        add->setMaximumSize(QSize(450, 520));
        verticalLayout = new QVBoxLayout(add);
        verticalLayout->setObjectName("verticalLayout");
        inputBox = new QGroupBox(add);
        inputBox->setObjectName("inputBox");
        inputBox->setMinimumSize(QSize(440, 350));
        inputBox->setMaximumSize(QSize(440, 350));
        widget = new QWidget(inputBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 60, 301, 162));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setMinimumSize(QSize(0, 40));
        nameLabel->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        nameLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(widget);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setMinimumSize(QSize(0, 40));
        nameLineEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        ipLabel = new QLabel(widget);
        ipLabel->setObjectName("ipLabel");
        ipLabel->setMinimumSize(QSize(0, 40));
        ipLabel->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(14);
        ipLabel->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, ipLabel);

        ipLineEdit = new QLineEdit(widget);
        ipLineEdit->setObjectName("ipLineEdit");
        ipLineEdit->setMinimumSize(QSize(0, 40));
        ipLineEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(1, QFormLayout::FieldRole, ipLineEdit);

        portLabel = new QLabel(widget);
        portLabel->setObjectName("portLabel");
        portLabel->setMinimumSize(QSize(0, 40));
        portLabel->setMaximumSize(QSize(16777215, 40));
        portLabel->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, portLabel);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName("portLineEdit");
        portLineEdit->setMinimumSize(QSize(0, 40));
        portLineEdit->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(2, QFormLayout::FieldRole, portLineEdit);


        verticalLayout->addWidget(inputBox);

        buttBox = new QGroupBox(add);
        buttBox->setObjectName("buttBox");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttBox->sizePolicy().hasHeightForWidth());
        buttBox->setSizePolicy(sizePolicy);
        buttBox->setMinimumSize(QSize(440, 0));
        buttBox->setMaximumSize(QSize(440, 16777215));
        saveButton = new QPushButton(buttBox);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(270, 50, 75, 40));
        saveButton->setFont(font1);
        clearButton = new QPushButton(buttBox);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(100, 50, 75, 40));
        clearButton->setFont(font1);

        verticalLayout->addWidget(buttBox);


        retranslateUi(add);

        QMetaObject::connectSlotsByName(add);
    } // setupUi

    void retranslateUi(QWidget *add)
    {
        add->setWindowTitle(QCoreApplication::translate("add", "add", nullptr));
        inputBox->setTitle(QString());
        nameLabel->setText(QCoreApplication::translate("add", "\345\220\215\347\247\260", nullptr));
        ipLabel->setText(QCoreApplication::translate("add", "\345\234\260\345\235\200", nullptr));
        portLabel->setText(QCoreApplication::translate("add", "\347\253\257\345\217\243", nullptr));
        buttBox->setTitle(QString());
        saveButton->setText(QCoreApplication::translate("add", "\344\277\235\345\255\230", nullptr));
        clearButton->setText(QCoreApplication::translate("add", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
