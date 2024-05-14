#include "order.h"

// Order constructor
order::order() {
    
}

// Sets an order object from the user
void order::set_order_from_user(int order_number, std::string coffee_name, 
    char coffee_size, int quantity) {
    this->order_number = order_number; // Sets order number
    this->coffee_name = coffee_name; // Sets name of coffee
    this->coffee_size = coffee_size; // Sets size of coffee
    this->quantity = quantity; // Sets quantity of coffees
}

// Gets order number of specific order
int order::get_order_number() {
    return this->order_number; // Returns order number
}

// Gets coffee name of specific order
std::string order::get_coffee_name() {
    return this->coffee_name; // Returns coffee name
}

// Gets coffee size of specific order
char order::get_order_size() {
    return this->coffee_size; // Returns coffee size
}

// Gets quantity of specific order
int order::get_order_quantity() {
    return this->quantity; // Returns quantity of coffees
}



