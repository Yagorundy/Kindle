#pragma once

#include <iostream>

#include "command.h"
#include "add_page_command.h"
#include "../utils/input_helpers.h"
#include "../app/app_state.h"
#include "../storages/book_storage.h"

class WriteCommand : public Command {
public:
    static const char* kName;

    WriteCommand(List<char*>* args);

    virtual void exec();
};
