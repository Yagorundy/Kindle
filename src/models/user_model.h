#pragma once

#include <cstring>
#include <fstream>

#include "../utils/random_id.h"
#include "../utils/file_helpers.h"

class UserModel {
	UserModel();
	UserModel(const unsigned int& id, const char* username, const char* password);

	unsigned int id_;
	char* username_;
	char* password_;

	static UserModel* deserialize(std::istream& is, bool withPassword);

public:
	UserModel(const char* username, const char* password);
	~UserModel();

	unsigned int getId() const;
	const char* getUsername() const;
	const char* getPassword() const;

	friend std::ostream& operator<<(std::ostream& os, const UserModel& model);
	static UserModel* deserialize(std::istream& is);
	static UserModel* deserializeWithPassword(std::istream& is);
};