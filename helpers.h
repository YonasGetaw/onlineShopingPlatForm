#ifndef HELPERS_H
#define HELPERS_H

#include <QString>
#include <QMessageBox>

class Helpers
{
public:
    static bool validateEmail(const QString &email);
    static bool validateLicenseNumber(const QString &license);
    static void showMessageBox(QWidget *parent, const QString &title, const QString &text);
};

#endif // HELPERS_H