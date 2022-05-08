#include "book_storage.h"

BookStorage::BookStorage() { }

BookStorage& BookStorage::getInstance() {
	static BookStorage instance;
	return instance;
}

const char* BookStorage::kBooksPath = "./books.txt";
const char* BookStorage::kBookReadingsPath = "./book_readings.txt";
const char* BookStorage::kBookRatingsPath = "./book_reviews.txt";
const char* BookStorage::kBookCommentsPath = "./book_comments.txt";

const char* kBookPagesPathPrefix = "./book_";
const size_t kBookPagesPathPrefixLen = strlen(kBookPagesPathPrefix);
const char* kBookPagesPathSuffix = "_pages.txt";
const size_t kBookPagesPathSuffixLen = strlen(kBookPagesPathSuffix);

const char* BookStorage::getBookPagesPath(unsigned int id) {
	List<int> digitsReversed;
	while (id) {
		digitsReversed.add(id % 10);
		id /= 10;
	}
	auto len = kBookPagesPathPrefixLen + digitsReversed.size() + kBookPagesPathSuffixLen + 1;
	char* path = new char[len];
	strcpy_s(path, kBookPagesPathPrefixLen + 1, kBookPagesPathPrefix);
	for (int i = 0; i < digitsReversed.size(); i++) {
		auto digitNum = digitsReversed[digitsReversed.size() - 1 - i];
		char digitChar = '0' + digitNum;
		path[i + kBookPagesPathPrefixLen] = digitChar;
	}
	for (int i = 0; i < kBookPagesPathSuffixLen; i++) {
		path[i + kBookPagesPathPrefixLen + digitsReversed.size()] = kBookPagesPathSuffix[i];
	}
	path[len - 1] = '\0';
	return path;
}


BookModel* BookStorage::createBook(const unsigned int& userId, const char* title) {
	std::ofstream file(kBooksPath, std::ios::out | std::ios::app);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	BookModel* book = new BookModel(userId, title);
	file << *book << '\n';

	file.close();
	return book;
}

List<BookModel*>* BookStorage::getBooks() {
	std::ifstream file(kBooksPath);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	auto list = new List<BookModel*>();
	while (!isInputEmpty(file)) {
		BookModel* book = BookModel::deserialize(file);
		if (!isEmptyString(book->getTitle())) {
			list->add(book);
		}
		else {
			delete book;
		}
		readUntilNewLine(file);
	}
	return list;
}

BookModel* BookStorage::getBook(const unsigned int& id) {
	std::ifstream file(kBooksPath);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	while (!isInputEmpty(file)) {
		BookModel* book = BookModel::deserialize(file);
		if (book->getId() == id) {
			file.close();
			return book;
		}
		delete book;
		readUntilNewLine(file);
	}
	file.close();
	throw ValidationException("Could not find book!");
}


void BookStorage::createPage(const unsigned int& userId, const unsigned int& bookId, const char* content) {
	BookModel* book = nullptr;
	const char* path = nullptr;
	std::ofstream file;
	try {
		book = getBook(bookId);
		if (book->getAuthorId() != userId)
			throw ValidationException("You cannot add pages to this book!");

		path = getBookPagesPath(bookId);
		file.open(path, std::ios::out | std::ios::app);

		PageModel page = PageModel(bookId, content);
		file << page << "\n";
	}
	catch (...) {
		file.close();
		delete book;
		delete[] path;
		throw;
	}
}

List<PageModel*>* BookStorage::getPages(const unsigned int& bookId) {
	BookModel* book = getBook(bookId);
	delete book;
	
	const char* path = getBookPagesPath(bookId);
	std::ifstream file(path);
	delete[] path;
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	auto list = new List<PageModel*>();
	while (!isInputEmpty(file)) {
		PageModel* page = PageModel::deserialize(file);
		if (!isEmptyString(page->getContent())) {
			list->add(page);
		}
		else {
			delete page;
		}
		readUntilNewLine(file);
	}
	return list;
}


void BookStorage::addBookReading(const unsigned int& userId, const unsigned int& bookId) {
	std::ofstream file(kBookRatingsPath, std::ios::out | std::ios::app);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	BookReadingModel bookReading = BookReadingModel(userId, bookId);
	file << bookReading << '\n';

	file.close();
}

bool BookStorage::hasUserReadBook(const unsigned int& userId, const unsigned int& bookId) {
	std::ifstream file(kBookReadingsPath);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	while (!isInputEmpty(file)) {
		BookReadingModel* bookReading = BookReadingModel::deserialize(file);
		if (bookReading->getUserId() == userId && bookReading->getBookId() == bookId) {
			file.close();
			return true;
		}
		delete bookReading;
		readUntilNewLine(file);
	}
	file.close();
	return false;
}


void BookStorage::addBookRating(const unsigned int& userId, const unsigned int& bookId, const int& score) {
	std::ofstream file(kBookRatingsPath, std::ios::out | std::ios::app);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	BookRatingModel rating = BookRatingModel(userId, bookId, score);
	file << rating << '\n';

	file.close();
}

List<BookRatingModel*>* BookStorage::getBookRatings(unsigned int bookId) {
	std::ifstream file(kBookRatingsPath);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	auto list = new List<BookRatingModel*>();
	while (!isInputEmpty(file)) {
		BookRatingModel* rating = BookRatingModel::deserialize(file);
		if (rating->getBookId() == bookId) {
			list->add(rating);
		}
		else {
			delete rating;
		}
		readUntilNewLine(file);
	}
	return list;
}

void BookStorage::addComment(const unsigned int& userId, const unsigned int& bookId, const char* content) {
	std::ofstream file(kBookCommentsPath, std::ios::out | std::ios::app);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	BookCommentModel comment = BookCommentModel(userId, bookId, content);
	file << comment << '\n';

	file.close();
}

List<BookCommentModel*>* BookStorage::getComments(unsigned int bookId) {
	std::ifstream file(kBookCommentsPath);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	auto list = new List<BookCommentModel*>();
	while (!isInputEmpty(file)) {
		BookCommentModel* comment = BookCommentModel::deserialize(file);
		if (comment->getBookId() == bookId) {
			list->add(comment);
		}
		else {
			delete comment;
		}
		readUntilNewLine(file);
	}
	return list;
}