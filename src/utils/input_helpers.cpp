#include "input_helpers.h"

const size_t kMaxInputSize = 1024;

const char* promptSingleLineInput(const char* msg) {
	char* input = new char[kMaxInputSize];
	std::cout << "> ";
	if (msg != nullptr)
		std::cout << msg;
	std::cin.getline(input, kMaxInputSize);
	return input;
}

//const char* promptMultiLineInput(const char* stopKey) {
//
//}