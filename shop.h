#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>

#include "menu.h"
#include "order.h"

class shop {
private:
	menu m; // Menu of shop

	std::string phone; // Phone number of shop
	std::string address; // Address of shop
	double revenue = 0; // Revenue of shop

	int num_orders = 0; // Number of orders

	// Base address of order array (nullptr if array is empty)
	order* orders = nullptr;
public:
	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `shop.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: shop (default constructor)
	 * Description: Constructs a shop with a defaultly-constructed menu,
	 *		an empty phone number and address, 0 revenue, and no orders.
	 */
	shop();

	/*
	 Name: ~shop (default destructor)
	 Description: Destructs a shop object
	*/
	~shop();

	/*
	 Name: shop (copy constructor)
	 Description: Constructs a new shop by copying over data of existing shop
	 Parameters: 
	 	existing_shop (const shop&): a reference to a shop that has already 
			been created
	*/
	shop(const shop& existing_shop);

	/*
	 Name: operator= (assignment operator overload)
	 Description: Changes an existing shop to have the data of another 
		existing shop (deep copy)
	 Parameters: 
	 	other_shop (const shop&): a reference to another shop that has already
			been created
	*/
	void operator=(const shop& other_shop);

	/*
	 Name: set_num_coffees
	 Description: Sets the number of coffees in the shop from information
	 	from file (menu.txt)
	 Parameters:
	 	file (std::ifstream&): reference to input stream to file (menu.txt)
	*/
	void set_num_coffees(std::ifstream& file);

	/*
	 Name: coffee_array
	 Description: Creates and populates initial coffees array on the heap.
	 Parameters:
	 	file (std::ifstream&): reference to input stream to file (menu.txt)
	*/
	void coffee_array(std::ifstream& file);

	/*
	 Name: orders_array
	 Description: Creates initial order array and points orders pointer in shop
	 	to it. Initially of size 0.
	*/
	void orders_array();

	/*
	 Name: print_menu
	 Description: Prints menu from coffees array to terminal.
	*/
	void print_menu();

	/*
	 Name: option_2
	 Description: Populates a new coffee object with information from the user
	 	for option 2 (add a coffee to menu).
	 Parameters:
	 	c (coffee&): reference to a coffee object
		name (std::string): name of coffee
		small (double): small cost of coffee
		medium (double): medium cost of coffee
		large (double): large cost of coffee
	*/
	void option_2(coffee& c, std::string name, double small, double medium, double large);

	/*
	 Name: get_user_selection
	 Description: Prompts user for the drink they would like to remove 
	 	(option 3). Error handles if user inputs invalid value.
	*/
	int get_user_selection();

	/*
	 Name: print_drink_options
	 Description: Prints the drink options from the menu (coffees array) in
		specific format.
	*/
	void print_drink_options();

	/*
	 Name: remove_coffee_from_array
	 Description: Removes the coffee user selected from the menu (coffees array)
	 Parameters:
	 	user_input (int): drink option user wishes to remove
	*/
	void remove_coffee_from_array(int user_input);

	/*
	 Name: option_4
	 Description: Displays coffee information with name that user inputs
	 	to the terminal
	 Parameters: 
	 	name (const std::string& name): reference to name user wants to search 
			up
	*/
	void option_4(const std::string& name);

	/*
	 Name: option_5
	 Description: Displays coffees that meet the budget that the user
	 	inputs to the terminal
	 Parameters: 
	 	budget (const double&): reference to budget user inputs
	*/
	void option_5(const double& budget);

	/*
	 Name: option_6
	 Description: Displays information about the coffee the user would like to 
	 	order to the terminal from the menu (coffees array)
	 Parameters:
	 	selection (const int&): reference to drink number user selected
	*/
	void option_6(const int& selection);

	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `shop.cpp`. THIS FUNCTION IS USED
	 *		BY THE BIG 3 TESTING SCRIPT.
	 * Name: add_coffee_to_menu
	 * Description: Adds a coffee to the shop's menu
	 * Parameters:
	 *		c (const coffee&): The coffee to add to the shop's menu
	 * Post conditions: Coffee added to menu
	 */
	void add_coffee_to_menu(const coffee& c);

	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `shop.cpp`. THIS FUNCTION IS USED
	 *		BY THE BIG 3 TESTING SCRIPT.
	 * Name: add_order
	 * Description: Adds an order to the order array
	 * Parameters:
	 *		o (const order&): The order to add to the array
	 * Post conditions: Order added to array (array may need to be
	 *		reallocated, and num_orders should be incremented by 1)
	 */
	void add_order(const order& o);

	/*
	 * Name: populate_from_file
	 * Description: Reads address and phone number of shop from file and
	 * 		prints to terminal.
	 * Parameters:
	 *		file (std::ifstream&): Reference to input file stream to file.
	 */
	void populate_shop_from_file(std::ifstream& file);

	/*
	 Name: print_revenue
	 Description: Prints the revenue of the shop that is calculated from
	 	the orders array
	*/
	void print_revenue();

	/*
	 Name: print_orders
	 Description: Prints the orders from the order array to the terminal
	*/
	void print_orders();

	/*
	 Name: populate_new_order
	 Description: Populates a new order object with information given by the 
	 	user
	 Parameters: 
	 	o (order&): reference to an order object
		selection (int): drink option user chose
		coffee_size (char): size of coffee user orders
		quantity (int): quantity of coffees user orders
	*/
	void populate_new_order(order& o, int selection, char coffee_size, 
		int quantity);

	/*
	 Name: calculate_order_cost
	 Description: Calculates the total cost of an order with data from order 
	 	array
	 Parameters: 
	 	o (order&): reference to an order object
	*/
	double calculate_order_cost(order& o);

	/*
	 Name: print_order_message
	 Description: Prints message that order has been placed and the order number
	 Parameters:
	 	o (order&): reference to an order object
	*/
	void print_order_message(order& o);

	/*
	 Name: write_orders_to_file
	 Description: 
	 Parameters: 
	*/
	void write_orders_to_file(std::ofstream& file);
	void write_to_files(std::ofstream& menu_file, std::ofstream& orders_file);

};

#endif
