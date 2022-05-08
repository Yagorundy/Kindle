#pragma once

#include "../models/book_model.h"
#include "../models/page_model.h"
#include "../models/book_reading_model.h"
#include "../models/book_rating_model.h"
#include "../models/book_comment_model.h"
#include "../utils/list.h"

class BookStorage {
	BookStorage();

	static const char* kBooksPath;
	static const char* kBookReadingsPath;
	static const char* kBookRatingsPath;
	static const char* kBookCommentsPath;
	const char* getBookPagesPath(unsigned int id);

public:
	BookStorage(BookStorage const&) = delete;
	void operator=(BookStorage const&) = delete;
	static BookStorage& getInstance();

	BookModel* createBook(const unsigned int& userId, const char* title);
	List<BookModel*>* getBooks();
	BookModel* getBook(const unsigned int& id);

	void createPage(const unsigned int& userId, const unsigned int& bookId, const char* content);
	List<PageModel*>* getPages(const unsigned int& bookId);

	void addBookReading(const unsigned int& userId, const unsigned int& bookId);
	bool hasUserReadBook(const unsigned int& userId, const unsigned int& bookId);

	void addBookRating(const unsigned int& userId, const unsigned int& bookId, const int& rating);
	List<BookRatingModel*>* getBookRatings(unsigned int bookId);

	void addComment(const unsigned int& userId, const unsigned int& bookId, const char* comment);
	List<BookCommentModel*>* getComments(unsigned int bookId);
};
