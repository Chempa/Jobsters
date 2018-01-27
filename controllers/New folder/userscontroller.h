#ifndef USERSCONTROLLER_H
#define USERSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UsersController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    UsersController() { }
    UsersController(const UsersController &other);

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

T_DECLARE_CONTROLLER(UsersController, userscontroller)

#endif // USERSCONTROLLER_H
