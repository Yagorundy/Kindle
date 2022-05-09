#include "view_comments_command.h"

const char* ViewCommentsCommand::kName = "comments";

ViewCommentsCommand::ViewCommentsCommand(List<char*>* args)
    : Command(args)
{
    if (args->size() != 1)
        throw InvalidArgumentsException();
}

void ViewCommentsCommand::exec() {
    assertUserIsLoggedIn();

    BookModel* book = BookStorage::getInstance().getBookByTitle((*args_)[0]);
    List<BookCommentModel*>* comments = BookStorage::getInstance().getComments(book->getId());

    if (comments->size() == 0) {
        delete book;
        delete comments;
        std::cout << "Book has no comments!\n";
        return;
    }

    List<unsigned int> userIds(comments->size());
    for (size_t i = 0; i < comments->size(); i++) {
        userIds.add((*comments)[i]->getUserId());
    }
    List<UserModel*>* users = UserStorage::getInstance().getUsers(userIds);

    for (size_t i = 0; i < comments->size(); i++) {
        BookCommentModel* comment = (*comments)[i];

        UserModel* user = nullptr;
        for (size_t j = 0; j < users->size(); j++) {
            UserModel* currUser = (*users)[j];
            if (currUser->getId() == comment->getUserId()) {
                user = currUser;
                break;
            }
        }

        std::cout << "\t" << user->getUsername() << " wrote: " << comment->getContent() << '\n';
    }

    delete book;
    delete comments;
    delete users;
}
