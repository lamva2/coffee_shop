#ifndef ORDER_H
#define ORDER_H

#include <string>

class order {
private:
	int order_number = 0;
	std::string coffee_name;
	char coffee_size = 0;
	int quantity = 0;
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
	

	void set_order_from_user(int order_number, std::string coffee_name, char coffee_size, int quantity);
	int get_order_number();
	std::string get_coffee_name();
	char get_order_size();
	int get_order_quantity();
};

#endif
