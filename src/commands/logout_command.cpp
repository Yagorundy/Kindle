#include "logout_command.h"

const char* LogoutCommand::kName = "logout";

LogoutCommand::LogoutCommand(List<char*>* args)
    : Command(args)
{ }

void LogoutCommand::exec() {
    AppState::getInstance().clear();
}
