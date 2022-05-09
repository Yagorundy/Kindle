#include "command_parser.h"

Command* CommandParser::parseCommand(const char* input) {
	size_t l = 0, r = strlen(input);
	trim(input, l, r);

	char* name = nullptr;
	List<char*>* args = new List<char*>();
	char last_ch = 0;
	bool is_between_quotes = false;
	for (size_t i = l; i <= r; i++) {		
		char ch = input[i];
		bool is_space = isSpace(ch);
		bool is_quote = ch == '"';
		bool is_last_char_space = isSpace(last_ch);
		bool is_last_char_quote = last_ch == '"';
		bool is_end_of_word = (is_between_quotes && is_quote) || (!is_between_quotes && !is_last_char_quote && !is_last_char_space && is_space);
		if (is_end_of_word || i == r) {
			if (input[i - 1] == '"' && i == r)
				break;
			char* token = substring(input, is_between_quotes ? l + 1 : l, i);
			if (name == nullptr)
				name = token;
			else
				args->add(token);
			is_between_quotes = false;
		}
		else if (!is_between_quotes && is_last_char_space && !is_space) {
			l = i;
			if (is_quote) {
				is_between_quotes = true;
			}
		}
		last_ch = ch;
	}

	//for (int i = 0; i < args->size(); i++) {
	//	std::cout << (*args)[i] << '\n';
	//}

	auto command = Command::create(name, args);
		
	delete[] name;
	return command;
}
