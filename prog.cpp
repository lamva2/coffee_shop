/*
 Author: Valerie Lam
 Description: C++ program that will simulate the basic functionalities of a 
 	coffee shop. Utilize classes, the Big 3, member functions, and implement
	information hiding and encapsulation.
*/

#include <iostream>
#include "display.h"
#include <fstream>

int main() {
	std::cout << "Welcome to the Coffee++ Cafe!" << std::endl;

	shop s; // Initializes shop object 's' and call constructor
	int option; // intialize option for user to select
	create_coffees_array(s); // Creates initial menu (coffees array)
	do {
		option = get_option(); // Get user option
		if (option >= 1 && option <= 6) {
			// Execute options for specific shop object
			execute_option(s, option);
		} 
	} while (option != 7);
	// Create output streams and write coffees array and orders array
	// to files (menu.txt and orders.txt)
	create_output_streams(s);


	return 0;
}
