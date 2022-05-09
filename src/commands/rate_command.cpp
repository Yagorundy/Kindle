#include "rate_command.h"

const char* RateCommand::kName = "rate";

RateCommand::RateCommand(List<char*>* args)
    : Command(args)
{
    if (args->size() != 2)
        throw InvalidArgumentsException();

    score_ = parseInt((*args)[1]);
    if (score_ < 0 || score_ > 10)
        throw ValidationException("Rating must be a number from 0 to 10!");
}

void RateCommand::exec() {
    assertUserIsLoggedIn();

    BookModel* book = BookStorage::getInstance().getBookByTitle((*args_)[0]);

    auto userId = AppState::getInstance().getUserId();

    if (book->getAuthorId() == userId) {
        delete book;
        throw ValidationException("You cannot rate your own books!");
    }

    if (!BookStorage::getInstance().hasUserReadBook(userId, book->getId())) {
        delete book;
        throw ValidationException("You can add a rating after you have read the book!");
    }

    BookStorage::getInstance().addBookRating(userId, book->getId(), score_);
    delete book;
}