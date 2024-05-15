#include "coffee.h"

// Coffee constructor
coffee::coffee() {

}

// Pass in one coffee (first index in coffee array) to get name, 
//      small/med/large cost (from file)
void coffee::set_a_coffee(std::ifstream& file) {
    file >> this->name >> this->small_cost >> this->medium_cost 
        >> this->large_cost;
}

// Pass in one coffee and sets information from user (option 2)
void coffee::set_a_coffee_from_user(std::string name, double small, 
    double medium, double large) {
    this->name = name; // Sets coffee name
    this->small_cost = small; // Sets small cost
    this->medium_cost = medium; // Sets medium cost
    this->large_cost = large; // Sets large cost
}

// Gets coffee name of specific coffee object
std::string coffee::get_coffee_name() {
    return this->name; // Returns coffee name
}

// Gets small cost of specific coffee object
double coffee::get_small_cost() {
    return this->small_cost; // returns small cost
}

// Gets medium cost of specific coffee object
double coffee::get_medium_cost() {
    return this->medium_cost; // returns medium cost
}

// Gets large cost of specific coffee object
double coffee::get_large_cost() {
    return this->large_cost; // returns large cost
}
