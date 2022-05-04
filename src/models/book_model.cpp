#include "book_model.h"

BookModel::BookModel() { }

BookModel::BookModel(const unsigned int& id, const unsigned int& authorId, const char* title)
	: id_(id), authorId_(authorId)
{
	auto titleLen = strlen(title) + 1;
	title_ = new char[titleLen];
	strcpy_s(title_, titleLen, title);
}

BookModel::BookModel(const unsigned int& authorId, const char* title)
	: BookModel(generateRandomId(), authorId, title)
{ }

BookModel::~BookModel() {
	delete[] title_;
}

unsigned int BookModel::getId() const {
	return id_;
}

unsigned int BookModel::getAuthorId() const {
	return authorId_;
}

const char* BookModel::getTitle() const {
	return title_;
}

std::ostream& operator<<(std::ostream& os, const BookModel& model) {
	os << model.id_ << ' '
		<< model.authorId_ << ' ';
	serializeString(model.title_, os);
	return os;
}

BookModel* BookModel::deserialize(std::istream& is) {
	BookModel* model = new BookModel();
	is >> model->id_
		>> model->authorId_;
	model->title_ = deserializeString(is);
	return model;
}
