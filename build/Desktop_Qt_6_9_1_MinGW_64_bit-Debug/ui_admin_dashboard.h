/********************************************************************************
** Form generated from reading UI file 'admin_dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_DASHBOARD_H
#define UI_ADMIN_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminController
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *searchLayout;
    QLabel *searchLabel;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QHBoxLayout *sortLayout;
    QLabel *sortLabel;
    QComboBox *sortComboBox;
    QPushButton *sortButton;
    QTableWidget *driverTable;
    QLabel *addDriverLabel;
    QLineEdit *driverNameLineEdit;
    QLineEdit *driverEmailLineEdit;
    QLineEdit *licenseLineEdit;
    QPushButton *addDriverButton;

    void setupUi(QWidget *AdminController)
    {
        if (AdminController->objectName().isEmpty())
            AdminController->setObjectName("AdminController");
        AdminController->resize(926, 642);
        verticalLayout = new QVBoxLayout(AdminController);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AdminController);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        searchLabel = new QLabel(AdminController);
        searchLabel->setObjectName("searchLabel");

        searchLayout->addWidget(searchLabel);

        searchComboBox = new QComboBox(AdminController);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName("searchComboBox");

        searchLayout->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(AdminController);
        searchLineEdit->setObjectName("searchLineEdit");

        searchLayout->addWidget(searchLineEdit);

        searchButton = new QPushButton(AdminController);
        searchButton->setObjectName("searchButton");

        searchLayout->addWidget(searchButton);


        verticalLayout->addLayout(searchLayout);

        sortLayout = new QHBoxLayout();
        sortLayout->setObjectName("sortLayout");
        sortLabel = new QLabel(AdminController);
        sortLabel->setObjectName("sortLabel");

        sortLayout->addWidget(sortLabel);

        sortComboBox = new QComboBox(AdminController);
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->setObjectName("sortComboBox");

        sortLayout->addWidget(sortComboBox);

        sortButton = new QPushButton(AdminController);
        sortButton->setObjectName("sortButton");

        sortLayout->addWidget(sortButton);


        verticalLayout->addLayout(sortLayout);

        driverTable = new QTableWidget(AdminController);
        if (driverTable->columnCount() < 4)
            driverTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        driverTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        driverTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        driverTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        driverTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        driverTable->setObjectName("driverTable");
        driverTable->setColumnCount(4);

        verticalLayout->addWidget(driverTable);

        addDriverLabel = new QLabel(AdminController);
        addDriverLabel->setObjectName("addDriverLabel");

        verticalLayout->addWidget(addDriverLabel);

        driverNameLineEdit = new QLineEdit(AdminController);
        driverNameLineEdit->setObjectName("driverNameLineEdit");

        verticalLayout->addWidget(driverNameLineEdit);

        driverEmailLineEdit = new QLineEdit(AdminController);
        driverEmailLineEdit->setObjectName("driverEmailLineEdit");

        verticalLayout->addWidget(driverEmailLineEdit);

        licenseLineEdit = new QLineEdit(AdminController);
        licenseLineEdit->setObjectName("licenseLineEdit");

        verticalLayout->addWidget(licenseLineEdit);

        addDriverButton = new QPushButton(AdminController);
        addDriverButton->setObjectName("addDriverButton");

        verticalLayout->addWidget(addDriverButton);


        retranslateUi(AdminController);

        QMetaObject::connectSlotsByName(AdminController);
    } // setupUi

    void retranslateUi(QWidget *AdminController)
    {
        AdminController->setWindowTitle(QCoreApplication::translate("AdminController", "Admin Dashboard - Bajaj Management System", nullptr));
        AdminController->setStyleSheet(QCoreApplication::translate("AdminController", "background-color: #E6F0FA; /* Light blue background */\n"
"QLabel { font-size: 14px; color: #003087; font-weight: bold; }\n"
"QPushButton { background-color: #003087; color: white; border-radius: 5px; padding: 5px; }\n"
"QPushButton:hover { background-color: #0052cc; }\n"
"QLineEdit { border: 1px solid #003087; border-radius: 3px; padding: 3px; }\n"
"QComboBox { border: 1px solid #003087; border-radius: 3px; padding: 3px; background-color: white; }\n"
"QTableWidget { border: 1px solid #003087; background-color: white; }\n"
"QTableWidget::item { padding: 5px; }\n"
"QTableWidget QTableCornerButton::section { background-color: #003087; }\n"
"QTableWidget QHeaderView::section { background-color: #003087; color: white; padding: 5px; }", nullptr));
        label->setText(QCoreApplication::translate("AdminController", "Admin Dashboard", nullptr));
        searchLabel->setText(QCoreApplication::translate("AdminController", "Search By:", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("AdminController", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("AdminController", "Name", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("AdminController", "Email", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("AdminController", "License Number", nullptr));

        searchLineEdit->setPlaceholderText(QCoreApplication::translate("AdminController", "Enter search term", nullptr));
        searchButton->setText(QCoreApplication::translate("AdminController", "Search", nullptr));
        sortLabel->setText(QCoreApplication::translate("AdminController", "Sort By:", nullptr));
        sortComboBox->setItemText(0, QCoreApplication::translate("AdminController", "ID", nullptr));
        sortComboBox->setItemText(1, QCoreApplication::translate("AdminController", "Name", nullptr));
        sortComboBox->setItemText(2, QCoreApplication::translate("AdminController", "Email", nullptr));
        sortComboBox->setItemText(3, QCoreApplication::translate("AdminController", "License Number", nullptr));

        sortButton->setText(QCoreApplication::translate("AdminController", "Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem = driverTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminController", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = driverTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminController", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = driverTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminController", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = driverTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdminController", "License Number", nullptr));
        addDriverLabel->setText(QCoreApplication::translate("AdminController", "Add New Driver", nullptr));
        driverNameLineEdit->setPlaceholderText(QCoreApplication::translate("AdminController", "Driver Full Name", nullptr));
        driverEmailLineEdit->setPlaceholderText(QCoreApplication::translate("AdminController", "Driver Email", nullptr));
        licenseLineEdit->setPlaceholderText(QCoreApplication::translate("AdminController", "License Number", nullptr));
        addDriverButton->setText(QCoreApplication::translate("AdminController", "Add Driver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminController: public Ui_AdminController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_DASHBOARD_H
