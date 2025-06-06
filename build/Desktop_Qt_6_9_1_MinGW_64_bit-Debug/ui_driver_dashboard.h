/********************************************************************************
** Form generated from reading UI file 'driver_dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVER_DASHBOARD_H
#define UI_DRIVER_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DriverController
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *routeLabel;
    QHBoxLayout *searchLayout;
    QLabel *searchLabel;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QHBoxLayout *sortLayout;
    QLabel *sortLabel;
    QComboBox *sortComboBox;
    QPushButton *sortButton;
    QTableWidget *issueTable;
    QLabel *reportLabel;
    QLineEdit *issueTypeLineEdit;
    QTextEdit *descriptionTextEdit;
    QPushButton *reportIssueButton;

    void setupUi(QWidget *DriverController)
    {
        if (DriverController->objectName().isEmpty())
            DriverController->setObjectName("DriverController");
        DriverController->resize(600, 400);
        verticalLayout = new QVBoxLayout(DriverController);
        verticalLayout->setObjectName("verticalLayout");
        routeLabel = new QLabel(DriverController);
        routeLabel->setObjectName("routeLabel");

        verticalLayout->addWidget(routeLabel);

        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        searchLabel = new QLabel(DriverController);
        searchLabel->setObjectName("searchLabel");

        searchLayout->addWidget(searchLabel);

        searchComboBox = new QComboBox(DriverController);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName("searchComboBox");

        searchLayout->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(DriverController);
        searchLineEdit->setObjectName("searchLineEdit");

        searchLayout->addWidget(searchLineEdit);

        searchButton = new QPushButton(DriverController);
        searchButton->setObjectName("searchButton");

        searchLayout->addWidget(searchButton);


        verticalLayout->addLayout(searchLayout);

        sortLayout = new QHBoxLayout();
        sortLayout->setObjectName("sortLayout");
        sortLabel = new QLabel(DriverController);
        sortLabel->setObjectName("sortLabel");

        sortLayout->addWidget(sortLabel);

        sortComboBox = new QComboBox(DriverController);
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->setObjectName("sortComboBox");

        sortLayout->addWidget(sortComboBox);

        sortButton = new QPushButton(DriverController);
        sortButton->setObjectName("sortButton");

        sortLayout->addWidget(sortButton);


        verticalLayout->addLayout(sortLayout);

        issueTable = new QTableWidget(DriverController);
        if (issueTable->columnCount() < 4)
            issueTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        issueTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        issueTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        issueTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        issueTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        issueTable->setObjectName("issueTable");
        issueTable->setColumnCount(4);

        verticalLayout->addWidget(issueTable);

        reportLabel = new QLabel(DriverController);
        reportLabel->setObjectName("reportLabel");

        verticalLayout->addWidget(reportLabel);

        issueTypeLineEdit = new QLineEdit(DriverController);
        issueTypeLineEdit->setObjectName("issueTypeLineEdit");

        verticalLayout->addWidget(issueTypeLineEdit);

        descriptionTextEdit = new QTextEdit(DriverController);
        descriptionTextEdit->setObjectName("descriptionTextEdit");

        verticalLayout->addWidget(descriptionTextEdit);

        reportIssueButton = new QPushButton(DriverController);
        reportIssueButton->setObjectName("reportIssueButton");

        verticalLayout->addWidget(reportIssueButton);


        retranslateUi(DriverController);

        QMetaObject::connectSlotsByName(DriverController);
    } // setupUi

    void retranslateUi(QWidget *DriverController)
    {
        DriverController->setWindowTitle(QCoreApplication::translate("DriverController", "Driver Dashboard", nullptr));
        DriverController->setStyleSheet(QCoreApplication::translate("DriverController", "background-color: #E6F0FA; /* Light blue background */\n"
"QLabel { font-size: 14px; color: #003087; font-weight: bold; }\n"
"QPushButton { background-color: #003087; color: white; border-radius: 5px; padding: 5px; }\n"
"QPushButton:hover { background-color: #0052cc; }\n"
"QLineEdit { border: 1px solid #003087; border-radius: 3px; padding: 3px; }\n"
"QComboBox { border: 1px solid #003087; border-radius: 3px; padding: 3px; background-color: white; }\n"
"QTableWidget { border: 1px solid #003087; background-color: white; }\n"
"QTableWidget::item { padding: 5px; }\n"
"QTableWidget QTableCornerButton::section { background-color: #003087; }\n"
"QTableWidget QHeaderView::section { background-color: #003087; color: white; padding: 5px; }", nullptr));
        routeLabel->setText(QCoreApplication::translate("DriverController", "Route: Not Assigned", nullptr));
        searchLabel->setText(QCoreApplication::translate("DriverController", "Search By:", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("DriverController", "Issue ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("DriverController", "Issue Type", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("DriverController", "Description", nullptr));

        searchLineEdit->setPlaceholderText(QCoreApplication::translate("DriverController", "Enter search term", nullptr));
        searchButton->setText(QCoreApplication::translate("DriverController", "Search", nullptr));
        sortLabel->setText(QCoreApplication::translate("DriverController", "Sort By:", nullptr));
        sortComboBox->setItemText(0, QCoreApplication::translate("DriverController", "Issue ID", nullptr));
        sortComboBox->setItemText(1, QCoreApplication::translate("DriverController", "Issue Type", nullptr));
        sortComboBox->setItemText(2, QCoreApplication::translate("DriverController", "Status", nullptr));

        sortButton->setText(QCoreApplication::translate("DriverController", "Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem = issueTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DriverController", "Issue ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = issueTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DriverController", "Issue Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = issueTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DriverController", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = issueTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DriverController", "Status", nullptr));
        reportLabel->setText(QCoreApplication::translate("DriverController", "Report New Issue", nullptr));
        issueTypeLineEdit->setPlaceholderText(QCoreApplication::translate("DriverController", "Issue Type", nullptr));
        descriptionTextEdit->setPlaceholderText(QCoreApplication::translate("DriverController", "Issue Description", nullptr));
        reportIssueButton->setText(QCoreApplication::translate("DriverController", "Report Issue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DriverController: public Ui_DriverController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVER_DASHBOARD_H
