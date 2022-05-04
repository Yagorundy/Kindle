#pragma once

#include "user_book_model.h"
#include "../utils/file_helpers.h"

class BookCommentModel : public UserBookModelRepeatable {
protected:
	BookCommentModel();

	char* content_;

	friend std::istream& operator>>(std::istream& is, BookCommentModel* model);

public:
	BookCommentModel(const unsigned int& userId, const unsigned int& bookId, const char* content);

	const char* getContent() const;

	friend std::ostream& operator<<(std::ostream& os, const BookCommentModel& model);
	static BookCommentModel* deserialize(std::istream& is);
};