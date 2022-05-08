#include "user_storage.h"

UserStorage::UserStorage() { }

UserStorage& UserStorage::getInstance() {
	static UserStorage instance;
	return instance;
}

const char* UserStorage::kUsersFilePath = "./users.txt";

void UserStorage::signUp(const char* username, const char* password) {
	std::fstream file(kUsersFilePath, std::ios::in | std::ios::out | std::ios::app);
	if (!file.is_open())
		throw ValidationException("Could not open file!");

	UserModel* readUser = nullptr;
	try {
		while (!isInputEmpty(file)) {
			readUser = UserModel::deserialize(file);
			if (strcmp(username, readUser->getUsername()) == 0) {
				throw ValidationException("User already exists!");
			}
			delete readUser;
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

UserModel* UserStorage::login(const char* username, const char* password) {
	std::ifstream file(kUsersFilePath);

	while (!isInputEmpty(file)) {
		UserModel* model = UserModel::deserializeWithPassword(file);
		if (strcmp(username, model->getUsername()) == 0) {
			if (strcmp(password, model->getPassword()) == 0) {
				return model;
			}
		}
		delete model;
		readUntilNewLine(file);
	}
	file.close();
	throw ValidationException("Invalid user or password");
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
	throw ValidationException("Could not find user!");
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
