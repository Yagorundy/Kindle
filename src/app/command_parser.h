#pragma once

#include <iostream>

#include "../commands/command.h";
#include "../utils/str_helpers.h"

class CommandParser {
public:
	Command* parseCommand(const char* path);
};
