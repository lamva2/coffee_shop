#include <iostream>
#include "display.h"
#include <string>

void print_options() {
	// Prints different options for user to choose to terminal
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
	// Prints error message for invalid selection
	std::cout << "Error: You must choose one of the 7 options provided"
		<< std::endl;
}

int get_option() {
	int option;
	bool first = true;
	// Do while loop until user inputs valid selection
	do {
		if (!first) {
			// Prints error selection selections after first
			// prompt
			print_selection_error();
		}
		first = false; // set first to false
		print_options(); // Print options
		std::cout << "Selection: ";
		std::cin >> option;
	} while (option < 1 || option > 7);
	// Return user's option
	return option;
}

void option_2_prompts(std::string& name, double& small_cost, double& medium_cost, double& large_cost) {
	std::cout << std::endl;
	// Prompt for name of coffee drink
	std::cout << "Enter the name of the new coffee drink (in 1 word): ";
	std::cin >> name;
	do {
		// Prompt for small cost
		std::cout << "Enter price of small size (8oz): ";
		std::cin >> small_cost;
		if (small_cost > 0) {
			// Break out of loop if input is valid
			break;
		} else {
			// Print error message if input is invalid. Continue loop
			std::cout << "Not a valid price. Please re-enter price." << std::endl;
		}
	} while (true);
	do {
		// Prompt for medium cost
		std::cout << "Enter price of medium size (12oz): ";
		std::cin >> medium_cost;
		if (medium_cost > 0) {
			// Break out of loop if input is valid
			break;
		} else {
			// Print error message if input is invalid. Continue loop
			std::cout << "Not a valid price. Please re-enter price." << std::endl;
		}
	} while (true);
	do {
		// Prompt for large cost
		std::cout << "Enter price of large size (16oz): ";
		std::cin >> large_cost;
		if (large_cost > 0) {
			// Break out of loop if input is valid
			break;
		} else {
			// Print error message if input is invalid. Continue loop
			std::cout << "Not a valid price. Please re-enter price." << std::endl;
		}
	} while (true);
} 

std::string option_4_prompts() {
	// Prompt for coffee name
	std::cout << std::endl;
	std::string name;
	std::cout << "Enter the coffee name: ";
	std::cin >> name;
	// Return coffee name
	return name;
}

double option_5_prompts() {
	// Prompt for budget
	std::cout << std::endl;
	double budget;
	std::cout << "Enter your budget for 1 drink, and I will list out our " 
		<< "products that are cheaper or equal to your budget: ";
	std::cin >> budget;
	std::cout << std::endl;
	// Return budget
	return budget;
}

int option_6_prompt_for_selection() {
	int selection;
	// Prompt for the drink selection user would like to order
	std::cout << "Which of the drinks above would you like to order? Enter here: ";
	std::cin >> selection;
	// Return drink selection
	return selection;
}

char option_6_prompt_for_size() {
	char size;
	do {
		// Prompt for size of drink user would like to order
		std::cout << "Enter the size: S-small, M-medium, L-large: ";
		std::cin >> size;
		if (size == 'S' | size == 'M' | size == 'L') {
			// If valid size, break out of loop
			break;
		} else {
			// If invalid size, print error message and loop continues
			std::cout << "Not a valid size. Please re-eneter size." << std::endl;
		}
	} while (true);
	// Return size of drink order
	return size;
}

int option_6_prompt_for_quantity() {
	int quantity;
	std::cout << "Enter quantity: ";
	std::cin >> quantity;
	return quantity;
}

// Creates coffees array
void create_coffees_array(shop& s) {
	// Create input stream to menu.txt file
	std::ifstream input_stream_to_menu;
    input_stream_to_menu.open("menu.txt");
	// Sets number of coffees variable in menu
	s.set_num_coffees(input_stream_to_menu);
	// Creates and populates initial coffees array
	s.coffee_array(input_stream_to_menu);
}

void execute_option(shop& s, int option) {
	if (option == 1) {
		// Access shop_info.txt and reads shop information
		std::ifstream populate_shop_from_file_stream;
		populate_shop_from_file_stream.open("shop_info.txt");
		// Populate shop with information from file
		s.populate_shop_from_file(populate_shop_from_file_stream);
		// Print revenue of shop
		s.print_revenue();
		std::cout << std::endl;
		// Print menu of shop
		s.print_menu();
		std::cout << std::endl;
		// Print orders of shop
		s.print_orders();
	} else if (option == 2) {
		// Initialize variables that user will input
		std::string name;
		double small_cost, medium_cost, large_cost;
		// Prompt the user for new coffee information
		option_2_prompts(name, small_cost, medium_cost, large_cost);
		// Create a new coffee object
		coffee c;
		// Populates new coffee object with information from user
		s.option_2(c, name, small_cost, medium_cost, large_cost);
		// Adds new coffee object to coffees array (menu)
		s.add_coffee_to_menu(c);
		// Prints message that new drink has been added to menu
		std::cout << "This new drink has been successfully added to the coffee menu!" << std::endl;
		std::cout << std::endl;
	} else if (option == 3) {
		std::cout << std::endl;
		// Prints menu (drink options) to terminal
		s.print_drink_options();
		std::cout << std::endl;
		// Get user selection for drink to remove
		int user_selection = s.get_user_selection();
		// Removes user_selection from menu;
		s.remove_coffee_from_array(user_selection);
		std::cout << "This drink has been successfully removed from the coffee menu!" << std::endl;
		std::cout << std::endl;
		// TODO Guide user through removing a coffee from the menu
	} else if (option == 4) {
		// Prompt for coffee name to search
		std::string coffee_name = option_4_prompts();
		std::cout << std::endl;
		// Prints information about the coffee selected
		s.option_4(coffee_name);
		std::cout << std::endl;
	} else if (option == 5) {
		double budget = option_5_prompts(); // Prompt for budget to search
		s.option_5(budget); // Prints drinks that meet budget requirements
	} else if (option == 6) {
		std::cout << std::endl;
		s.print_drink_options(); // Prints menu (drink options)
		std::cout << std::endl;
		int selection = option_6_prompt_for_selection(); // Prompt for drink number to search
		s.option_6(selection); // Prints information about specific drink 
		char size = option_6_prompt_for_size(); // Prompt for drink size
		char quantity = option_6_prompt_for_quantity(); // Prompt for quantity
		order o; // Creates new order object
		// Populates order object with data from user
		s.populate_new_order(o, selection, size, quantity);
		s.add_order(o); // Add order to orders array
		double total_cost = s.calculate_order_cost(o); // Calculates total cost of order
		// Prints total cost of order
		std::cout << "Your total cost is: " << "$" << total_cost << std::endl;
		// Print order message 
		s.print_order_message(o);
	}
}

// Creates ouput streams to files (menu.txt and orders.txt)
void create_output_streams(shop& s) {
	// Create output stream to menu.txt file
	std::ofstream stream_to_menu;
    stream_to_menu.open("menu.txt");
	// Create output stream to orders.txt file
	std::ofstream stream_to_orders;
	stream_to_orders.open("orders.txt");
	// Rewrite files
	s.write_to_files(stream_to_menu, stream_to_orders);
}
