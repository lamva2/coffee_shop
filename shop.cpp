#include "shop.h"

// Shop Default Constuctor
shop::shop() {

}

// Shop deconstructor
shop::~shop() {
    if (this->orders != nullptr) {
        delete [] this->orders; // delete orders array
        this->orders = nullptr; // point orders to nullptr
    }
}

// Shop copy constructor
shop::shop(const shop& existing_shop) : num_orders(existing_shop.num_orders), 
    orders(new order[num_orders]) {
    for (int i = 0; i < num_orders; i++) { 
        // Setting each element of new orders array to existing orders array
        this->orders[i] = existing_shop.orders[i];  
    }   
}

// Shop assignment operator overload
void shop::operator=(const shop& other_shop) {
    if (this == &other_shop) {
        return; // If this shop is equal to other shop, return shop
    }
    if (orders != nullptr) {
        delete [] orders; // Delete orders array if not equal to nullptr
    }
    // set num_orders to other shop's num orders
    num_orders = other_shop.num_orders;  
    orders = new order[num_orders]; // create orders array on heap
    for (int i = 0; i < num_orders; i++) {
        // Copy over each element in the old array to the new array
        orders[i] = other_shop.orders[i]; 
    }
}

void shop::set_num_coffees(std::ifstream& file) {
    this->m.set_num_coffees(file); // Sets number of coffees with info from file
}

// Calls public menu member functions to populate coffees array and add new 
//      coffee to the array (option 2)
void shop::coffee_array(std::ifstream& file) {
    this->m.create_coffee_array(); // Creates coffees array
    this->m.populate_coffee_array(file); // Populates coffees array
}

void shop::orders_array() {
    // Create orders array and set to orders pointer
    this->orders = new order[this->num_orders];
}

// Option 1: Print the shop address and the phone number
void shop::populate_shop_from_file(std::ifstream& file) {
    // Get the phone number of shop from file
    std::getline(file, this->phone);
    // Get the address of shop from file
    std::getline(file, this->address);
    // Print address and phone number of shop to terminal
    std::cout << std::endl << "Address: " << this->address 
        << std::endl << "Phone: " << this->phone << std::endl;
}

void shop::print_revenue() {
    // Print shop revenue of shop to terminal
    std::cout << "The shop revenue is: $" << this->revenue << std::endl;
}

void shop::print_menu() {
    // Print menu of shop to terminal
    this->m.print_menu();
}

void shop::print_orders() {
    std::cout << "Order info:" << std::endl;
    if (this->num_orders == 0) {
        // If no orders, print message
        std::cout << "(No orders to display)" << std::endl;
    }
    for (int i = 0; i < this->num_orders; i++) {
        // For each element in orders array, print order information
        std::cout << this->orders[i].get_order_number() << " "
            << this->orders[i].get_coffee_name() << " "
            << this->orders[i].get_order_size() << " "
            << this->orders[i].get_order_quantity() << std::endl;
    }
    std::cout << std::endl;
}

void shop::option_2(coffee& c, std::string name, double small, double medium, double large) {
    // Populate a new coffee object with information from the user
    this->m.populate_new_coffee(c, name, small, medium, large);
}

void shop::add_coffee_to_menu(const coffee& c) {
    // Adds new coffee object to coffees array (menu)
    this->m.add_coffee(c);
}

void shop::print_drink_options() {
    // Prints drink options from menu (used in option 3 & 6)
    this->m.print_drink_options();
}

// Gets user selection for drink to remove (option 3)
int shop::get_user_selection() {
    int drink_selection; // drink selection
    bool valid = false; // valid selection set to false
    do {
        // Get drink selection from user
        std::cout << "Selection: ";
        std::cin >> drink_selection;
        for (int i = 1; i <= this->m.get_num_coffees(); i++) {
            if (drink_selection == i) {
                valid = true;
                // If drink selection found, set valid to true
            }
        }
        if (valid == true) {
            // Break out of the loop if valid is true
            break;
        }
        // If valid is still false, print following error message
        std::cout << "Drink option not valid. Please re-enter a valid selection." << std::endl;
    } while (true);
    return drink_selection; // Return the valid drink selection
}

void shop::remove_coffee_from_array(int user_input) {
    // Removes the coffee user wants to remove from the coffees array
    this->m.remove_coffee(user_input);
}

void shop::option_4(const std::string& name) {
    // Display coffee information with name that user inputs to terminal
    this->m.display_coffee_with_name(name);
}

void shop::option_5(const double& budget) {
    // Display coffees that meet the budget requirements that user inputs
    this->m.display_coffees_with_price(budget);
}

void shop::option_6(const int& selection) {
    // Display information about the coffee the user would like to order
    this->m.display_coffee_with_index(selection);
}

void shop::populate_new_order(order& o, int selection, char coffee_size, int quantity) {
    std::string coffee_name;
    for (int i = 0; i < this->m.get_num_coffees(); i++) {
        if ((i+1) == selection) {
            // gets the coffee name of the drink user orders
            coffee_name = this->m.get_coffee_name(i);
        }
    }
    // Populates the order object with the informaiton given by the user
    o.set_order_from_user(this->num_orders + 1, coffee_name, coffee_size, quantity);
}
 
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
    double cost_per_drink; // Cost per drink
    double total_cost; // Total cost of order
    for (int i = 0; i < this->m.get_num_coffees(); i++) {
        if (o.get_coffee_name() == this->m.get_coffee_name(i)) {
            if (o.get_order_size() == 'S') {
                // Gets the cost per drink if drink is size small
                cost_per_drink = this->m.get_small_cost(i);
            } else if (o.get_order_size() == 'M') {
                // Gets the cost per drink if drink is size medium
                cost_per_drink = this->m.get_medium_cost(i);
            } else if (o.get_order_size() == 'L') {
                // Gets the cost per drnk if drink is size large
                cost_per_drink = this->m.get_large_cost(i);
            }
        }
    }
    // Calculates the total cost of the order
    total_cost = cost_per_drink * o.get_order_quantity();
    // Adds cost to revenue of shop
    this->revenue += total_cost;
    // Return shop
    return total_cost;
}

void shop::print_order_message(order& o) {
    // Prints order message with order number
    std::cout << "Your order has been placed. Your order number is " << o.get_order_number() << "." << std::endl;
}

void shop::write_orders_to_file(std::ofstream& file) {
    // Writes the number of orders to file (orders.txt)
    file << this->num_orders << "\n";
    for (int i = 0; i < this->num_orders; i++) {
        // Writes information of each order to file (orders.txt)
        file << this->orders[i].get_order_number() << " " << this->orders[i].get_coffee_name() << " " 
            << this->orders[i].get_order_size() << " " << this->orders[i].get_order_quantity() << "\n";
    }
}

void shop::write_to_files(std::ofstream& menu_file, std::ofstream& orders_file) {
    // Calls write menus function and writes menu to file
    this->m.rewrite_menu(menu_file);
    // Calls write orders function and write orders to file 
    this->write_orders_to_file(orders_file);
}