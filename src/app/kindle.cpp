#include "kindle.h"

void Kindle::run() {
	CommandParser command_parser;
	while (true) {
		try {
			auto input = promptSingleLineInput();
			auto command = command_parser.parseCommand(input);
			delete[] input;

			command->exec();
			delete command;
		}
		catch (ValidationException ex) {
			std::cout << ex.what() << '\n';
		}
	}
}
