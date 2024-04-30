#include <iostream>
#include "display.h"

int main() {
	std::cout << "Welcome to the Coffee++ Cafe!" << std::endl;

	// TODO Construct and initialize a shop object `s`, along with
	// everything inside it, using data from the text files.

	int option;
	do {
		option = get_option();
		if (option >= 1 && option <= 6) {
			execute_option(s, option);
		}
	} while (option != 7);

	return 0;
}
