#pragma once

class AppState {
	AppState();

	unsigned int userId_;

public:
	AppState(AppState const&) = delete;
	void operator=(AppState const&) = delete;
	static AppState& getInstance();

	unsigned int getUserId();
	void setUserId(unsigned int userId);
	void clear();
	bool isLoggedIn();
};