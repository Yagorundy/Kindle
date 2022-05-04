#include <iostream>

#include "storages/user_storage.h";
#include "storages/book_storage.h"

int main() {
	UserStorage userStorage;
	BookStorage bookStorage;
	
	try {
		//userStorage.signUp("yavor", "test");
		//userStorage.signUp("yavor2", "test2");

		unsigned int id = userStorage.signIn("yavor", "test");
		std::cout << id << '\n';
		BookModel* book = bookStorage.createBook(id, "my_new_book");

		bookStorage.createPage(id, book->getId(), "ooooooo daaaaa");


		auto books = bookStorage.getBooks();
		for (int i = 0; i < books->size(); i++) {
			auto book = (*books)[i];
			std::cout << i + 1 << ' ' << book->getTitle() << '\n';
		}
		std::cout << '\n';

		auto pages = bookStorage.getPages(book->getId());
		for (int i = 0; i < pages->size(); i++) {
			auto page = (*pages)[i];
			std::cout << "page-" << i + 1 << ' ' << page->getContent() << '\n';
		}
		std::cout << '\n';

		delete book;
		delete books;
		delete pages;
	}
	catch (CustomExteption ex) {
		std::cout << ex.what() << '\n';
	}
	
}