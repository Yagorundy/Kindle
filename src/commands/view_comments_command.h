#pragma once

#include <iostream>

#include "command.h"
#include "../storages/book_storage.h"
#include "../storages/user_storage.h"

class ViewCommentsCommand : public Command {
public:
    static const char* kName;

    ViewCommentsCommand(List<char*>* args);

    virtual void exec();
};
