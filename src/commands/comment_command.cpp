#include "comment_command.h"

const char* CommentCommand::kName = "comment";

CommentCommand::CommentCommand(List<char*>* args)
    : Command(args)
{
    if (args->size() != 2)
        throw InvalidArgumentsException();
}

void CommentCommand::exec() {
    assertUserIsLoggedIn();

    BookModel* book = BookStorage::getInstance().getBookByTitle((*args_)[0]);

    auto userId = AppState::getInstance().getUserId();

    if (book->getAuthorId() == userId) {
        delete book;
        throw ValidationException("You cannot comment on your own books!");
    }

    if (!BookStorage::getInstance().hasUserReadBook(userId, book->getId())) {
        delete book;
        throw ValidationException("You can add a comment after you have read the book!");
    }

    BookStorage::getInstance().addComment(userId, book->getId(), (*args_)[1]);
}