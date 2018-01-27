#ifndef INDUSTRIESCONTROLLER_H
#define INDUSTRIESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT IndustriesController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    IndustriesController() { }
    IndustriesController(const IndustriesController &other);

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

T_DECLARE_CONTROLLER(IndustriesController, industriescontroller)

#endif // INDUSTRIESCONTROLLER_H
