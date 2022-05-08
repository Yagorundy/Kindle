#pragma once

#include "command.h"
#include "../app/app_state.h"
#include "../storages/user_storage.h"
#include "../utils/input_helpers.h"

class SignUpCommand : public Command {
public:
    static const char* kName;

    SignUpCommand(List<char*>* args);

    virtual void exec();
};
