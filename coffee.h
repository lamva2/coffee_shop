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
};

#endif
