#pragma once

#include "user_book_model.h"

class BookReadingModel : public UserBookModelRepeatable {
public:
	using UserBookModelRepeatable::UserBookModelRepeatable;

	static BookReadingModel* deserialize(std::istream& is);
};