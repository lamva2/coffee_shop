#include <iostream>
#include "display.h"

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

void option_2_prompts(const shop& s, std::string name, double small_cost, double medium_cost, double large_cost) {
	std::cout << "Enter the name of the new coffee drink (in 1 word): ";
	std::cin >> name;
	std::cout << "Enter price of small size (8oz): ";
	std::cin >> small_cost;
	std::cout << "Enter price of medium size (12oz): ";
	std::cin >> medium_cost;
	std::cout << "Enter price of large size (16oz): ";
	std::cin >> large_cost;
} 


void execute_option(shop& s, int option) {
	if (option == 1) {
		// Access shop_info.txt and reads shop information
		std::ifstream populate_shop_from_file_stream;
		populate_shop_from_file_stream.open("shop_info.txt");
		s.populate_shop_from_file(populate_shop_from_file_stream);
	} else if (option == 2) {
		// Initialize variables that user will input
		std::string name;
		double small_cost, medium_cost, large_cost;
		// Create stream to menu.txt file
		std::ifstream stream_to_menu;
    	stream_to_menu.open("menu.txt");
		// Prompt the user for new coffee information
		option_2_prompts(s, name, small_cost, medium_cost, large_cost);
		// Create a new coffee object
		coffee c;
		menu m; // use constructor to make this when making shop object!!!
		// Creates & populates coffees array, and adds new coffee to array
		s.option_2(m, c, stream_to_menu, name, small_cost, medium_cost, large_cost);
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
