#include <iostream>
#include "display.h"
#include <fstream>

int main() {
	std::cout << "Welcome to the Coffee++ Cafe!" << std::endl;

	// TODO Construct and initialize a shop object `s`, along with
	// everything inside it, using data from the text files.

	shop s; // Initializes shop object 's'
	int option;
	create_coffees_array(s); // Creates initial menu (coffees array)
	do {
		option = get_option();
		if (option >= 1 && option <= 6) {
			execute_option(s, option);
		} else {
			print_selection_error();
		}
	} while (option != 7);



	return 0;
}
