#pragma once

#include "command.h"
#include "../utils/input_helpers.h"
#include "../storages/book_storage.h"
#include "../app/app_state.h"

class RateCommand : public Command {
    int score_;

public:
    static const char* kName;

    RateCommand(List<char*>* args);

    virtual void exec();
};
