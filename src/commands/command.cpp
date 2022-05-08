#include "command.h"
#include "sign_up_command.h"
#include "login_command.h"
#include "logout_command.h"

Command::Command(List<char*>* args)
    : args_(args)
{ }

Command::~Command() {
    for (size_t i = 0; i < args_->size(); i++)
        delete[](*args_)[i];
    delete args_;
}

Command* Command::create(const char* name, List<char*>* args) {
    if (strcmp(name, SignUpCommand::kName) == 0)
        return new SignUpCommand(args);
    if (strcmp(name, LoginCommand::kName) == 0)
        return new LoginCommand(args);
    if (strcmp(name, LogoutCommand::kName) == 0)
        return new LogoutCommand(args);
    throw ValidationException("Unrecognized command!");
}
