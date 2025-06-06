#include "session_manager.h"

SessionManager &SessionManager::getInstance()
{
    static SessionManager instance;
    return instance;
}

void SessionManager::setUser(int id, QString role)
{
    userId = id;
    userRole = role;
}

int SessionManager::getUserId() const
{
    return userId;
}

QString SessionManager::getUserRole() const
{
    return userRole;
}

void SessionManager::clearSession()
{
    userId = -1;
    userRole = "";
}