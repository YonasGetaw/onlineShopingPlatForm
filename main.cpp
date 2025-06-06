#include <QApplication>
#include "database.h"
#include "login_controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Database& dbInstance = Database::getInstance();
    if (!dbInstance.testConnection()) {
        qDebug() << "Failed to connect to the database.";
        return -1;
    } else {
        qDebug() << "Database connection successful!";
    }

    LoginController loginWindow;
    loginWindow.show();

    return app.exec();
}
