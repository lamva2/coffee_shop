#include "menu.h"

// Menu constructor
menu::menu() {

}

// Menu destructor
menu::~menu() {
    if (this->coffees != nullptr) {
        delete [] this->coffees; // Delete coffees pointer
        this->coffees = nullptr; // Sets coffees pointer to nullptr
    }
}

// Menu Copy Constructor
menu::menu(const menu& existing_menu) : num_coffees(existing_menu.num_coffees), 
    coffees(new coffee[num_coffees]) {
    for (int i = 0; i < num_coffees; i++) {
        // Copies each element in existing array to new coffee array
        this->coffees[i] = existing_menu.coffees[i]; 
    }   
}

// Menu Assignment Operator
void menu::operator=(const menu& other_menu) {
    if (this == &other_menu) {
        return; // Return if same menu
    }
    if (coffees != nullptr) {
        delete [] coffees; // Delete coffees pointer if not nullptr
    }
    // Set num_coffees to other num_coffees
    num_coffees = other_menu.num_coffees;
    // Creates new coffee array on heap 
    coffees = new coffee[num_coffees];
    // Copies each element in existing array to another existing array
    for (int i = 0; i < num_coffees; i++) {
        coffees[i] = other_menu.coffees[i];
    }
}

// Get number of coffees of menu
int menu::get_num_coffees() {
    return this->num_coffees; // Return number of coffees
}

// Set number of coffees of menu from file (menu.txt)
int menu::set_num_coffees(std::ifstream& file) {
    file >> this->num_coffees;
    return this->num_coffees; // Returns number of coffees of menu
}

// Get coffee name at certain index in coffees array
std::string menu::get_coffee_name(int index) {
    // Return name of coffee at index
    return (this->coffees[index].get_coffee_name());
}

// Get small cost at certain index in coffees array
double menu::get_small_cost(int index) {
    // Return small cost of coffee at index
    return (this->coffees[index].get_small_cost());
}

// Get medium cost at certain index in coffees array
double menu::get_medium_cost(int index) {
    // Return medium cost of coffee at index
    return (this->coffees[index].get_medium_cost());
}

// Get large cost at certain index in coffees array
double menu::get_large_cost(int index) {
    // Return large cost of coffee at index
    return (this->coffees[index].get_large_cost());
}

// Sets coffees pointer to new coffees array on heap
void menu::create_coffee_array() {
    // Menu coffees pointer points to new coffee array on heap
    //      of size num_coffees
    this->coffees = new coffee[this->num_coffees];
}

// Populates coffees array with information from file
void menu::populate_coffee_array(std::ifstream& file) {
    for (int i = 0; i < this->num_coffees; i++) {
        // For each index of coffees array, get 
        // data from file using set_a_coffee function
        this->coffees[i].set_a_coffee(file);
    }
}

// Prints current menu to terminal
void menu::print_menu() {
    std::cout << "Here is our menu:" << std::endl;
    for (int i = 0; i < this->num_coffees; i++) {
        std::cout << (i+1) << ". " << this->coffees[i].get_coffee_name() << std::endl
            << "\t" << "Small - " << this->coffees[i].get_small_cost() << std::endl
            <<  "\t" << "Medium - " << this->coffees[i].get_medium_cost() << std::endl
            << "\t" << "Large - " << this->coffees[i].get_large_cost() << std::endl;
    }
    std::cout << std::endl;
}

// Populates a new coffee object from information given by the user
void menu::populate_new_coffee(coffee& c, std::string name, double small, 
    double medium, double large) {
    // Sets coffee object with information from user
    c.set_a_coffee_from_user(name, small, medium, large); 
}

// Creates a larger array to store added coffees for option 2
void menu::add_coffee(const coffee& c) {
    // Creates new, bigger array to store existing coffees plus the new coffee
    coffee* new_coffees = new coffee[this->num_coffees + 1];
    // Copy the coffee elements from the old array to the new one (if it's not 
    //      empty; if it's empty, this loop will iterate 0 times)
    for (int i = 0; i < this->num_coffees; i++) {
        new_coffees[i] = this->coffees[i];
    }
    // Put new coffee into last index of new array
    new_coffees[this->num_coffees] = c;
    // Delete old array (it it's not empty)
    if (this->coffees != nullptr) {
        delete [] this->coffees;
    }
    // Reassign this->coffees to point to the new, bigger array
    this->coffees = new_coffees;
    //Increment this->num_coffees
    this->num_coffees++;
}

// For option 3 (remove a coffee) and option 6 (place an order), prints drink 
//      options from menu
void menu::print_drink_options() {
    for (int i = 0; i < this->num_coffees; i++) {
        // Prints coffee number and coffee name
        std::cout << (i+1) << ". " << this->coffees[i].get_coffee_name() 
            << std::endl;
    }
}

// Creates a smaller array to store coffees after removing a coffee
void menu::remove_coffee(int coffee_number) {
    // Creates new, smaller array to store existing coffees minus the removed coffee
    coffee* new_coffees = new coffee[this->num_coffees - 1];
    // Copy the coffee elements from the old array to the new one (if it's not 
    //      empty; if it's empty, this loop will iterate 0 times)
    for (int i = 0; i < this->num_coffees; i++) {
        if (i < coffee_number - 1) {
            new_coffees[i] = this->coffees[i];
        }
        // Skip over coffee user would like to remove
        if (i > coffee_number - 1) {
            new_coffees[i-1] = this->coffees[i];
        }
    }
    // Delete old array (it it's not empty)
    if (this->coffees != nullptr) {
        delete [] this->coffees;
    }
    // Reassign this->coffees to point ot the new, smaller array
    this->coffees = new_coffees;
    // Decrement this->num_coffees
    this->num_coffees--;
}

// For option 4, displays the coffee with the name user searches up
void menu::display_coffee_with_name(const std::string& name) {
    bool exists = false; // Set exists to false
    for (int i = 0; i < this->num_coffees; i++) {
        if (this->coffees[i].get_coffee_name() == name) {
            std::cout << "Results: " << std::endl;
            std::cout << this->coffees[i].get_coffee_name() << std::endl 
                << "Small: " << this->coffees[i].get_small_cost() 
                << std::endl << "Medium: " << this->coffees[i].get_medium_cost() 
                << std::endl << "Large: " 
                << this->coffees[i].get_large_cost() << std::endl;
            exists = true; // Set exists to true if name exists
        } else {
            continue;
        }
    }
    if (exists == false) {
        // If name does not exists, print error message.
        std::cout << "Sorry, we don't have that product at the moment." 
            << std::endl;
    }
}

// For option 5, dispalys the coffees that are equal to or less than the budget
void menu::display_coffees_with_price(const double& budget) {
    for (int i = 0; i < this->num_coffees; i++) {
        // If the small, medium, or large costs are less than or equal to the 
        //      budget, print name of coffee
        if (this->coffees[i].get_small_cost() <= budget || 
            this->coffees[i].get_medium_cost() <= budget || 
            this-> coffees[i].get_medium_cost() <= budget) {
                std::cout << this->coffees[i].get_coffee_name() << std::endl;
            
            // If small cost is less than or equal to budget, print it.
            if (this->coffees[i].get_small_cost() <= budget) {
                std::cout << "Small: " << this->coffees[i].get_small_cost() 
                    << std::endl;   
            }
            // If medium cost is less than or equal to budget, print it.
            if (this-> coffees[i].get_medium_cost() <= budget) {
                std::cout << "Medium: " << this->coffees[i].get_medium_cost() 
                    << std::endl;
            }
            // If large cost is less than or equal to budget, print it.
            if (this-> coffees[i].get_large_cost() <= budget) {
                std::cout << "Large: " << this->coffees[i].get_large_cost() 
                    << std::endl;
            }
        } else {
            // If none of the small, medium, or large drinks meet budget, 
            //      print error message.
            if (i == this->num_coffees - 1) {
                std::cout << "Sorry, no drinks match that budget." << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

// For option 6, displays the coffee with the specific selection (index + 1)
void menu::display_coffee_with_index(const int& selection) {
    for (int i = 0; i < this->num_coffees; i++) {
        // If the index+1 equals the selection, print data on the coffee at index.
        if ((i+1) == selection) {
            std::cout << this->coffees[i].get_coffee_name() << std::endl 
                << "Small: " << this->coffees[i].get_small_cost() 
                << std::endl << "Medium: " << this->coffees[i].get_medium_cost() 
                << std::endl << "Large: " << this->coffees[i].get_large_cost() 
                << std::endl;
        } 
    }
}

// Rewrites menu to menu.txt file through output stream
void menu::rewrite_menu(std::ofstream& file) {
    // Outputs number of coffees to first line of file
    file << this->get_num_coffees() << "\n";
    for (int i = 0; i < this->num_coffees; i++) {
        // Outputs each coffee in coffees array to file
        file << this->coffees[i].get_coffee_name() << " " 
            << this->coffees[i].get_small_cost() << " " 
            << this->coffees[i].get_medium_cost() 
            << " " << this->coffees[i].get_large_cost() << "\n";
    }
}