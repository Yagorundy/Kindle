#pragma once

#include <fstream>

#include "../models/user_model.h"
#include "../utils/custom_exception.h"
#include "../utils/list.h"

class UserStorage {
	UserStorage();

	static const char* kUsersFilePath;

public:
	UserStorage(UserStorage const&) = delete;
	void operator=(UserStorage const&) = delete;
	static UserStorage& getInstance();

	void signUp(const char* username, const char* password);
	UserModel* login(const char* username, const char* password);

	UserModel* getUser(const unsigned int& id);
	List<UserModel*>* getUsers(const List<unsigned int>& ids);
};