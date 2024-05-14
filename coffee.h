#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <fstream>
#include <string>

class coffee {
private:
	std::string name; // Coffee name
	double small_cost = 0.0; // Small cost
	double medium_cost = 0.0; // Medium Cost
	double large_cost = 0.0; // Large  cost

public:
	/*
	 * NOTE: THIS IS A REQUIRED FUNCTION. DO NOT ALTER ITS PROTOTYPE.
	 *		YOU MUST IMPLEMENT IT IN `coffee.cpp` OR SET IT TO `default`.
	 *		THIS FUNCTION IS USED BY THE BIG 3 TESTING SCRIPT.
	 * Name: coffee (default constructor)
	 * Description: Constructs a coffee object with an empty name
	 *		and all costs of 0
	 */
	coffee();

	/*
	 Name: set_a_coffee (setter)
	 Description: Sets a coffee from a the menu.txt file. Gets the name, small,
	 	medium, and large cost and stores in a coffee object.
	 Parameters:
	 	file (std::ifstream&): Reference to input stream to file (menu.txt)
	*/
	void set_a_coffee(std::ifstream& file);

	/*
	 Name: set_a_coffee_from_user (getter)
	 Description: Sets a coffee from the user. Gets the name, small, medium, and 
	 	large cost and stores in a coffee object.
	 Parameters: 
	 	name (std::string): Name of drink
		small (double): Price of small coffee
		medium (double): Price of medium coffee
		large (double): Price of large coffee
	*/
	void set_a_coffee_from_user(std::string name, double small, double medium, double large);

	/*
	 Name: get_a_coffee_name (getter)
	 Description: Gets the name of a coffee object (name is private)
	 Return (std::string): name of coffee object
	*/
	std::string get_coffee_name();

	/*
	 Name: get_small_cost (getter)
	 Description: Gets the small cost of a coffee object (small cost is private)
	 Return (double): small cost of coffee object
	*/
	double get_small_cost();

	/*
	 Name: get_medium_cost (getter)
	 Description: Gets the medium cost of a coffee object (medium cost is private)
	 Return (double): medium cost of coffee object
	*/
	double get_medium_cost();

	/*
	 Name: get_large_cost (getter)
	 Description: Gets the large cost of a coffee object (large cost is private)
	 Return (double): large cost of coffee object
	*/
	double get_large_cost();
};

#endif
