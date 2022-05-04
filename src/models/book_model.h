#pragma once

#include <cstring>
#include <fstream>

#include "../utils/random_id.h"
#include "../utils/file_helpers.h"

class BookModel {
	BookModel();

	unsigned int id_;
	unsigned int authorId_;
	char* title_;

public:
	BookModel(const unsigned int& authorId, const char* title);
	BookModel(const unsigned int& id, const unsigned int& authorId, const char* title);
	~BookModel();

	unsigned int getId() const;
	unsigned int getAuthorId() const;
	const char* getTitle() const;

	friend std::ostream& operator<<(std::ostream& os, const BookModel& model);
	static BookModel* deserialize(std::istream& is);
};
