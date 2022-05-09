#include "write_command.h"

const char* WriteCommand::kName = "write";

WriteCommand::WriteCommand(List<char*>* args)
    : Command(args)
{ }

void WriteCommand::exec() {
    assertUserIsLoggedIn();
    
    const char* title = promptSingleLineInput("Enter title: ");
       
    unsigned int userId = AppState::getInstance().getUserId();
    BookStorage::getInstance().createBook(userId, title);

    std::cout << "Book created! You can add pages using " << '"' << AddPageCommand::kName << '"' << '\n';
    delete[] title;
}
