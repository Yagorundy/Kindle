#pragma once

#include <fstream>

bool isInputEmpty(std::istream& file);

bool isEmptyString(const char* str);

void serializeString(const char* str, std::ostream& file, bool sameLine = true);
char* deserializeString(std::istream& file);

void readUntilNewLine(std::istream& file);