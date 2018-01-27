#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "applicationcontroller.h"
#include "users.h"

class T_CONTROLLER_EXPORT AccountController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    AccountController() { }
    AccountController(const AccountController &other);
    void sidebarsetup();
public slots:
    void login();
    void logout();
    void signup();
    void resetpassword();
    void resetpasswordphase2();
    void resetpasswordphase3();
    void userpreference();
};

T_DECLARE_CONTROLLER(AccountController, accountcontroller)

#endif // ACCOUNTCONTROLLER_H
