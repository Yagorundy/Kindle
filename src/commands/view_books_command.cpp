#include "view_books_command.h"

const char* ViewBooksCommand::kName = "view";

ViewBooksCommand::ViewBooksCommand(List<char*>* args)
    : Command(args)
{ }

void ViewBooksCommand::exec() {
    assertUserIsLoggedIn();
    
    List<BookModel*>* books = BookStorage::getInstance().getBooks();

    List<unsigned int> userIds(books->size());
    for (size_t i = 0; i < books->size(); i++) {
        userIds.add((*books)[i]->getAuthorId());
    }
    List<UserModel*>* users = UserStorage::getInstance().getUsers(userIds);

    for (size_t i = 0; i < books->size(); i++) {
        BookModel* book = (*books)[i];

        UserModel* author = nullptr;
        for (size_t j = 0; j < users->size(); j++) {
            UserModel* currUser = (*users)[j];
            if (currUser->getId() == book->getAuthorId()) {
                author = currUser;
                break;
            }
        }

        std::cout << "\t" << (i + 1) << ". " << (*books)[i]->getTitle() << " by " << author->getUsername() << '\n';
    }

    delete books;
    delete users;
}
