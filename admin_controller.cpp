#include "admin_controller.h"
#include "ui_admin_dashboard.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include "helpers.h"
#include <vector>
#include <algorithm>

struct DriverData {
    int id;
    QString fullName;
    QString email;
    QString licenseNumber;
};

AdminController::AdminController(int adminId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminController),
    adminId(adminId) {
    ui->setupUi(this);

    db = Database::getInstance().getConnection("admin_conn");
    if (!db.isOpen()) {
        close();
        return;
    }

    loadDrivers();

    connect(ui->addDriverButton, &QPushButton::clicked, this, &AdminController::on_addDriverButton_clicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &AdminController::on_searchButton_clicked);
    connect(ui->sortButton, &QPushButton::clicked, this, &AdminController::on_sortButton_clicked);
}

AdminController::~AdminController() {
    Database::getInstance().closeConnection("admin_conn");
    delete ui;
}

void AdminController::loadDrivers() {
    QSqlQuery query(db);
    query.prepare("SELECT driver_id, full_name, email, license_number FROM driver");
    if (!query.exec()) {
        Helpers::showMessageBox(this, "Error", "Failed to load drivers: " + query.lastError().text());
        return;
    }

    drivers.clear();
    ui->driverTable->setRowCount(0);

    while (query.next()) {
        DriverData driver;
        driver.id = query.value(0).toInt();
        driver.fullName = query.value(1).toString();
        driver.email = query.value(2).toString();
        driver.licenseNumber = query.value(3).toString();
        drivers.push_back(driver);

        int row = ui->driverTable->rowCount();
        ui->driverTable->insertRow(row);
        ui->driverTable->setItem(row, 0, new QTableWidgetItem(QString::number(driver.id)));
        ui->driverTable->setItem(row, 1, new QTableWidgetItem(driver.fullName));
        ui->driverTable->setItem(row, 2, new QTableWidgetItem(driver.email));
        ui->driverTable->setItem(row, 3, new QTableWidgetItem(driver.licenseNumber));
    }
}

void AdminController::merge(std::vector<DriverData>& arr, int left, int mid, int right, const QString& sortBy) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<DriverData> leftArr(n1);
    std::vector<DriverData> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (sortBy == "ID") {
            if (leftArr[i].id <= rightArr[j].id) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        } else if (sortBy == "Name") {
            if (leftArr[i].fullName <= rightArr[j].fullName) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        } else if (sortBy == "Email") {
            if (leftArr[i].email <= rightArr[j].email) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        } else if (sortBy == "License Number") {
            if (leftArr[i].licenseNumber <= rightArr[j].licenseNumber) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void AdminController::mergeSort(std::vector<DriverData>& arr, int left, int right, const QString& sortBy) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, sortBy);
        mergeSort(arr, mid + 1, right, sortBy);
        merge(arr, left, mid, right, sortBy);
    }
}

int AdminController::binarySearch(const QString& key, const QString& searchBy) {
    int left = 0, right = drivers.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        QString value;
        if (searchBy == "ID") {
            value = QString::number(drivers[mid].id);
        } else if (searchBy == "Name") {
            value = drivers[mid].fullName;
        } else if (searchBy == "Email") {
            value = drivers[mid].email;
        } else if (searchBy == "License Number") {
            value = drivers[mid].licenseNumber;
        }

        if (value == key) {
            return mid;
        } else if (value < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void AdminController::on_searchButton_clicked() {
    QString searchKey = ui->searchLineEdit->text().trimmed();
    if (searchKey.isEmpty()) {
        loadDrivers();
        return;
    }

    QString searchBy = ui->searchComboBox->currentText();
    mergeSort(drivers, 0, drivers.size() - 1, searchBy);

    int index = binarySearch(searchKey, searchBy);
    if (index == -1) {
        Helpers::showMessageBox(this, "Not Found", "Driver not found!");
        return;
    }

    ui->driverTable->setRowCount(0);
    const auto& driver = drivers[index];
    int row = ui->driverTable->rowCount();
    ui->driverTable->insertRow(row);
    ui->driverTable->setItem(row, 0, new QTableWidgetItem(QString::number(driver.id)));
    ui->driverTable->setItem(row, 1, new QTableWidgetItem(driver.fullName));
    ui->driverTable->setItem(row, 2, new QTableWidgetItem(driver.email));
    ui->driverTable->setItem(row, 3, new QTableWidgetItem(driver.licenseNumber));
}

void AdminController::on_sortButton_clicked() {
    if (drivers.empty()) return;

    QString sortBy = ui->sortComboBox->currentText();
    mergeSort(drivers, 0, drivers.size() - 1, sortBy);

    ui->driverTable->setRowCount(0);
    for (const auto& driver : drivers) {
        int row = ui->driverTable->rowCount();
        ui->driverTable->insertRow(row);
        ui->driverTable->setItem(row, 0, new QTableWidgetItem(QString::number(driver.id)));
        ui->driverTable->setItem(row, 1, new QTableWidgetItem(driver.fullName));
        ui->driverTable->setItem(row, 2, new QTableWidgetItem(driver.email));
        ui->driverTable->setItem(row, 3, new QTableWidgetItem(driver.licenseNumber));
    }
}

void AdminController::on_addDriverButton_clicked() {
    QString fullName = ui->driverNameLineEdit->text().trimmed();
    QString email = ui->driverEmailLineEdit->text().trimmed();
    QString license = ui->licenseLineEdit->text().trimmed();

    if (fullName.isEmpty() || email.isEmpty() || license.isEmpty()) {
        Helpers::showMessageBox(this, "Error", "All fields are required!");
        return;
    }

    if (!Helpers::validateEmail(email)) {
        Helpers::showMessageBox(this, "Error", "Invalid email format!");
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO driver (full_name, email, license_number, password, shift_status) "
                  "VALUES (:name, :email, :license, 'default123', 'Off Duty')");
    query.bindValue(":name", fullName);
    query.bindValue(":email", email);
    query.bindValue(":license", license);

    if (query.exec()) {
        Helpers::showMessageBox(this, "Success", "Driver added successfully!");
        loadDrivers();
    } else {
        Helpers::showMessageBox(this, "Error", "Failed to add driver: " + query.lastError().text());
    }
}
