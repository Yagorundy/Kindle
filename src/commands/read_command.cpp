#include "read_command.h"

const char* ReadCommand::kName = "read";

ReadCommand::ReadCommand(List<char*>* args)
    : Command(args)
{
    if (args->size() != 1)
        throw InvalidArgumentsException();
}

void ReadCommand::exec() {
    assertUserIsLoggedIn();

    BookModel* book = BookStorage::getInstance().getBookByTitle((*args_)[0]);

    unsigned int userId = AppState::getInstance().getUserId();
    BookStorage::getInstance().addBookReading(userId, book->getId());

    List<PageModel*>* pages = BookStorage::getInstance().getPages(book->getId());
    
    if (pages->size() == 0) {
        std::cout << "Book has no content!\n";
        delete book;
        delete pages;
        return;
    }

    size_t index = 0;
    while (true) {
        std::cout << (*pages)[index]->getContent() << '\n';

        const char* input = promptSingleLineInput("(n,p,q): ");

        if (strcmp(input, "n") == 0) {
            if (index < pages->size() - 1) {
                index++;
            }
        }
        else if (strcmp(input, "p") == 0) {
            if (index > 0) {
                index--;
            }
        }
        else if (strcmp(input, "q") == 0) {
            break;
        }
        else {
            std::cout << "Invalid command!\n";
        }
    }

    delete book;
    delete pages;
}