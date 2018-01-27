#include "userscontroller.h"
#include "users.h"


UsersController::UsersController(const UsersController &)
    : ApplicationController()
{ }

void UsersController::index()
{
    auto usersList = Users::getAll();
    texport(usersList);
    render();
}

void UsersController::show(const QString &id)
{
    auto users = Users::get(id.toInt());
    texport(users);
    render();
}

void UsersController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto users = httpRequest().formItems("users");
        auto model = Users::create(users);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(users);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void UsersController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Users::get(id.toInt());
        if (!model.isNull()) {
            auto users = model.toVariantMap();
            texport(users);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Users::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto users = httpRequest().formItems("users");
        model.setProperties(users);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(users);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void UsersController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto users = Users::get(id.toInt());
    users.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_REGISTER_CONTROLLER(userscontroller)
