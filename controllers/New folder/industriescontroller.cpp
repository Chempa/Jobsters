#include "industriescontroller.h"
#include "industries.h"


IndustriesController::IndustriesController(const IndustriesController &)
    : ApplicationController()
{ }

void IndustriesController::index()
{
    auto industriesList = Industries::getAll();
    texport(industriesList);
    render();
}

void IndustriesController::show(const QString &id)
{
    auto industries = Industries::get(id.toInt());
    texport(industries);
    render();
}

void IndustriesController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto industries = httpRequest().formItems("industries");
        auto model = Industries::create(industries);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(industries);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void IndustriesController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Industries::get(id.toInt());
        if (!model.isNull()) {
            auto industries = model.toVariantMap();
            texport(industries);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Industries::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto industries = httpRequest().formItems("industries");
        model.setProperties(industries);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(industries);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void IndustriesController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto industries = Industries::get(id.toInt());
    industries.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(industriescontroller)
