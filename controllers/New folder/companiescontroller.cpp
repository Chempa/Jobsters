#include "companiescontroller.h"
#include "companies.h"


CompaniesController::CompaniesController(const CompaniesController &)
    : ApplicationController()
{ }

void CompaniesController::index()
{
    auto companiesList = Companies::getAll();
    texport(companiesList);
    render();
}

void CompaniesController::show(const QString &id)
{
    auto companies = Companies::get(id.toInt());
    texport(companies);
    render();
}

void CompaniesController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto companies = httpRequest().formItems("companies");
        auto model = Companies::create(companies);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(companies);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void CompaniesController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Companies::get(id.toInt());
        if (!model.isNull()) {
            auto companies = model.toVariantMap();
            texport(companies);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Companies::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto companies = httpRequest().formItems("companies");
        model.setProperties(companies);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(companies);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void CompaniesController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto companies = Companies::get(id.toInt());
    companies.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(companiescontroller)
