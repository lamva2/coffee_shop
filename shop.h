#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>

#include "menu.h"
#include "order.h"

class shop {
private:
	menu m;

	std::string phone;
	std::string address;
	double revenue = 0;

	// Number of orders
	int num_orders = 0;

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

	// Deconstructor
	~shop();

	// Gets the number of coffees
	void set_num_coffees(std::ifstream& file);

	// Creates and populates initial coffees array
	void coffee_array(std::ifstream& file);

	// Creates initial orders array
	void orders_array();

	// Prints menu to terminal
	void print_menu();

	// Option 2 functions
	void option_2(coffee& c, std::string name, double small, double medium, double large);

	// Option 3 functions
	int get_user_selection();
	void print_drink_options();
	void remove_coffee_from_array(int user_input);

	// Option 4 functions
	void option_4(const std::string& name);

	// Option 5 functions
	void option_5(const double& budget);

	// Option 6 functions
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
	 *		o file (std::ifstream&): Reference to input file stream to file.
	 */
	void populate_shop_from_file(std::ifstream& file);

	void print_revenue();
	void print_orders();

	void populate_new_order(order& o, int selection, char coffee_size, int quantity);
	double calculate_order_cost(order& o);
	void calculate_revenue(double& revenue, double new_order);
	void print_order_message(order& o);

	void write_orders_to_file(std::ofstream& file);
	void write_to_files(std::ofstream& menu_file, std::ofstream& orders_file);

};

#endif
