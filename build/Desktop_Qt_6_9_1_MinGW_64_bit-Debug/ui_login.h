/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginController
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *emailLineEdit;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QLabel *label_3;
    QComboBox *roleComboBox;
    QPushButton *loginButton;

    void setupUi(QWidget *LoginController)
    {
        if (LoginController->objectName().isEmpty())
            LoginController->setObjectName("LoginController");
        LoginController->resize(400, 300);
        verticalLayout = new QVBoxLayout(LoginController);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(LoginController);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        emailLineEdit = new QLineEdit(LoginController);
        emailLineEdit->setObjectName("emailLineEdit");

        verticalLayout->addWidget(emailLineEdit);

        label_2 = new QLabel(LoginController);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passwordLineEdit = new QLineEdit(LoginController);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordLineEdit);

        label_3 = new QLabel(LoginController);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        roleComboBox = new QComboBox(LoginController);
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->setObjectName("roleComboBox");

        verticalLayout->addWidget(roleComboBox);

        loginButton = new QPushButton(LoginController);
        loginButton->setObjectName("loginButton");

        verticalLayout->addWidget(loginButton);


        retranslateUi(LoginController);

        QMetaObject::connectSlotsByName(LoginController);
    } // setupUi

    void retranslateUi(QWidget *LoginController)
    {
        LoginController->setWindowTitle(QCoreApplication::translate("LoginController", "Bajaj Management System - Login", nullptr));
        LoginController->setStyleSheet(QCoreApplication::translate("LoginController", "background-color: #E6F0FA; /* Light blue background */\n"
"QLabel { font-size: 14px; color: #003087; font-weight: bold; }\n"
"QPushButton { background-color: #003087; color: white; border-radius: 5px; padding: 5px; }\n"
"QPushButton:hover { background-color: #0052cc; }\n"
"QLineEdit { border: 1px solid #003087; border-radius: 3px; padding: 3px; }\n"
"QComboBox { border: 1px solid #003087; border-radius: 3px; padding: 3px; background-color: white; }", nullptr));
        label->setText(QCoreApplication::translate("LoginController", "Email:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginController", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("LoginController", "Role:", nullptr));
        roleComboBox->setItemText(0, QCoreApplication::translate("LoginController", "Admin", nullptr));
        roleComboBox->setItemText(1, QCoreApplication::translate("LoginController", "Driver", nullptr));
        roleComboBox->setItemText(2, QCoreApplication::translate("LoginController", "Traffic Police", nullptr));

        loginButton->setText(QCoreApplication::translate("LoginController", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginController: public Ui_LoginController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
