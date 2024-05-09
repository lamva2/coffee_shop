#include "shop.h"
#include <fstream>
#include <iostream>

// TODO Implement the shop class's member functions here
shop::shop() {

}

// Deconstructor for orders objects
shop::~shop() {
    if (this->orders != nullptr) {
        delete [] this->orders;
        this->orders = nullptr;
    }
}

void shop::option_2(menu& m, coffee& c, std::ifstream& file, std::string name, double small, double medium, double large) {
    int num_coffees = m.find_num_coffees(file);
    m.create_coffee_array();
    m.populate_coffee_array(num_coffees, file);
    m.populate_new_coffee(c, name, small, medium, large);
    m.add_coffee(c);
}


void shop::add_coffee_to_menu(const coffee& c) {
    
    // Access menu.txt and adds new coffee item to menu
	std::ofstream populate_menu_stream;
	populate_menu_stream.open("menu.txt", std::ios::app);
     
}

void shop::add_order(const order& o) {

}

void shop::populate_shop_from_file(std::ifstream& file) {
    std::getline(file, this->phone);
    std::getline(file, this->address);
    std::cout << std::endl << "Address: " << this->address 
        << std::endl << "Phone: " << this->phone << std::endl;
}