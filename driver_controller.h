#ifndef DRIVER_CONTROLLER_H
#define DRIVER_CONTROLLER_H

#include <QWidget>
#include <QSqlDatabase>
#include <vector>

namespace Ui
{
    class DriverController;
}

struct IssueData;

class DriverController : public QWidget
{
    Q_OBJECT

public:
    explicit DriverController(int driverId, QWidget *parent = nullptr);
    ~DriverController();

private slots:
    void on_reportIssueButton_clicked();
    void on_searchButton_clicked();
    void on_sortButton_clicked();

private:
    Ui::DriverController *ui;
    QSqlDatabase db;
    int driverId;
    std::vector<IssueData> issues;

    void loadIssues();
    void merge(std::vector<IssueData> &arr, int left, int mid, int right, const QString &sortBy);
    void mergeSort(std::vector<IssueData> &arr, int left, int right, const QString &sortBy);
    int binarySearch(const QString &key, const QString &searchBy);
};

#endif // DRIVER_CONTROLLER_H