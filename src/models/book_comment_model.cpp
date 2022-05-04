#include "book_comment_model.h"

BookCommentModel::BookCommentModel() { }

BookCommentModel::BookCommentModel(const unsigned int& userId, const unsigned int& bookId, const char* content)
	: UserBookModelRepeatable(userId, bookId)
{
	auto contentLen = strlen(content) + 1;
	content_ = new char[contentLen];
	strcpy_s(content_, contentLen, content);
}

const char* BookCommentModel::getContent() const {
	return content_;
}

std::ostream& operator<<(std::ostream& os, const BookCommentModel& model) {
	os << *dynamic_cast<const UserBookModelSingle*>(&model);
	serializeString(model.content_, os);
	return os;
}

std::istream& operator>>(std::istream& is, BookCommentModel* model) {
	is >> dynamic_cast<UserBookModelSingle*>(model);
	model->content_ = deserializeString(is);
	return is;
}

BookCommentModel* BookCommentModel::deserialize(std::istream& is) {
	BookCommentModel* model = new BookCommentModel();
	is >> model;
	return model;
}
