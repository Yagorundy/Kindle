#include "command_parser.h"

Command* CommandParser::parseCommand(const char* input) {
	size_t l = 0, r = strlen(input);
	trim(input, l, r);

	char* name = nullptr;
	List<char*>* args = new List<char*>();
	bool is_last_char_space = false;
	for (size_t i = l; i <= r; i++) {
		bool is_space = isSpace(input[i]);
		if ((!is_last_char_space && is_space) || i == r) {
			char* token = substring(input, l, i);
			if (name == nullptr)
				name = token;
			else
				args->add(token);
		}
		else if (is_last_char_space && !is_space) {
			l = i;
		}
		is_last_char_space = is_space;
	}

	auto command = Command::create(name, args);
		
	delete[] name;
	return command;
}
