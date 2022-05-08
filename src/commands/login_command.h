#pragma once

#include "command.h"
#include "../app/app_state.h"
#include "../storages/user_storage.h"
#include "../utils/input_helpers.h"

class LoginCommand : public Command {
public:
    static const char* kName;

    LoginCommand(List<char*>* args);

    virtual void exec();
};
