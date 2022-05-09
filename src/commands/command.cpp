#include "command.h"
#include "add_page_command.h"
#include "comment_command.h"
#include "login_command.h"
#include "logout_command.h"
#include "rate_command.h"
#include "read_command.h"
#include "sign_up_command.h"
#include "view_books_command.h"
#include "view_comments_command.h"
#include "view_ratings_command.h"
#include "write_command.h"

Command::Command(List<char*>* args)
    : args_(args)
{ }

Command::~Command() {
    for (size_t i = 0; i < args_->size(); i++)
        delete[](*args_)[i];
    delete args_;
}

void Command::assertUserIsLoggedIn() {
    if (!AppState::getInstance().isLoggedIn())
        throw ValidationException("You are not logged in!");
}

Command* Command::create(const char* name, List<char*>* args) {
    if (strcmp(name, AddPageCommand::kName) == 0)
        return new AddPageCommand(args);
    if (strcmp(name, CommentCommand::kName) == 0)
        return new CommentCommand(args);
    if (strcmp(name, LoginCommand::kName) == 0)
        return new LoginCommand(args);
    if (strcmp(name, LogoutCommand::kName) == 0)
        return new LogoutCommand(args);
    if (strcmp(name, RateCommand::kName) == 0)
        return new RateCommand(args);
    if (strcmp(name, ReadCommand::kName) == 0)
        return new ReadCommand(args);
    if (strcmp(name, SignUpCommand::kName) == 0)
        return new SignUpCommand(args);
    if (strcmp(name, ViewBooksCommand::kName) == 0)
        return new ViewBooksCommand(args);
    if (strcmp(name, ViewCommentsCommand::kName) == 0)
        return new ViewCommentsCommand(args);
    if (strcmp(name, ViewRatingsCommand::kName) == 0)
        return new ViewRatingsCommand(args);
    if (strcmp(name, WriteCommand::kName) == 0)
        return new WriteCommand(args);
    throw ValidationException("Unrecognized command!");
}
