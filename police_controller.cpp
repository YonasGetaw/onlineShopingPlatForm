#include "police_controller.h"
#include "ui_police_dashboard.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include "helpers.h"

struct ViolationData
{
    int reportId;
    int driverId;
    int bajajId;
    QString violationType;
    QString description;
};

PoliceController::PoliceController(int policeId, QWidget *parent) : QWidget(parent),
                                                                    ui(new Ui::PoliceController),
                                                                    policeId(policeId)
{
    ui->setupUi(this);

    db = Database::getInstance().getConnection("police_conn");
    if (!db.isOpen())
    {
        close();
        return;
    }

    loadViolations();

    connect(ui->submitViolationButton, &QPushButton::clicked, this, &PoliceController::on_submitViolationButton_clicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &PoliceController::on_searchButton_clicked);
    connect(ui->sortButton, &QPushButton::clicked, this, &PoliceController::on_sortButton_clicked);
}

PoliceController::~PoliceController()
{
    Database::getInstance().closeConnection("police_conn");
    delete ui;
}

void PoliceController::loadViolations()
{
    QSqlQuery query(db);
    query.prepare("SELECT report_id, driver_id, bajaj_id, violation_type, description FROM violation_report WHERE police_id = :id");
    query.bindValue(":id", policeId);
    if (!query.exec())
    {
        Helpers::showMessageBox(this, "Error", "Failed to load violations: " + query.lastError().text());
        return;
    }

    violations.clear();
    ui->violationTable->setRowCount(0);

    while (query.next())
    {
        ViolationData violation;
        violation.reportId = query.value(0).toInt();
        violation.driverId = query.value(1).toInt();
        violation.bajajId = query.value(2).toInt();
        violation.violationType = query.value(3).toString();
        violation.description = query.value(4).toString();
        violations.push_back(violation);

        int row = ui->violationTable->rowCount();
        ui->violationTable->insertRow(row);
        ui->violationTable->setItem(row, 0, new QTableWidgetItem(QString::number(violation.reportId)));
        ui->violationTable->setItem(row, 1, new QTableWidgetItem(QString::number(violation.driverId)));
        ui->violationTable->setItem(row, 2, new QTableWidgetItem(QString::number(violation.bajajId)));
        ui->violationTable->setItem(row, 3, new QTableWidgetItem(violation.violationType));
        ui->violationTable->setItem(row, 4, new QTableWidgetItem(violation.description));
    }
}

void PoliceController::merge(std::vector<ViolationData> &arr, int left, int mid, int right, const QString &sortBy)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<ViolationData> leftArr(n1);
    std::vector<ViolationData> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (sortBy == "Report ID")
        {
            if (leftArr[i].reportId <= rightArr[j].reportId)
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
        }
        else if (sortBy == "Driver ID")
        {
            if (leftArr[i].driverId <= rightArr[j].driverId)
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
        }
        else if (sortBy == "Bajaj ID")
        {
            if (leftArr[i].bajajId <= rightArr[j].bajajId)
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
        }
        else if (sortBy == "Violation Type")
        {
            if (leftArr[i].violationType <= rightArr[j].violationType)
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void PoliceController::mergeSort(std::vector<ViolationData> &arr, int left, int right, const QString &sortBy)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, sortBy);
        mergeSort(arr, mid + 1, right, sortBy);
        merge(arr, left, mid, right, sortBy);
    }
}

int PoliceController::binarySearch(const QString &key, const QString &searchBy)
{
    int left = 0, right = violations.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        QString value;
        if (searchBy == "Report ID")
        {
            value = QString::number(violations[mid].reportId);
        }
        else if (searchBy == "Driver ID")
        {
            value = QString::number(violations[mid].driverId);
        }
        else if (searchBy == "Bajaj ID")
        {
            value = QString::number(violations[mid].bajajId);
        }
        else if (searchBy == "Violation Type")
        {
            value = violations[mid].violationType;
        }

        if (value == key)
        {
            return mid;
        }
        else if (value < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void PoliceController::on_searchButton_clicked()
{
    QString searchKey = ui->searchLineEdit->text().trimmed();
    if (searchKey.isEmpty())
    {
        loadViolations();
        return;
    }

    QString searchBy = ui->searchComboBox->currentText();
    mergeSort(violations, 0, violations.size() - 1, searchBy);

    int index = binarySearch(searchKey, searchBy);
    if (index == -1)
    {
        Helpers::showMessageBox(this, "Not Found", "Violation not found!");
        return;
    }

    ui->violationTable->setRowCount(0);
    const auto &violation = violations[index];
    int row = ui->violationTable->rowCount();
    ui->violationTable->insertRow(row);
    ui->violationTable->setItem(row, 0, new QTableWidgetItem(QString::number(violation.reportId)));
    ui->violationTable->setItem(row, 1, new QTableWidgetItem(QString::number(violation.driverId)));
    ui->violationTable->setItem(row, 2, new QTableWidgetItem(QString::number(violation.bajajId)));
    ui->violationTable->setItem(row, 3, new QTableWidgetItem(violation.violationType));
    ui->violationTable->setItem(row, 4, new QTableWidgetItem(violation.description));
}

void PoliceController::on_sortButton_clicked()
{
    if (violations.empty())
        return;

    QString sortBy = ui->sortComboBox->currentText();
    mergeSort(violations, 0, violations.size() - 1, sortBy);

    ui->violationTable->setRowCount(0);
    for (const auto &violation : violations)
    {
        int row = ui->violationTable->rowCount();
        ui->violationTable->insertRow(row);
        ui->violationTable->setItem(row, 0, new QTableWidgetItem(QString::number(violation.reportId)));
        ui->violationTable->setItem(row, 1, new QTableWidgetItem(QString::number(violation.driverId)));
        ui->violationTable->setItem(row, 2, new QTableWidgetItem(QString::number(violation.bajajId)));
        ui->violationTable->setItem(row, 3, new QTableWidgetItem(violation.violationType));
        ui->violationTable->setItem(row, 4, new QTableWidgetItem(violation.description));
    }
}

void PoliceController::on_submitViolationButton_clicked()
{
    bool ok;
    int driverId = ui->driverIdLineEdit->text().toInt(&ok);
    if (!ok)
    {
        Helpers::showMessageBox(this, "Error", "Invalid Driver ID!");
        return;
    }
    int bajajId = ui->bajajIdLineEdit->text().toInt(&ok);
    if (!ok)
    {
        Helpers::showMessageBox(this, "Error", "Invalid Bajaj ID!");
        return;
    }
    QString violationType = ui->violationTypeLineEdit->text().trimmed();
    QString description = ui->descriptionTextEdit->toPlainText().trimmed();

    if (violationType.isEmpty() || description.isEmpty())
    {
        Helpers::showMessageBox(this, "Error", "All fields are required!");
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO violation_report (police_id, driver_id, bajaj_id, violation_type, description) "
                  "VALUES (:policeId, :driverId, :bajajId, :type, :desc)");
    query.bindValue(":policeId", policeId);
    query.bindValue(":driverId", driverId);
    query.bindValue(":bajajId", bajajId);
    query.bindValue(":type", violationType);
    query.bindValue(":desc", description);

    if (query.exec())
    {
        Helpers::showMessageBox(this, "Success", "Violation reported successfully!");
        loadViolations();
    }
    else
    {
        Helpers::showMessageBox(this, "Error", "Failed to report violation: " + query.lastError().text());
    }
}