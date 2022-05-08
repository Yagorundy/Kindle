#include <iostream>

#include "app/kindle.h"
#include "utils/custom_exception.h"

int main() {
	try {
		Kindle app;
		app.run();
	}
	//catch (const ValidationException& ex) {
	//	std::cout << ex.what();
	//}
	catch (const std::exception& ex) {
		std::cout << "An unexpected error occured! Details: " << ex.what();
	}

	//try {
	//	//userStorage.signUp("yavor", "test");
	//	//userStorage.signUp("yavor2", "test2");

	//	unsigned int id = UserStorage::getInstance().signIn("yavor", "test");
	//	std::cout << id << '\n';
	//	BookModel* book = BookStorage::getInstance().createBook(id, "my_new_book");

	//	BookStorage::getInstance().createPage(id, book->getId(), "ooooooo daaaaa");


	//	auto books = BookStorage::getInstance().getBooks();
	//	for (int i = 0; i < books->size(); i++) {
	//		auto book = (*books)[i];
	//		std::cout << i + 1 << ' ' << book->getTitle() << '\n';
	//	}
	//	std::cout << '\n';

	//	auto pages = BookStorage::getInstance().getPages(book->getId());
	//	for (int i = 0; i < pages->size(); i++) {
	//		auto page = (*pages)[i];
	//		std::cout << "page-" << i + 1 << ' ' << page->getContent() << '\n';
	//	}
	//	std::cout << '\n';

	//	delete book;
	//	delete books;
	//	delete pages;
	//}
	//catch (CustomException ex) {
	//	std::cout << ex.what() << '\n';
	//}
	
}