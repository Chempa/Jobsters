#ifndef JOBSCONTROLLER_H
#define JOBSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT JobsController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    JobsController() { }
    JobsController(const JobsController &other);

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

T_DECLARE_CONTROLLER(JobsController, jobscontroller)

#endif // JOBSCONTROLLER_H
