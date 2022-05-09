#include "view_ratings_command.h"

const char* ViewRatingsCommand::kName = "ratings";

ViewRatingsCommand::ViewRatingsCommand(List<char*>* args)
    : Command(args)
{
    if (args->size() != 1)
        throw InvalidArgumentsException();
}

void ViewRatingsCommand::exec() {
    assertUserIsLoggedIn();

    BookModel* book = BookStorage::getInstance().getBookByTitle((*args_)[0]);
    List<BookRatingModel*>* ratings = BookStorage::getInstance().getBookRatings(book->getId());

    if (ratings->size() == 0) {
        delete book;
        delete ratings;
        std::cout << "Book has no comments!\n";
        return;
    }

    List<unsigned int> userIds(ratings->size());
    for (size_t i = 0; i < ratings->size(); i++) {
        userIds.add((*ratings)[i]->getUserId());
    }
    List<UserModel*>* users = UserStorage::getInstance().getUsers(userIds);

    for (size_t i = 0; i < ratings->size(); i++) {
        BookRatingModel* rating = (*ratings)[i];

        UserModel* user = nullptr;
        for (size_t j = 0; j < users->size(); j++) {
            UserModel* currUser = (*users)[j];
            if (currUser->getId() == rating->getUserId()) {
                user = currUser;
                break;
            }
        }

        std::cout << "\t" << user->getUsername() << " rated " << rating->getScore() << " stars!\n";
    }

    delete book;
    delete ratings;
    delete users;
}
