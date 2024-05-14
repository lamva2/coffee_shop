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

	// TODO Construct and initialize a shop object `s`, along with
	// everything inside it, using data from the text files.

	shop s; // Initializes shop object 's'
	int option;
	create_coffees_array(s); // Creates initial menu (coffees array)
	do {
		option = get_option();
		if (option >= 1 && option <= 6) {
			execute_option(s, option);
		} 
	} while (option != 7);

	create_output_streams(s);


	return 0;
}
