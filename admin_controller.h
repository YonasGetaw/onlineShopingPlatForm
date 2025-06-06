#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include <QWidget>
#include <QSqlDatabase>
#include <vector>

namespace Ui
{
    class AdminController;
}

struct DriverData;

class AdminController : public QWidget
{
    Q_OBJECT

public:
    explicit AdminController(int adminId, QWidget *parent = nullptr);
    ~AdminController();

private slots:
    void on_addDriverButton_clicked();
    void on_searchButton_clicked();
    void on_sortButton_clicked();

private:
    Ui::AdminController *ui;
    QSqlDatabase db;
    int adminId;
    std::vector<DriverData> drivers;

    void loadDrivers();
    void merge(std::vector<DriverData> &arr, int left, int mid, int right, const QString &sortBy);
    void mergeSort(std::vector<DriverData> &arr, int left, int right, const QString &sortBy);
    int binarySearch(const QString &key, const QString &searchBy);
};

#endif // ADMIN_CONTROLLER_H