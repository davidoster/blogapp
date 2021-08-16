#pragma once
#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UserController : public ApplicationController {
    Q_OBJECT
public slots:
    void index();
    void show(const QString &username);
    void create();
    void save(const QString &username);
    void remove(const QString &username);
protected:
    virtual bool preFilter();
};

