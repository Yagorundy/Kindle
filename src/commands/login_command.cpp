#include "login_command.h"

const char* LoginCommand::kName = "login";

LoginCommand::LoginCommand(List<char*>* args)
    : Command(args)
{
    //if (args->size() != 1)
    //    throw InvalidArgumentsException();

    //value_ = num_helper::FromHex((*args_)[0]);
}

void LoginCommand::exec() {
    if (AppState::getInstance().isLoggedIn())
        throw ValidationException("Already logged in!");

    const char* username = promptSingleLineInput("Enter username: ");
    const char* password = promptSingleLineInput("Enter password: ");
    
    UserModel* user = UserStorage::getInstance().login(username, password);
    AppState::getInstance().setUserId(user->getId());

    std::cout << "\tWelcome, " << user->getUsername() << "!\n";
}
