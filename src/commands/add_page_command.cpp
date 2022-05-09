#include "add_page_command.h"

const char* AddPageCommand::kName = "addPage";

AddPageCommand::AddPageCommand(List<char*>* args)
    : Command(args)
{
    if (args->size() != 1)
        throw InvalidArgumentsException();
}

void AddPageCommand::exec() {
    assertUserIsLoggedIn();

    unsigned int userId = AppState::getInstance().getUserId();
    BookModel* book = BookStorage::getInstance().getBookByTitle((*args_)[0]);
    if (book->getAuthorId() != userId) {
        delete book;
        throw ValidationException("You cannot edit this book!");
    }

    const char* content = readMultipleLines();
    BookStorage::getInstance().createPage(userId, book->getId(), content);

    delete book;
    delete[] content;
}