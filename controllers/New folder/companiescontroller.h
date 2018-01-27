#ifndef COMPANIESCONTROLLER_H
#define COMPANIESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT CompaniesController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    CompaniesController() { }
    CompaniesController(const CompaniesController &other);

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

T_DECLARE_CONTROLLER(CompaniesController, companiescontroller)

#endif // COMPANIESCONTROLLER_H
