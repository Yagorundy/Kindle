#pragma once

#include "command.h"
#include "../utils/input_helpers.h"
#include "../storages/book_storage.h"
#include "../app/app_state.h"

class CommentCommand : public Command {
public:
    static const char* kName;

    CommentCommand(List<char*>* args);

    virtual void exec();
};
