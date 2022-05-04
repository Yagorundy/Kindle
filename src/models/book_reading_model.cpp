#include "book_reading_model.h"

BookReadingModel* BookReadingModel::deserialize(std::istream& is) {
	BookReadingModel* model = new BookReadingModel();
	is >> model;
	return model;
}