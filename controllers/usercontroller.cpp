#include "usercontroller.h"
#include "userservice.h"
#include <TreeFrogController>

static UserService service;

bool UserController::preFilter()
{
    if(!isUserLoggedIn()) {
        redirect(QUrl("/Blog"));
        return(false);
    } else {
        QString username = identityKeyOfLoginUser();
        texport(username);
        return(true);
    }
}

void UserController::index()
{
    service.index();
    render();
}

void UserController::show(const QString &username)
{
    service.show(username);
    render();
}

void UserController::create()
{
    QString username;

    switch (request().method()) {
    case Tf::Get:
        render();
        break;
    case Tf::Post:
        username = service.create(request());
        if (!username.isEmpty()) {
            redirect(urla("show", username));
        } else {
            render();
        }
        break;

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void UserController::save(const QString &username)
{
    int res;

    switch (request().method()) {
    case Tf::Get:
        service.edit(session(), username);
        render();
        break;
    case Tf::Post:
        res = service.save(request(), session(), username);
        if (res > 0) {
            // Save completed
            redirect(urla("show", username));
        } else if (res < 0) {
            // Failed
            render();
        } else {
            // Retry
            redirect(urla("save", username));
        }
        break;
    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void UserController::remove(const QString &username)
{
    switch (request().method()) {
    case Tf::Post:
        service.remove(username);
        redirect(urla("index"));
        break;
    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(UserController)
