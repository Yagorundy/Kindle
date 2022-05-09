#pragma once

#include <iostream>

#include "command.h"
#include "../app/app_state.h"
#include "../storages/book_storage.h"
#include "../storages/user_storage.h"

class ViewBooksCommand : public Command {
public:
    static const char* kName;

    ViewBooksCommand(List<char*>* args);

    virtual void exec();
};
