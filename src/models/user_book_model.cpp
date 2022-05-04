#include "user_book_model.h"

//
// single
//
UserBookModelSingle::UserBookModelSingle() { }

UserBookModelSingle::UserBookModelSingle(const unsigned int& userId, const unsigned int& bookId)
	: userId_(userId), bookId_(bookId)
{ }

unsigned int UserBookModelSingle::getUserId() const {
	return userId_;
}

unsigned int UserBookModelSingle::getBookId() const {
	return bookId_;
}

std::ostream& operator<<(std::ostream& os, const UserBookModelSingle& model) {
	os << model.userId_ << ' '
		<< model.bookId_ << ' ';
	return os;
}

std::istream& operator>>(std::istream& is, UserBookModelSingle* model) {
	is >> model->userId_ >> model->bookId_;
	return is;
}

UserBookModelSingle* UserBookModelSingle::deserialize(std::istream& is) {
	UserBookModelSingle* model = new UserBookModelSingle();
	is >> model;
	return model;
}


//
// repeatable
//
UserBookModelRepeatable::UserBookModelRepeatable() { }

UserBookModelRepeatable::UserBookModelRepeatable(const unsigned int& id, const unsigned int& userId, const unsigned int& bookId)
	: id_(id), UserBookModelSingle(userId, bookId)
{ }

UserBookModelRepeatable::UserBookModelRepeatable(const unsigned int& userId, const unsigned int& bookId)
	: UserBookModelRepeatable(generateRandomId(), userId, bookId)
{ }

unsigned int UserBookModelRepeatable::getId() const {
	return id_;
}

std::ostream& operator<<(std::ostream& os, const UserBookModelRepeatable& model) {
	os << model.id_ << ' ';
	os << *dynamic_cast<const UserBookModelSingle*>(&model);
	return os;
}

std::istream& operator>>(std::istream& is, UserBookModelRepeatable* model) {
	is >> model->id_;
	is >> dynamic_cast<UserBookModelSingle*>(model);
	return is;
}

UserBookModelRepeatable* UserBookModelRepeatable::deserialize(std::istream& is) {
	UserBookModelRepeatable* model = new UserBookModelRepeatable();
	is >> model;
	return model;
}
