#ifndef POLICE_CONTROLLER_H
#define POLICE_CONTROLLER_H

#include <QWidget>
#include <QSqlDatabase>
#include <vector>

namespace Ui
{
    class PoliceController;
}

struct ViolationData;

class PoliceController : public QWidget
{
    Q_OBJECT

public:
    explicit PoliceController(int policeId, QWidget *parent = nullptr);
    ~PoliceController();

private slots:
    void on_submitViolationButton_clicked();
    void on_searchButton_clicked();
    void on_sortButton_clicked();

private:
    Ui::PoliceController *ui;
    QSqlDatabase db;
    int policeId;
    std::vector<ViolationData> violations;

    void loadViolations();
    void merge(std::vector<ViolationData> &arr, int left, int mid, int right, const QString &sortBy);
    void mergeSort(std::vector<ViolationData> &arr, int left, int right, const QString &sortBy);
    int binarySearch(const QString &key, const QString &searchBy);
};

#endif // POLICE_CONTROLLER_H