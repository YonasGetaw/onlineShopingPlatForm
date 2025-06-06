#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlError> // Explicitly include QSqlError

class Database
{
public:
    static Database &getInstance();
    QSqlDatabase getConnection(const QString &connectionName = "");
    void closeConnection(const QString &connectionName = "");
    bool testConnection();

private:
    Database();
    QSqlDatabase db;
    static const QString HOST;
    static const QString DB_NAME;
    static const QString USER;
    static const QString PASSWORD;
};

#endif // DATABASE_H
