#include <iostream>
#include "display.h"

/*
 * THIS IS A SUGGESTED FUNCTION.
 * Name: print_options()
 * Description: Print options to the user
 */
void print_options() {
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "	1. View shop info" << std::endl;
	std::cout << "	2. Add an item to menu" << std::endl;
	std::cout << "	3. Remove an item from menu" << std::endl;
	std::cout << "	4. Search by coffee name" << std::endl;
	std::cout << "	5. Search by price" << std::endl;
	std::cout << "	6. Place an order" << std::endl;
	std::cout << "	7. Log out" << std::endl;
}

/*
 * THIS IS A SUGGESTED FUNCTION.
 * Name: print_selection_error
 * Description: Scolds the user for selecting a bad option
 *		number
 */
void print_selection_error() {
	std::cout << "Error: You must choose one of the 7 options provided"
		<< std::endl;
}

int get_option() {
	int option;
	bool first = true;
	do {
		if (!first) {
			print_selection_error();
		}
		first = false;
		print_options();
		std::cout << "Selection: ";
		std::cin >> option;
	} while (option < 1 || option > 7);

	return option;
}

void execute_option(shop& s, int option) {
	if (option == 1) {
		// TODO Display shop info
	} else if (option == 2) {
		// TODO Guide user through adding a coffee to the menu
	} else if (option == 3) {
		// TODO Guide user through removing a coffee from the menu
	} else if (option == 4) {
		// TODO Guide user through searching the menu by coffee name
	} else if (option == 5) {
		// TODO Guide user through searching the menu by coffee price
	} else if (option == 6) {
		// TODO Guide user through placing an order
	}
}
