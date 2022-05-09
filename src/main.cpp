#include <iostream>

#include "app/kindle.h"
#include "utils/custom_exception.h"

int main() {
	try {
		Kindle app;
		app.run();
	}
	//catch (const ValidationException& ex) {
	//	std::cout << ex.what();
	//}
	catch (const std::exception& ex) {
		std::cout << "An unexpected error occured! Details: " << ex.what();
	}
}