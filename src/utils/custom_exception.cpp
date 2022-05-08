#include "custom_exception.h"

ValidationException::ValidationException()
	: ValidationException(nullptr)
{ };

ValidationException::ValidationException(const char* info)
	: info_(info)
{ };

const char* ValidationException::what() const throw () {
	return isEmpty(info_) ? "validation-error" : info_;
}


InvalidArgumentsException::InvalidArgumentsException()
	: ValidationException("Invalid arguments!")
{ };