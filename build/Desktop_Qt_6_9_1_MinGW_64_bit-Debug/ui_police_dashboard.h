/********************************************************************************
** Form generated from reading UI file 'police_dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLICE_DASHBOARD_H
#define UI_POLICE_DASHBOARD_H

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

class Ui_PoliceController
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *searchLayout;
    QLabel *searchLabel;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QHBoxLayout *sortLayout;
    QLabel *sortLabel;
    QComboBox *sortComboBox;
    QPushButton *sortButton;
    QTableWidget *violationTable;
    QLabel *submitLabel;
    QLineEdit *driverIdLineEdit;
    QLineEdit *bajajIdLineEdit;
    QLineEdit *violationTypeLineEdit;
    QTextEdit *descriptionTextEdit;
    QPushButton *submitViolationButton;

    void setupUi(QWidget *PoliceController)
    {
        if (PoliceController->objectName().isEmpty())
            PoliceController->setObjectName("PoliceController");
        PoliceController->resize(634, 463);
        verticalLayout = new QVBoxLayout(PoliceController);
        verticalLayout->setObjectName("verticalLayout");
        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        searchLabel = new QLabel(PoliceController);
        searchLabel->setObjectName("searchLabel");

        searchLayout->addWidget(searchLabel);

        searchComboBox = new QComboBox(PoliceController);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName("searchComboBox");

        searchLayout->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(PoliceController);
        searchLineEdit->setObjectName("searchLineEdit");

        searchLayout->addWidget(searchLineEdit);

        searchButton = new QPushButton(PoliceController);
        searchButton->setObjectName("searchButton");

        searchLayout->addWidget(searchButton);


        verticalLayout->addLayout(searchLayout);

        sortLayout = new QHBoxLayout();
        sortLayout->setObjectName("sortLayout");
        sortLabel = new QLabel(PoliceController);
        sortLabel->setObjectName("sortLabel");

        sortLayout->addWidget(sortLabel);

        sortComboBox = new QComboBox(PoliceController);
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->setObjectName("sortComboBox");

        sortLayout->addWidget(sortComboBox);

        sortButton = new QPushButton(PoliceController);
        sortButton->setObjectName("sortButton");

        sortLayout->addWidget(sortButton);


        verticalLayout->addLayout(sortLayout);

        violationTable = new QTableWidget(PoliceController);
        if (violationTable->columnCount() < 5)
            violationTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        violationTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        violationTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        violationTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        violationTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        violationTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        violationTable->setObjectName("violationTable");
        violationTable->setColumnCount(5);

        verticalLayout->addWidget(violationTable);

        submitLabel = new QLabel(PoliceController);
        submitLabel->setObjectName("submitLabel");

        verticalLayout->addWidget(submitLabel);

        driverIdLineEdit = new QLineEdit(PoliceController);
        driverIdLineEdit->setObjectName("driverIdLineEdit");

        verticalLayout->addWidget(driverIdLineEdit);

        bajajIdLineEdit = new QLineEdit(PoliceController);
        bajajIdLineEdit->setObjectName("bajajIdLineEdit");

        verticalLayout->addWidget(bajajIdLineEdit);

        violationTypeLineEdit = new QLineEdit(PoliceController);
        violationTypeLineEdit->setObjectName("violationTypeLineEdit");

        verticalLayout->addWidget(violationTypeLineEdit);

        descriptionTextEdit = new QTextEdit(PoliceController);
        descriptionTextEdit->setObjectName("descriptionTextEdit");

        verticalLayout->addWidget(descriptionTextEdit);

        submitViolationButton = new QPushButton(PoliceController);
        submitViolationButton->setObjectName("submitViolationButton");

        verticalLayout->addWidget(submitViolationButton);


        retranslateUi(PoliceController);

        QMetaObject::connectSlotsByName(PoliceController);
    } // setupUi

    void retranslateUi(QWidget *PoliceController)
    {
        PoliceController->setWindowTitle(QCoreApplication::translate("PoliceController", "Traffic Police Dashboard", nullptr));
        PoliceController->setStyleSheet(QCoreApplication::translate("PoliceController", "background-color: #E6F0FA; /* Light blue background */\n"
"QLabel { font-size: 14px; color: #003087; font-weight: bold; }\n"
"QPushButton { background-color: #003087; color: white; border-radius: 5px; padding: 5px; }\n"
"QPushButton:hover { background-color: #0052cc; }\n"
"QLineEdit { border: 1px solid #003087; border-radius: 3px; padding: 3px; }\n"
"QComboBox { border: 1px solid #003087; border-radius: 3px; padding: 3px; background-color: white; }\n"
"QTableWidget { border: 1px solid #003087; background-color: white; }\n"
"QTableWidget::item { padding: 5px; }\n"
"QTableWidget QTableCornerButton::section { background-color: #003087; }\n"
"QTableWidget QHeaderView::section { background-color: #003087; color: white; padding: 5px; }", nullptr));
        searchLabel->setText(QCoreApplication::translate("PoliceController", "Search By:", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("PoliceController", "Report ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("PoliceController", "Driver ID", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("PoliceController", "Bajaj ID", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("PoliceController", "Violation Type", nullptr));

        searchLineEdit->setPlaceholderText(QCoreApplication::translate("PoliceController", "Enter search term", nullptr));
        searchButton->setText(QCoreApplication::translate("PoliceController", "Search", nullptr));
        sortLabel->setText(QCoreApplication::translate("PoliceController", "Sort By:", nullptr));
        sortComboBox->setItemText(0, QCoreApplication::translate("PoliceController", "Report ID", nullptr));
        sortComboBox->setItemText(1, QCoreApplication::translate("PoliceController", "Driver ID", nullptr));
        sortComboBox->setItemText(2, QCoreApplication::translate("PoliceController", "Bajaj ID", nullptr));
        sortComboBox->setItemText(3, QCoreApplication::translate("PoliceController", "Violation Type", nullptr));

        sortButton->setText(QCoreApplication::translate("PoliceController", "Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem = violationTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PoliceController", "Report ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = violationTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PoliceController", "Driver ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = violationTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PoliceController", "Bajaj ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = violationTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PoliceController", "Violation Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = violationTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("PoliceController", "Description", nullptr));
        submitLabel->setText(QCoreApplication::translate("PoliceController", "Submit New Violation", nullptr));
        driverIdLineEdit->setPlaceholderText(QCoreApplication::translate("PoliceController", "Driver ID", nullptr));
        bajajIdLineEdit->setPlaceholderText(QCoreApplication::translate("PoliceController", "Bajaj ID", nullptr));
        violationTypeLineEdit->setPlaceholderText(QCoreApplication::translate("PoliceController", "Violation Type", nullptr));
        descriptionTextEdit->setPlaceholderText(QCoreApplication::translate("PoliceController", "Violation Description", nullptr));
        submitViolationButton->setText(QCoreApplication::translate("PoliceController", "Submit Violation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PoliceController: public Ui_PoliceController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLICE_DASHBOARD_H
