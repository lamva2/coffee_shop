#include "order.h"

// TODO Implement the order class's member functions here
order::order() {
    
}

void order::set_order_from_user(int order_number, std::string coffee_name, char coffee_size, int quantity) {
    this->order_number = order_number;
    this->coffee_name = coffee_name;
    this->coffee_size = coffee_size;
    this->quantity = quantity;
}

int order::get_order_number() {
    return this->order_number;
}

std::string order::get_coffee_name() {
    return this->coffee_name;
}

char order::get_order_size() {
    return this->coffee_size;
}

int order::get_order_quantity() {
    return this->quantity;
}



