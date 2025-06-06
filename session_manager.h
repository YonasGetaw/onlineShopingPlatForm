#ifndef SESSION_MANAGER_H
#define SESSION_MANAGER_H

#include <QString>

class SessionManager
{
public:
    static SessionManager &getInstance();
    void setUser(int id, QString role);
    int getUserId() const;
    QString getUserRole() const;
    void clearSession();

private:
    SessionManager() : userId(-1), userRole("") {}
    int userId;
    QString userRole;
};

#endif // SESSION_MANAGER_H