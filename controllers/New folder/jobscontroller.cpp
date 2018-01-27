#include "jobscontroller.h"
#include "jobs.h"


JobsController::JobsController(const JobsController &)
    : ApplicationController()
{ }

void JobsController::index()
{
    auto jobsList = Jobs::getAll();
    texport(jobsList);
    render();
}

void JobsController::show(const QString &id)
{
    auto jobs = Jobs::get(id.toInt());
    texport(jobs);
    render();
}

void JobsController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto jobs = httpRequest().formItems("jobs");
        auto model = Jobs::create(jobs);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(jobs);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void JobsController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Jobs::get(id.toInt());
        if (!model.isNull()) {
            auto jobs = model.toVariantMap();
            texport(jobs);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Jobs::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto jobs = httpRequest().formItems("jobs");
        model.setProperties(jobs);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(jobs);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void JobsController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto jobs = Jobs::get(id.toInt());
    jobs.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(jobscontroller)
