#ifndef COFFEE_H
#define COFFEE_H

#include <string>

class coffee {
private:
	std::string name;
	double small_cost = 0.0;
	double medium_cost = 0.0;
	double large_cost = 0.0;

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

	void set_a_coffee(coffee& c, std::ifstream& file);
	void set_a_coffee_from_user(std::string name, double small, double medium, double large);
	std::string get_coffee_name();
	void get_coffee_info();
	double get_small_cost();
	double get_medium_cost();
	double get_large_cost();
};

#endif
