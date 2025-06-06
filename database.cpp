#include "database.h"
#include "helpers.h"
#include <QSqlError>
#include <QDebug>

const QString Database::HOST = "localhost";
const QString Database::DB_NAME = "Bajaj_Management System";
const QString Database::USER = "postgres";
const QString Database::PASSWORD = "123456";

Database::Database() {
    db = QSqlDatabase::addDatabase("QPSQL", "global_conn");
    db.setHostName(HOST);
    db.setDatabaseName(DB_NAME);
    db.setUserName(USER);
    db.setPort(5432);
    db.setPassword(PASSWORD);
}

Database& Database::getInstance() {
    static Database instance;
    return instance;
}

QSqlDatabase Database::getConnection(const QString& connectionName) {
    if (connectionName.isEmpty()) {
        if (!db.isOpen() && !db.open()) {
            QSqlError error = db.lastError();
            Helpers::showMessageBox(nullptr, "Error",
                                    "Database connection failed: " + error.text());
        }
        return db;
    }

    if (QSqlDatabase::contains(connectionName)) {
        return QSqlDatabase::database(connectionName);
    }

    QSqlDatabase newDb = QSqlDatabase::cloneDatabase(db, connectionName);
    if (!newDb.open()) {
        QSqlError error = newDb.lastError();
        Helpers::showMessageBox(nullptr, "Error",
                                "Database connection failed: " + error.text());
    }
    return newDb;
}

void Database::closeConnection(const QString& connectionName) {
    if (connectionName.isEmpty()) {
        if (db.isOpen()) {
            db.close();
        }
        return;
    }

    if (QSqlDatabase::contains(connectionName)) {
        QSqlDatabase conn = QSqlDatabase::database(connectionName);
        conn.close(); // Ensure the connection is closed
        QSqlDatabase::removeDatabase(connectionName); // Remove it after closing
    }
}

bool Database::testConnection() {
    bool isOpen = false;
    {
        // Scope block to ensure testDb is destroyed before closing the connection
        QSqlDatabase testDb = getConnection("test_connection");
        isOpen = testDb.isOpen();
    } // testDb goes out of scope here
    closeConnection("test_connection");
    return isOpen;
}
