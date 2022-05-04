#pragma once

#include <fstream>

#include "../utils/random_id.h"

//
// single
//
class UserBookModelSingle {
protected:
	UserBookModelSingle();

	unsigned int userId_;
	unsigned int bookId_;

	friend std::istream& operator>>(std::istream& is, UserBookModelSingle* model);

public:
	UserBookModelSingle(const unsigned int& userId, const unsigned int& bookId);

	unsigned int getUserId() const;
	unsigned int getBookId() const;

	friend std::ostream& operator<<(std::ostream& os, const UserBookModelSingle& model);
	static UserBookModelSingle* deserialize(std::istream& is);
};

//
// repeatable
//
class UserBookModelRepeatable : public UserBookModelSingle {
protected:
	UserBookModelRepeatable();
	UserBookModelRepeatable(const unsigned int& id, const unsigned int& userId, const unsigned int& bookId);

	unsigned int id_;

	friend std::istream& operator>>(std::istream& is, UserBookModelRepeatable* model);

public:
	UserBookModelRepeatable(const unsigned int& userId, const unsigned int& bookId);

	unsigned int getId() const;

	friend std::ostream& operator<<(std::ostream& os, const UserBookModelRepeatable& model);
	static UserBookModelRepeatable* deserialize(std::istream& is);
};