#include "page_model.h"

PageModel::PageModel() { }

PageModel::PageModel(const unsigned int& id, const unsigned int& bookId, const char* content)
	: id_(id), bookId_(bookId)//, number_(number)
{
	auto contentLen = strlen(content) + 1;
	content_ = new char[contentLen];
	strcpy_s(content_, contentLen, content);
}

PageModel::PageModel(const unsigned int& bookId, const char* content)
	: PageModel(generateRandomId(), bookId, content)
{ }

PageModel::~PageModel() {
	delete[] content_;
}

unsigned int PageModel::getId() const {
	return id_;
}

unsigned int PageModel::getBookId() const {
	return bookId_;
}

//unsigned int PageModel::getNumber() const {
//	return number_;
//}

const char* PageModel::getContent() const {
	return content_;
}

std::ostream& operator<<(std::ostream& os, const PageModel& model) {
	os << model.id_ << ' '
		<< model.bookId_ << '\n';
		//<< model.number_ << ' ';
	serializeString(model.content_, os, false);
	return os;
}

PageModel* PageModel::deserialize(std::istream& is) {
	PageModel* model = new PageModel();
	is >> model->id_
		>> model->bookId_;
		//>> model->number_;
	model->content_ = deserializeString(is, false);
	return model;
}
