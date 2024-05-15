#ifndef ORDER_H
#define ORDER_H

#include <string>

class order {
private:
	int order_number = 0; // Order number
	std::string coffee_name; // Coffee Name
	char coffee_size = 0; // Coffee Size
	int quantity = 0; // Quantity of Coffees
public:
	/* 
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `order.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: order (default constructor)
	 * Description: Constructs an order with order_number 0,
	 *		empty coffee name, null (0) coffee size, and 0
	 *		quantity.
	 */
	order();
	
	/*
	 Name: set_order_from_user (setter)
	 Description: Sets an order object with user input order number, coffee
	 	name, coffee size, and quantity.
	 Parameters:
	 	order_number (int): order number of order
		coffee_name (std::string): name of coffee ordered
		coffee_size (char): size of coffee ordered
		quantity (int): number of coffee ordered 
	*/
	void set_order_from_user(int order_number, std::string coffee_name, 
        char coffee_size, int quantity);

	/*
	 Name: get_order_number (getter)
	 Description: Gets the order number of a specific order
	 Return (int): order number
	*/
	int get_order_number();

	/*
	 Name: get_coffee_name (getter)
	 Description: Gets the coffee name of a specific order
	 Return (std::string): name of coffee of order
	*/
	std::string get_coffee_name();

	/*
	 Name: get_order_size (getter)
	 Description: Gets the order size of a specific order
	 Return (char): coffee size of an order
	*/
	char get_order_size();

	/*
	 Name: get_order_quantity (getter)
	 Description: Gets the quantity of coffees of a specific order
	 Return (int): quantity of order
	*/
	int get_order_quantity();
};

#endif
