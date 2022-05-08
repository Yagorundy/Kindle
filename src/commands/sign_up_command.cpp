#include "sign_up_command.h"

const char* SignUpCommand::kName = "signup";

SignUpCommand::SignUpCommand(List<char*>* args)
    : Command(args)
{
    //if (args->size() != 1)
    //    throw InvalidArgumentsException();

    //value_ = num_helper::FromHex((*args_)[0]);
}

void SignUpCommand::exec() {
    if (AppState::getInstance().isLoggedIn())
        throw ValidationException("Already signed in! Log out in order to sign up.");

    const char* username = promptSingleLineInput("Enter username: ");
    const char* password = promptSingleLineInput("Enter password: ");
    UserStorage::getInstance().signUp(username, password);
    std::cout << "\tUser registered!\n";
}
