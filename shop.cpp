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

// Calls public menu member functions to populate coffees array and add new coffee to the array (option 2)
void shop::option_2(menu& m, coffee& c, std::ifstream& input_file, std::ofstream& output_file, std::string name, double small, double medium, double large) {
    int num_coffees = m.find_num_coffees(input_file);
    m.create_coffee_array();
    m.populate_coffee_array(num_coffees, input_file);
    m.populate_new_coffee(c, name, small, medium, large);
    m.add_coffee(c);
}

// Gets user selection for drink to remove (option 3)
int shop::get_user_selection() {
    int drink_selection;
    std::cout << "Selection: ";
    std::cin >> drink_selection;
    return drink_selection;
}

// Calls public menu member functions to print drink options from menu (option 3 & 6)
void shop::print_drink_options(menu& m) {
    m.print_drink_options();
}

// Removes coffee from array (option 3)
void shop::remove_coffee_from_array(menu& m, int user_input) {
    m.remove_coffee(user_input);
}

// Displays coffee information with name that user inputs (option 4)
void shop::option_4(menu& m, const std::string& name) {
    m.display_coffee_with_name(name);
}

void shop::option_5(menu& m, const double& budget) {
    m.display_coffees_with_price(budget);
}

void shop::option_6(menu& m, const int& selection) {
    m.display_coffee_with_index(selection);
}


/* required function!!!
void shop::add_coffee_to_menu(const coffee& c) {
    
    // Access menu.txt and adds new coffee item to menu
	std::ofstream populate_menu_stream;
	populate_menu_stream.open("menu.txt", std::ios::app);
     
}
*/
void shop::add_order(const order& o) {

}

void shop::populate_shop_from_file(std::ifstream& file) {
    std::getline(file, this->phone);
    std::getline(file, this->address);
    std::cout << std::endl << "Address: " << this->address 
        << std::endl << "Phone: " << this->phone << std::endl;
}