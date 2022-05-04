#pragma once

#include <exception>

class CustomExteption : public std::exception {
public:
	CustomExteption(const char* msg)
		: std::exception(msg)
	{ }
};