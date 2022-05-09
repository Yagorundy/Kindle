#pragma once

#include <iostream>

#include "custom_exception.h"
#include "list.h"

const char* promptSingleLineInput(const char* msg = nullptr);

const char* readMultipleLines();

int promptNumberInput(const char* msg = nullptr);

int parseInt(const char* str);

//const char* promptMultiLineInput(const char* stopKey);