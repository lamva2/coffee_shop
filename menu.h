#ifndef MENU_H
#define MENU_H

#include "coffee.h"

class menu {
private:
	// Number of coffees in menu
	int num_coffees = 0;

	// Base address of coffee array (nullptr if array is empty)
	coffee* coffees = nullptr;
public:
	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `menu.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: menu (default constructor)
	 * Description: Constructs a menu with an empty coffee array
	 */
	menu();

	// Deconstructor for coffees
	~menu();

	// returns number of coffees
	int get_num_coffees();
	// Sets the number of coffees from file
	int set_num_coffees(std::ifstream& file);
	// returns name of coffee
	std::string get_coffee_name(int index);
	double get_small_cost(int index);
	double get_medium_cost(int index);
	double get_large_cost(int index);

	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `menu.cpp`. THIS FUNCTION IS USED
	 *		BY THE BIG 3 TESTING SCRIPT.
	 * Name: add_coffee
	 * Description: Adds a coffee to the coffee array
	 * Parameters:
	 *		c (const coffee&): The coffee to add to the array
	 * Post conditions: Coffee added to array (array may need to be
	 *		reallocated, and num_coffees should be incremented by 1)
	 */
	void add_coffee(const coffee& c);

	void create_coffee_array();
	void populate_coffee_array(std::ifstream& file);
	void print_menu();
	void populate_new_coffee(coffee& c, std::string name, double small, double medium, double large);
	void remove_coffee(int coffee_number);
	void print_drink_options();
	void display_coffee_with_name(const std::string& name);
	void display_coffees_with_price(const double& budget);
	void display_coffee_with_index(const int& selection);

	void rewrite_menu(std::ofstream& file);
};

#endif
