#include "file_helpers.h"

#include <iostream>

bool isInputEmpty(std::istream& file) {
	auto g = file.tellg();
	file.seekg(std::ios::beg);
	bool isEmpty = file.peek() == std::istream::traits_type::eof();
	file.seekg(g);
	return isEmpty;
}

char* getEmptyString() {
	char* str = new char[1];
	str[0] = '\0';
	return str;
}

bool isEmptyString(const char* str) {
	return str == nullptr || str[0] == '\0';
}

void serializeString(const char* str, std::ostream& file, bool sameLine) {
	file << strlen(str);
	if (sameLine) {
		file << ' ' << str << ' ';
	} else {
		file << '\n' << str << '\n';
	}
}

char* deserializeString(std::istream& file, bool sameLine) {
	if (isInputEmpty(file))
		return getEmptyString();

	unsigned int len;
	file >> len;
	if (!len)
		return getEmptyString();

	if (sameLine) {
		file.seekg(1 + file.tellg());
	}
	else {
		readUntilNewLine(file);
	}
	

	char* str = new char[len + 1];
	file.read(str, len);
	str[len] = '\0';

	file.seekg(1 + file.tellg());
	return str;
}

const int kMaxNewLineBuffSize = 256;
void readUntilNewLine(std::istream& file) {
	char str[kMaxNewLineBuffSize];
	file.getline(str, kMaxNewLineBuffSize);
}