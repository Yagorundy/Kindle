#include "str_helpers.h"

bool isSpace(const char& ch) {
	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v' || ch == '\f';
}

bool isLetter(const char& ch) {
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isDigit(const char& ch) {
	return ch >= '0' && ch <= '9';
}

char toUpper(const char& ch) {
	return (ch >= 'a' && ch <= 'z') ? ch - ('a' - 'A') : ch;
}

void trim(const char* str, size_t& l, size_t& r) {
	while (r > l && isSpace(str[r - 1])) r--;
	while (isSpace(str[l]) && r > l) l++;
}

bool isEmpty(const char* str) {
	if (str == nullptr)
		return true;
	for (size_t i = 0; str[i] != '\0'; i++)
		if (!isSpace(str[i]))
			return false;
	return true;
}

char* substring(const char* str, const size_t& l, const size_t& r) {
	const size_t len = r - l;
	char* result = new char[len + 1];
	result[len] = '\0';
	for (size_t i = 0; i < len; i++)
		result[i] = str[l + i];
	return result;
}
