#pragma once

#include <fstream>

#include "../models/user_model.h"
#include "../utils/custom_exception.h"
#include "../utils/list.h"

class UserStorage {
	static const char* kUsersFilePath;

public:
	void signUp(const char* username, const char* password);
	unsigned int signIn(const char* username, const char* password);

	UserModel* getUser(const unsigned int& id);
	List<UserModel*>* getUsers(const List<unsigned int>& ids);
};