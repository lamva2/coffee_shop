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
 Name: option_2_prompts
 Description: Prompts for name, small cost, medium cost, and large cost of coffee
    user would like to add to menu. Error handles invalid inputs.
 Parameters:
    name (std::string&): name of coffee
    small_cost (double&): small cost of coffee
    medium_cost (double&): medium cost of coffee
    large_cost (double&): large cost of coffee
*/
void option_2_prompts(std::string& name, double& small_cost, double& medium_cost, double& large_cost);

/*
 Name: option_4_prompts
 Description: Prompts for coffee name for option 4 (search by coffee name)
*/
std::string option_4_prompts();

/*
 Name: option_5_prompts
 Description: Prompts for the user's budget for option 5 (search by price)
*/
double option_5_prompts();

/*
 Name: option_6_prompt_for_selection
 Description: Prompts for the user's drink selection for option 6 (place order)
*/
int option_6_prompt_for_selection();

/*
 Name: option_6_prompt_for_size
 Description: Prompts for the drink size user would like to order for option 6
    (place order)
*/
char option_6_prompt_for_size();

/*
 Name: option_6_prompt_for_quantity
 Description: Prompts for the quantity of drinks the user would like to order 
    for option 6 (place order)
*/
int option_6_prompt_for_quantity();

/*
 Name: create_coffees_array
 Description: Creates coffees array and populates with information from menu.txt
 Parameters:
    s (shop&): reference to shop object
*/
void create_coffees_array(shop& s);

/*
 * THIS IS A SUGGESTED FUNCTION. IT IS PARTIALLY IMPLEMENTED FOR YOU IN
 *		`display.cpp`.
 * Name: execute_option
 * Description: Execute the option selected by the user
 * Parameters:
 *		s (shop&): A reference to the shop object
 *		option (int): The user's selected option to execute. Must be
 *			between 1 and 7 (inclusive).
 */
void execute_option(shop& s, int option);

/*
 Name: create_output_streams
 Description: Creates output streams to files (menu.txt and orders.txt)
    and writes coffees array and orders array to respective files.
 Parameters:
    s (shop&): a reference to the shop object
*/
void create_output_streams(shop& s);

#endif
