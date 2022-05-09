#pragma once

#include "command.h"
#include "../storages/book_storage.h"
#include "../app/app_state.h"
#include "../utils/input_helpers.h"

class ReadCommand : public Command {
public:
    static const char* kName;

    ReadCommand(List<char*>* args);

    virtual void exec();
};
