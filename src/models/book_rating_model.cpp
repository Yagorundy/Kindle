#include "book_rating_model.h"

BookRatingModel::BookRatingModel() { }

BookRatingModel::BookRatingModel(const unsigned int& userId, const unsigned int& bookId, const double& score)
	: UserBookModelSingle(userId, bookId), score_(score)
{ }

double BookRatingModel::getScore() const {
	return score_;
}

std::ostream& operator<<(std::ostream& os, const BookRatingModel& model) {
	os << *dynamic_cast<const UserBookModelSingle*>(&model);
	os << model.score_ << ' ';
	return os;
}

std::istream& operator>>(std::istream& is, BookRatingModel* model) {
	is >> dynamic_cast<UserBookModelSingle*>(model);
	is >> model->score_;
	return is;
}

BookRatingModel* BookRatingModel::deserialize(std::istream& is) {
	BookRatingModel* model = new BookRatingModel();
	is >> model;
	return model;
}
