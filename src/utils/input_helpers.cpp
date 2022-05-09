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

const char* readMultipleLines() {
	List<char*> inputs;

	size_t len = 0;
	while (true) {
		char* input = new char[kMaxInputSize];
		std::cin.getline(input, kMaxInputSize);

		if (strcmp(input, ":quit") == 0) {
			break;
		}
		else {
			inputs.add(input);
			// +1 for new line
			len += strlen(input) + 1;
		}
	}

	char* result = new char[len + 1];
	result[len] = '\0';
	size_t resultIndex = 0;
	for (size_t i = 0; i < inputs.size(); i++) {
		char* input = inputs[i];
		for (size_t j = 0; j < strlen(input); j++) {
			result[resultIndex++] = input[j];
		}
		result[resultIndex++] = '\n';
		delete[] input;
	}
	
	return result;
}

int promptNumberInput(const char* msg) {
	int num;
	std::cout << "> ";
	if (msg != nullptr)
		std::cout << msg;
	std::cin >> num;
	return num;
}

int parseInt(const char* str) {
	size_t result = 0;
	for (size_t i = 0; str[i] != '\0'; i++) {
		char ch = str[i];
		if (ch < '0' || ch > '9')
			throw ValidationException("Invalid number!");
		result = result * 10;
		result += ch - '0';
	}
	return result;
}

//const char* promptMultiLineInput(const char* stopKey) {
//
//}