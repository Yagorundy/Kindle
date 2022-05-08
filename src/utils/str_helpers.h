#pragma once

// similar to std::isspace
bool isSpace(const char& ch);

bool isLetter(const char& ch);

bool isDigit(const char& ch);

char toUpper(const char& ch);

// Moves l and r until they no longer point to a space character
void trim(const char* str, size_t& l, size_t& r);

// Checks if string includes only space characters
bool isEmpty(const char* str);

// Substring method that uses l and r instead of offset and len
char* substring(const char* str, const size_t& l, const size_t& r);
