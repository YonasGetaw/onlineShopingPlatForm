#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include <QWidget>
#include "admin_controller.h"
#include "driver_controller.h"
#include "police_controller.h"
#include "session_manager.h"

namespace Ui
{
    class LoginController;
}

class LoginController : public QWidget
{
    Q_OBJECT

public:
    explicit LoginController(QWidget *parent = nullptr);
    ~LoginController();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginController *ui;
    SessionManager *session;
};

#endif // LOGIN_CONTROLLER_H
