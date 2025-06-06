#include "login_controller.h"
#include "ui_login.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include "helpers.h"

LoginController::LoginController(QWidget *parent) : QWidget(parent),
                                                    ui(new Ui::LoginController),
                                                    session(&SessionManager::getInstance())
{
    ui->setupUi(this);

    QSqlDatabase db = Database::getInstance().getConnection("login_conn");
    if (!db.isOpen())
    {
        close();
        return;
    }
}

LoginController::~LoginController()
{
    Database::getInstance().closeConnection("login_conn");
    delete ui;
}

void LoginController::on_loginButton_clicked()
{
    QString email = ui->emailLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text();
    QString role = ui->roleComboBox->currentText();

    if (!Helpers::validateEmail(email))
    {
        Helpers::showMessageBox(this, "Error", "Invalid email format!");
        return;
    }

    QSqlDatabase db = Database::getInstance().getConnection("login_conn");
    QSqlQuery query(db);
    QString table = role.toLower() == "admin" ? "admin" : role.toLower() == "driver" ? "driver"
                                                                                     : "traffic_police";
    QString idField = role.toLower() == "admin" ? "admin_id" : role.toLower() == "driver" ? "driver_id"
                                                                                          : "police_id";

    query.prepare(QString("SELECT %1 FROM %2 WHERE email = :email AND password = :password").arg(idField, table));
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec() && query.next())
    {
        int userId = query.value(0).toInt();
        session->setUser(userId, role);
        if (role == "Admin")
        {
            AdminController *admin = new AdminController(userId);
            admin->show();
        }
        else if (role == "Driver")
        {
            DriverController *driver = new DriverController(userId);
            driver->show();
        }
        else
        {
            PoliceController *police = new PoliceController(userId);
            police->show();
        }
        this->close();
    }
    else
    {
        Helpers::showMessageBox(this, "Error", "Invalid credentials!");
    }
}
