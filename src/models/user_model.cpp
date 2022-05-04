#include "user_model.h"

UserModel::UserModel() { }

UserModel::UserModel(const unsigned int& id, const char* username, const char* password)
	: id_(id)
{
	auto usernameLen = strlen(username) + 1;
	username_ = new char[usernameLen];
	strcpy_s(username_, usernameLen, username);

	auto passwordLen = strlen(password) + 1;
	password_ = new char[passwordLen];
	strcpy_s(password_, passwordLen, password);
}

UserModel::UserModel(const char* username, const char* password)
	: UserModel(generateRandomId(), username, password)
{ }

UserModel::~UserModel() {
	delete[] username_;
	delete[] password_;
}

unsigned int UserModel::getId() const {
	return id_;
}

const char* UserModel::getUsername() const {
	return username_;
}

const char* UserModel::getPassword() const {
	return password_;
}

std::ostream& operator<<(std::ostream& os, const UserModel& model) {
	os << model.id_ << ' ';
	serializeString(model.username_, os);
	serializeString(model.password_, os);
	return os;
}

UserModel* UserModel::deserialize(std::istream& is, bool withPassword) {
	UserModel* model = new UserModel();
	is >> model->id_;
	model->username_ = deserializeString(is);
	if (withPassword)
		model->password_ = deserializeString(is);
	return model;
}

UserModel* UserModel::deserialize(std::istream& is) {
	return deserialize(is, false);
}

UserModel* UserModel::deserializeWithPassword(std::istream& is) {
	return deserialize(is, true);
}
