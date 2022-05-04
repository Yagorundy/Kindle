#pragma once

#include "user_book_model.h"

class BookRatingModel : public UserBookModelSingle {
protected:
	BookRatingModel();

	double score_;

	friend std::istream& operator>>(std::istream& is, BookRatingModel* model);

public:
	BookRatingModel(const unsigned int& userId, const unsigned int& bookId, const double& score);

	double getScore() const;

	friend std::ostream& operator<<(std::ostream& os, const BookRatingModel& model);
	static BookRatingModel* deserialize(std::istream& is);
};