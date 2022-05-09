#pragma once

#include "command.h"
#include "../storages/book_storage.h"
#include "../app/app_state.h"
#include "../utils/input_helpers.h"

class AddPageCommand : public Command {

public:
    static const char* kName;

    AddPageCommand(List<char*>* args);

    virtual void exec();
};
