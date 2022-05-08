#include "logout_command.h"

const char* LogoutCommand::kName = "logout";

LogoutCommand::LogoutCommand(List<char*>* args)
    : Command(args)
{
    //if (args->size() != 1)
    //    throw InvalidArgumentsException();

    //value_ = num_helper::FromHex((*args_)[0]);
}

void LogoutCommand::exec() {
    AppState::getInstance().clear();
}
