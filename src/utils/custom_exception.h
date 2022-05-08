#pragma once

#include <exception>

#include "str_helpers.h"

class ValidationException : public std::exception {
	const char* info_;

public:
	ValidationException();
	ValidationException(const char* info);

	const char* what() const throw ();
};


class InvalidArgumentsException : public ValidationException {
public:
	InvalidArgumentsException();
};