#include "coffee.h"
#include <iostream>
#include <fstream>
#include <string>

// TODO Implement the coffee class's member functions here
coffee::coffee() {

}

// Pass in one coffee (first index in coffee array) to get name, small/med/large cost (from file)
void coffee::set_a_coffee(std::ifstream& file) {
    file >> this->name >> this->small_cost >> this->medium_cost >> this->large_cost;
}

// Pass in one coffee and sets information from user (option 2)
void coffee::set_a_coffee_from_user(std::string name, double small, double medium, double large) {
    this->name = name;
    this->small_cost = small;
    this->medium_cost = medium;
    this->large_cost = large;
}

// Gets coffee name of specific coffee object
std::string coffee::get_coffee_name() {
    return this->name;
}

double coffee::get_small_cost() {
    return this->small_cost;
}

double coffee::get_medium_cost() {
    return this->medium_cost;
}

double coffee::get_large_cost() {
    return this->large_cost;
}