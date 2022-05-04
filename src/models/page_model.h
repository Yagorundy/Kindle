#pragma once

#include <cstring>
#include <fstream>

#include "../utils/file_helpers.h"
#include "../utils/random_id.h"

class PageModel {
	PageModel();
	PageModel(const unsigned int& id, const unsigned int& bookId, const char* content);

	unsigned int id_;
	unsigned int bookId_;
	//unsigned int number_;
	char* content_;

public:
	PageModel(const unsigned int& bookId, const char* content);
	~PageModel();
	
	unsigned int getId() const;
	unsigned int getBookId() const;
	//unsigned int getNumber() const;
	const char* getContent() const;

	friend std::ostream& operator<<(std::ostream& os, const PageModel& model);
	static PageModel* deserialize(std::istream& is);
};