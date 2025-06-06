#include "helpers.h"
#include <QRegularExpression>

bool Helpers::validateEmail(const QString &email)
{
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    return emailRegex.match(email).hasMatch();
}

bool Helpers::validateLicenseNumber(const QString &license)
{
    QRegularExpression licenseRegex("^[A-Z0-9]{5,15}$");
    return licenseRegex.match(license).hasMatch();
}

void Helpers::showMessageBox(QWidget *parent, const QString &title, const QString &text)
{
    QMessageBox::information(parent, title, text);
}