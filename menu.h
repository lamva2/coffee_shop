#ifndef MENU_H
#define MENU_H

#include "coffee.h"
#include <fstream>
#include <iostream>

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

	/*
	 Name: ~menu (default destructor)
	 Description: Destructs a menu
	*/
	~menu();

	/*
	 Name: menu (copy constructor)
	 Description: Constructs a new menu by copying over data of existing menu
	 Parameters: 
	 	existing_menu (const menu&): a reference to a menu that has already 
			been created
	*/
	menu(const menu& existing_menu);

	/*
	 Name: operator (assignment operator)
	 Description: Changes an existing menu to have the data of another 
		existing menu
	 Parameters: 
	 	other_menu (const menu&): a reference to another menu that has already
			been created
	*/
	void operator=(const menu& other_menu);
    
	/*
	 Name: get_num_coffees (getter)
	 Description: Gets the number of coffees in menu
	 Return (int): number of coffees in menu
	*/
	int get_num_coffees();

	/*
	 Name: set_num_coffees (setter)
	 Description: Sets the number of coffees from file (menu.txt)
	 Return (int): number of coffees in menu
	*/
	int set_num_coffees(std::ifstream& file);
	
	/*
	 Name: get_coffee_name (getter)
	 Description: Gets the name of a coffee in the menu (coffees array)
	 Parameters: 
	 	index (int): index of coffee in coffees array
	 Returns (std::string): coffee name
	*/
	std::string get_coffee_name(int index);

	/*
	 Name: get_small_cost (getter)
	 Description: Gets small cost of a coffee in the menu (coffees array)
	 Parameters: 
	 	index (int): index of coffee in coffees array
	 Returns (double): small cost of coffee
	*/
	double get_small_cost(int index);

	/*
	 Name: get_medium_cost (getter)
	 Description: Gets medium cost of a coffee in the menu (coffees array)
	 Parameters: 
	 	index (int): index of coffee in coffees array
	 Returns (double): medium cost of coffee
	*/
	double get_medium_cost(int index);

	/*
	 Name: get_large_cost (getter)
	 Description: Gets large cost of a coffee in the menu (coffees array)
	 Parameters: 
	 	index (int): index of coffee in coffees array
	 Returns (double): large cost of coffee
	*/
	double get_large_cost(int index);

	/*
	 Name: create_coffee_array
	 Description: Creates a coffee array on the heap. The coffees pointer 
	 	of the menu points to array. Array of size number of coffees in 
		menu.
	*/
	void create_coffee_array();

	/*
	 Name: populate_coffee_array
	 Description: Populates coffee array that coffees pointer points to in
	 	menu with data from file (menu.txt). 
	 Parameters:
	 	file (std::ifstream&): reference to input stream to file (menu.txt)
	*/
	void populate_coffee_array(std::ifstream& file);

	/*
	 Name: print_menu
	 Description: Prints the data from the coffees array (menu) to the terminal
	 	in specific format. 
	*/
	void print_menu();

	/*
	 Name: populate_new_coffee (for Option 2)
	 Description: Populates a new coffee object from information from user.
	 	Sets the name, small cost, medium cost, and large cost of coffee object.
	 Parameters: 
	 	c (coffee& c): coffee object
		name (std::string): coffee name
		small (double): small cost
		medium (double): medium cost
		large (double): large cost
	*/
	void populate_new_coffee(coffee& c, std::string name, double small, double medium, double large);

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

	/*
	 Name: print_drink_options
	 Description: Prints the coffees user can remove (from menu) to terminal
	*/
	void print_drink_options();

	/*
	 Name: remove_coffee
	 Description: Removes a coffee object from the coffees array (menu).
	 Parameters:
	 	coffee_number (int): coffee option user wants to remove
	*/
	void remove_coffee(int coffee_number);

	/*
	 Name: display_coffee_with_name
	 Description: Prints to terminal coffee with name user would like to search up.
	 	If name could not be found, error message printed.
	 Parameters:
	 	name (const std::string &): name of coffee user wishes to search up
	*/
	void display_coffee_with_name(const std::string& name);

	/*
	 Name: display_coffees_with_price
	 Description: Prints to the terminal coffees that meet the user's budget. 
	 	Coffees must be equal to or less than the user's budget. If coffee
		that meets budget cannot be found, error message printed.
	 Parameters:
	 	budget (const double&): user's budget
	*/
	void display_coffees_with_price(const double& budget);

	/* 
	 Name: display_coffee_with_index
	 Description: Prints to terminal coffee at certain index (determined by
	 	subtracted 1 from selection). Information used by user to determine
		order details.
	 Parameters:
		selection (const int&): coffee option user would like to order
	*/
	void display_coffee_with_index(const int& selection);

	/*
	 Name: rewrite_menu
	 Description: Truncates menu.txt through output stream with updated
	 	changes to the coffees array (menu).
	 Parameters:
	 	file (std::ofstream&): reference to output stream to file (menu.txt)
	*/
	void rewrite_menu(std::ofstream& file);
};

#endif
