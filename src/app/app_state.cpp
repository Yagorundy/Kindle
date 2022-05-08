#include "app_state.h"

AppState::AppState(): userId_(0) { }

AppState& AppState::getInstance() {
	static AppState instance;
	return instance;
}

unsigned int AppState::getUserId() {
	return userId_;
}

void AppState::setUserId(unsigned int userId) {
	userId_ = userId;
}

void AppState::clear() {
	userId_ = 0;
}

bool AppState::isLoggedIn() {
	return userId_ != 0;
}