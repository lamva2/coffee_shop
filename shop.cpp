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

void shop::set_num_coffees(std::ifstream& file) {
    this->m.set_num_coffees(file);
}

// Calls public menu member functions to populate coffees array and add new coffee to the array (option 2)
void shop::coffee_array(std::ifstream& file) {
    this->m.create_coffee_array();
    this->m.populate_coffee_array(file);
}

// Creates orders array
void shop::orders_array() {
    this->orders = new order[this->num_orders];
}

// Option 1: Prints the menu
void shop::print_menu() {
    this->m.print_menu();
}

// Option 1: Print the shop address and the phone number
void shop::populate_shop_from_file(std::ifstream& file) {
    std::getline(file, this->phone);
    std::getline(file, this->address);
    std::cout << std::endl << "Address: " << this->address 
        << std::endl << "Phone: " << this->phone << std::endl;
}

void shop::print_revenue() {
    std::cout << "The shop revenue is: $" << this->revenue << std::endl;
}

void shop::print_orders() {
    std::cout << "Order info:" << std::endl;
    for (int i = 0; i < this->num_orders; i++) {
        std::cout << this->orders[i].get_order_number() << " "
            << this->orders[i].get_coffee_name() << " "
            << this->orders[i].get_order_size() << " "
            << this->orders[i].get_order_quantity() << std::endl;
    }
    std::cout << std::endl;
}

// Populates new coffee object with information from user
void shop::option_2(coffee& c, std::string name, double small, double medium, double large) {
    this->m.populate_new_coffee(c, name, small, medium, large);
}

// Adds new coffee object to coffees array (menu)
void shop::add_coffee_to_menu(const coffee& c) {
    this->m.add_coffee(c);
}

// Calls public menu member functions to print drink options from menu (used in option 3 & 6)
void shop::print_drink_options() {
    this->m.print_drink_options();
}

// Gets user selection for drink to remove (option 3)
int shop::get_user_selection() {
    int drink_selection;
    std::cout << "Selection: ";
    std::cin >> drink_selection;
    return drink_selection;
}

// Removes coffee from array (option 3)
void shop::remove_coffee_from_array(int user_input) {
    this->m.remove_coffee(user_input);
}

// Displays coffee information with name that user inputs (option 4)
void shop::option_4(const std::string& name) {
    this->m.display_coffee_with_name(name);
}

void shop::option_5(const double& budget) {
    this->m.display_coffees_with_price(budget);
}

// Displays information about the coffee the user would like to order
void shop::option_6(const int& selection) {
    this->m.display_coffee_with_index(selection);
}


// Populates a new order object from information given by the user
void shop::populate_new_order(order& o, int selection, char coffee_size, int quantity) {
    std::string coffee_name;
    for (int i = 0; i < this->m.get_num_coffees(); i++) {
        if ((i+1) == selection) {
            coffee_name = this->m.get_coffee_name(i);
        }
    }
    o.set_order_from_user(this->num_orders + 1, coffee_name, coffee_size, quantity);
}

// Adds new order to orders array 
void shop::add_order(const order& o) {
    // Creates new, bigger array to store existing orders plus the new order
    order* new_orders = new order[this->num_orders + 1];
    // Copy the coffee elements from the old array to the new one (if it's not empty; if it's empty,
    //      this loop will iterate 0 times)
    for (int i = 0; i < this->num_orders; i++) {
        new_orders[i] = this->orders[i];
    }
    // Put new coffee into last index of new array
    new_orders[this->num_orders] = o;
    // Delete old array (it it's not empty)
    if (this->orders != nullptr) {
        delete [] this->orders;
    }
    // Reassign this->coffees to point to the new, bigger array
    this->orders = new_orders;
    //Increment this->num_coffees
    this->num_orders++;
}

// Calculates the cost of an order and returns it. Also adds order total cost to revenue.
double shop::calculate_order_cost(order& o) {
    double cost_per_drink;
    double total_cost;
    for (int i = 0; i < this->m.get_num_coffees(); i++) {
        if (o.get_coffee_name() == this->m.get_coffee_name(i)) {
            if (o.get_order_size() == 's') {
                cost_per_drink = this->m.get_small_cost(i);
            } else if (o.get_order_size() == 'm') {
                cost_per_drink = this->m.get_medium_cost(i);
            } else if (o.get_order_size() == 'l') {
                cost_per_drink = this->m.get_large_cost(i);
            }
        }
    }
    total_cost = cost_per_drink * o.get_order_quantity();
    this->revenue += total_cost;
    return total_cost;
}

void shop::print_order_message(order& o) {
    std::cout << "Your order has been placed. Your order number is " << o.get_order_number() << "." << std::endl;
}

void shop::write_orders_to_file(std::ofstream& file) {
    file >> this->num_orders >> "\n";
    for (int i = 0; i < this->num_orders; i++) {
        file >> this->orders[i].get_order_number() >> " " >> this->orders[i].get_coffee_name() >> " " >> this->orders[i].get_order_size() >> " " >> this->orders[i].get_order_quantity() >> "\n";
    }
}

void shop::write_to_files(std::ofstream& menu_file, std::ofstream& orders_file) {
    this->m.rewrite_menu(menu_file);
    this->write_orders_to_file(orders_file);
}