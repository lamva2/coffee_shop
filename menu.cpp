#include "menu.h"
#include <fstream>
#include <iostream>

// TODO Implement the menu class's member functions here
menu::menu() {

}

menu::~menu() {
    if (this->coffees != nullptr) {
        delete [] this->coffees;
        this->coffees = nullptr;
    }
}

// Find number of coffees. Delcare stream to file in shop.cpp
int menu::find_num_coffees(std::ifstream& file) {
    file >> this->num_coffees;
    return this->num_coffees;
}


// Sets coffees pointer to coffees array
void menu::create_coffee_array() {
    this->coffees = new coffee[this->num_coffees];
}


// Populates coffees array with information from file
void menu::populate_coffee_array(int num_coffees, std::ifstream& file) {
    for (int i = 0; i < this->num_coffees; i++) {
        this->coffees[i].set_a_coffee(this->coffees[i], file);
    }
}


// Populates a new coffee object from information given by the user
void menu::populate_new_coffee(coffee& c, std::string name, double small, double medium, double large) {
    c.set_a_coffee_from_user(name, small, medium, large);
}


// Creates a larger array to store added coffees
void menu::add_coffee(const coffee& c) {
    // Creates new, bigger array to store existing coffees plus the new coffee
    coffee* new_coffees = new coffee[this->num_coffees + 1];
    // Copy the coffee elements from the old array to the new one (if it's not empty; if it's empty,
    //      this loop will iterate 0 times)
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


// Creates a smaller array to store coffees after removing a coffee
void menu::remove_coffee(int coffee_number) {
    coffee* new_coffees = new coffee[this->num_coffees - 1];
    for (int i = 0; i < this->num_coffees; i++) {
        if (i < coffee_number - 1) {
            new_coffees[i] = this->coffees[i];
        }
        if (i > coffee_number - 1) {
            new_coffees[i-1] = this->coffees[i];
        }
    }
    if (this->coffees != nullptr) {
        delete [] this->coffees;
    }
    this->coffees = new_coffees;
    this->num_coffees--;
}

// For option 3 and option 6, prints drink options from menu
void menu::print_drink_options() {
    for (int i = 0; i < this->num_coffees; i++) {
        std::cout << (i+1) << ". " << this->coffees[i].get_coffee_name() << std::endl;
    }
}

void menu::display_coffee_with_name(const std::string& name) {
    bool exists = false;
    for (int i = 0; i < this->num_coffees; i++) {
        if (this->coffees[i].get_coffee_name() == name) {
            this->coffees[i].get_coffee_info();
            exists = true;
        } else {
            continue;
        }
    }
    if (exists == false) {
        std::cout << "Sorry, we don't have that product at the moment." << std::endl;
    }
}

void menu::display_coffees_with_price(const double& budget) {
    for (int i = 0; i < this->num_coffees; i++) {
        if (this->coffees[i].get_small_cost() <= budget || 
            this->coffees[i].get_medium_cost() <= budget || this-> coffees[i].get_medium_cost() <= budget) {
                std::cout << this->coffees[i].get_coffee_name();
            }
        if (this->coffees[i].get_small_cost() <= budget) {
            std::cout << "Small: " << this->coffees[i].get_small_cost() << std::endl;   
        }
        if (this-> coffees[i].get_medium_cost() <= budget) {
            std::cout << "Medium: " << this->coffees[i].get_medium_cost() << std::endl;
        }
        if (this-> coffees[i].get_large_cost() <= budget) {
            std::cout << "Large: " << this->coffees[i].get_large_cost() << std::endl;
        }
    }
}

void menu::display_coffee_with_index(const int& selection) {
    for (int i = 0; i < this->num_coffees; i++) {
        if ((i+1) == selection) {
            this->coffees[i].get_coffee_info();
        } 
    }
}