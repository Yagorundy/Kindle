#pragma once

#include <cstring>

#include "../utils/list.h"

class Command {
protected:
    List<char*>* args_;

public:
    static Command* create(const char* name, List<char*>* args);

    Command(List<char*>* args);
    ~Command();

    virtual void exec() = 0;
};
