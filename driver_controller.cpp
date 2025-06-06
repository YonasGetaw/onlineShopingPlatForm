#include "driver_controller.h"
#include "ui_driver_dashboard.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include "helpers.h"

struct IssueData
{
    int issueId;
    QString issueType;
    QString description;
    QString status;
};

DriverController::DriverController(int driverId, QWidget *parent) : QWidget(parent),
                                                                    ui(new Ui::DriverController),
                                                                    driverId(driverId)
{
    ui->setupUi(this);

    db = Database::getInstance().getConnection("driver_conn");
    if (!db.isOpen())
    {
        close();
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT r.start_point, r.end_point FROM driver d "
                  "JOIN route r ON d.assigned_route_id = r.route_id WHERE d.driver_id = :id");
    query.bindValue(":id", driverId);
    if (query.exec() && query.next())
    {
        ui->routeLabel->setText("Route: " + query.value(0).toString() + " to " + query.value(1).toString());
    }

    loadIssues();

    connect(ui->reportIssueButton, &QPushButton::clicked, this, &DriverController::on_reportIssueButton_clicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &DriverController::on_searchButton_clicked);
    connect(ui->sortButton, &QPushButton::clicked, this, &DriverController::on_sortButton_clicked);
}

DriverController::~DriverController()
{
    Database::getInstance().closeConnection("driver_conn");
    delete ui;
}

void DriverController::loadIssues()
{
    QSqlQuery query(db);
    query.prepare("SELECT issue_id, issue_type, description, status FROM driver_issue WHERE driver_id = :id");
    query.bindValue(":id", driverId);
    if (!query.exec())
    {
        Helpers::showMessageBox(this, "Error", "Failed to load issues: " + query.lastError().text());
        return;
    }

    issues.clear();
    ui->issueTable->setRowCount(0);

    while (query.next())
    {
        IssueData issue;
        issue.issueId = query.value(0).toInt();
        issue.issueType = query.value(1).toString();
        issue.description = query.value(2).toString();
        issue.status = query.value(3).toString();
        issues.push_back(issue);

        int row = ui->issueTable->rowCount();
        ui->issueTable->insertRow(row);
        ui->issueTable->setItem(row, 0, new QTableWidgetItem(QString::number(issue.issueId)));
        ui->issueTable->setItem(row, 1, new QTableWidgetItem(issue.issueType));
        ui->issueTable->setItem(row, 2, new QTableWidgetItem(issue.description));
        ui->issueTable->setItem(row, 3, new QTableWidgetItem(issue.status));
    }
}

void DriverController::merge(std::vector<IssueData> &arr, int left, int mid, int right, const QString &sortBy)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<IssueData> leftArr(n1);
    std::vector<IssueData> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (sortBy == "Issue ID")
        {
            if (leftArr[i].issueId <= rightArr[j].issueId)
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
        else if (sortBy == "Issue Type")
        {
            if (leftArr[i].issueType <= rightArr[j].issueType)
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
        else if (sortBy == "Status")
        {
            if (leftArr[i].status <= rightArr[j].status)
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

void DriverController::mergeSort(std::vector<IssueData> &arr, int left, int right, const QString &sortBy)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, sortBy);
        mergeSort(arr, mid + 1, right, sortBy);
        merge(arr, left, mid, right, sortBy);
    }
}

int DriverController::binarySearch(const QString &key, const QString &searchBy)
{
    int left = 0, right = issues.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        QString value;
        if (searchBy == "Issue ID")
        {
            value = QString::number(issues[mid].issueId);
        }
        else if (searchBy == "Issue Type")
        {
            value = issues[mid].issueType;
        }
        else if (searchBy == "Description")
        {
            value = issues[mid].description;
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

void DriverController::on_searchButton_clicked()
{
    QString searchKey = ui->searchLineEdit->text().trimmed();
    if (searchKey.isEmpty())
    {
        loadIssues();
        return;
    }

    QString searchBy = ui->searchComboBox->currentText();
    mergeSort(issues, 0, issues.size() - 1, searchBy);

    int index = binarySearch(searchKey, searchBy);
    if (index == -1)
    {
        Helpers::showMessageBox(this, "Not Found", "Issue not found!");
        return;
    }

    ui->issueTable->setRowCount(0);
    const auto &issue = issues[index];
    int row = ui->issueTable->rowCount();
    ui->issueTable->insertRow(row);
    ui->issueTable->setItem(row, 0, new QTableWidgetItem(QString::number(issue.issueId)));
    ui->issueTable->setItem(row, 1, new QTableWidgetItem(issue.issueType));
    ui->issueTable->setItem(row, 2, new QTableWidgetItem(issue.description));
    ui->issueTable->setItem(row, 3, new QTableWidgetItem(issue.status));
}

void DriverController::on_sortButton_clicked()
{
    if (issues.empty())
        return;

    QString sortBy = ui->sortComboBox->currentText();
    mergeSort(issues, 0, issues.size() - 1, sortBy);

    ui->issueTable->setRowCount(0);
    for (const auto &issue : issues)
    {
        int row = ui->issueTable->rowCount();
        ui->issueTable->insertRow(row);
        ui->issueTable->setItem(row, 0, new QTableWidgetItem(QString::number(issue.issueId)));
        ui->issueTable->setItem(row, 1, new QTableWidgetItem(issue.issueType));
        ui->issueTable->setItem(row, 2, new QTableWidgetItem(issue.description));
        ui->issueTable->setItem(row, 3, new QTableWidgetItem(issue.status));
    }
}

void DriverController::on_reportIssueButton_clicked()
{
    QString issueType = ui->issueTypeLineEdit->text().trimmed();
    QString description = ui->descriptionTextEdit->toPlainText().trimmed();

    if (issueType.isEmpty() || description.isEmpty())
    {
        Helpers::showMessageBox(this, "Error", "All fields are required!");
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO driver_issue (driver_id, issue_type, description, status) "
                  "VALUES (:driverId, :type, :desc, 'Pending')");
    query.bindValue(":driverId", driverId);
    query.bindValue(":type", issueType);
    query.bindValue(":desc", description);

    if (query.exec())
    {
        Helpers::showMessageBox(this, "Success", "Issue reported successfully!");
        loadIssues();
    }
    else
    {
        Helpers::showMessageBox(this, "Error", "Failed to report issue: " + query.lastError().text());
    }
}