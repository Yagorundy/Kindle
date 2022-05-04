#include "user_storage.h"

#include <iostream>

const char* UserStorage::kUsersFilePath = "./users.txt";

void UserStorage::signUp(const char* username, const char* password) {
	std::fstream file(kUsersFilePath, std::ios::in | std::ios::out | std::ios::app);
	if (!file.is_open())
		throw CustomExteption("Could not open file!");

	UserModel* readUser = UserModel::deserialize(file);
	try {
		while (!isInputEmpty(file)) {
			UserModel* model = UserModel::deserialize(file);
			if (strcmp(username, model->getUsername()) == 0) {
				file.close();
				delete model;
				throw CustomExteption("User already exists!");
			}
			delete model;
			readUntilNewLine(file);
		}

		UserModel user = UserModel(username, password);
		
		file.clear();
		file.seekg(std::ios::end);
		file.seekp(std::ios::end);
		file << user << '\n';
	}
	catch (...) {
		file.close();
		delete readUser;
		throw;
	}
}

unsigned int UserStorage::signIn(const char* username, const char* password) {
	std::ifstream file(kUsersFilePath);

	while (!isInputEmpty(file)) {
		UserModel* model = UserModel::deserializeWithPassword(file);
		if (strcmp(username, model->getUsername()) == 0) {
			if (strcmp(password, model->getPassword()) == 0) {
				auto id = model->getId();
				delete model;
				return id;
			}
		}
		delete model;
		readUntilNewLine(file);
	}
	file.close();
	throw CustomExteption("Invalid user or password");
}

UserModel* UserStorage::getUser(const unsigned int& id) {
	std::ifstream file(kUsersFilePath);

	while (!isInputEmpty(file)) {
		UserModel* user = UserModel::deserialize(file);
		if (id == user->getId()) {
			file.close();
			return user;
		}
		delete user;
		readUntilNewLine(file);
	}
	file.close();
	throw CustomExteption("Could not find user!");
}

List<UserModel*>* UserStorage::getUsers(const List<unsigned int>& ids) {
	std::ifstream file(kUsersFilePath);

	List<UserModel*>* list = new List<UserModel*>;
	while (!isInputEmpty(file)) {
		UserModel* user = UserModel::deserialize(file);
		bool added = false;
		for (size_t i = 0; i < ids.size(); i++) {
			if (ids[i] == user->getId()) {
				list->add(user);
				added = true;
				break;
			}
		}
		if (!added) {
			delete user;
		}
		readUntilNewLine(file);
	}
	file.close();
	return list;
}
