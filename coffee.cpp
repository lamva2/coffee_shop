#include "coffee.h"
#include <iostream>
#include <fstream>

// TODO Implement the coffee class's member functions here
coffee::coffee() {

}

// Pass in one coffee (first index in coffee array) to get name, small/med/large cost (from file)
void coffee::set_a_coffee(coffee& c, std::ifstream& file) {
    file >> c.name >> c.small_cost >> c.medium_cost >> c.large_cost;
}

// Pass in one coffee and set information from user 
void coffee::set_a_coffee_from_user(std::string name, double small, double medium, double large) {
    this->name = name;
    this->small_cost = small;
    this->medium_cost = medium;
    this->large_cost = large;
}