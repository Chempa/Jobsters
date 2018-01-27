#ifndef JOBSCONTROLLER_H
#define JOBSCONTROLLER_H

#include "applicationcontroller.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>

class T_CONTROLLER_EXPORT JobsController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    JobsController() { }
    JobsController(const JobsController &other);
    void sidebarsetup();

public slots:
	void index();
    void show(const QString &id);
    void addjob();
    void remove(QString &id);
    void search();
    void show();
};

T_DECLARE_CONTROLLER(JobsController, jobscontroller)

#endif // JOBSCONTROLLER_H
