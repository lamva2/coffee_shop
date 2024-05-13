#ifndef DISPLAY_H
#define DISPLAY_H

#include "shop.h"

/*
 * Name: print_options()
 * Description: Print options to the user
 */
void print_options();

/*
 * Name: print_selection_error
 * Description: Scolds the user for selecting a bad option
 *		number
 */
void print_selection_error();

/*
 * THIS IS A SUGGESTED FUNCTION. IT IS IMPLEMENTED FOR YOU IN
 *		`display.cpp`
 * Name: get_option
 * Description: Prompt the user for their numbered option selection
 * Returns (int): The number associated with the option selected by the user
 */
int get_option();

/*
 * THIS IS A SUGGESTED FUNCTION. IT IS PARTIALLY IMPLEMENTED FOR YOU IN
 *		`display.cpp`.
 * Name: execute_option
 * Description: Execute the option selected by the user
 * parameters:
 *		s (shop&): A reference to the shop object
 *		option (int): The user's selected option to execute. Must be
 *			between 1 and 7 (inclusive).
 */
void execute_option(shop& s, int option);

void option_2_prompts(std::string& name, double& small_cost, double& medium_cost, double& large_cost);

std::string option_4_prompts();

void create_coffees_array(shop& s);

void create_output_streams(shop& s);

#endif
