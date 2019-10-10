#ifndef UI
#define UI

/**
 * Manages everything the user sees.
 * 
 * @author Collin Weyel
 * @file
 */ 

#include <string>

/**
 * Prints the version of the program.
 * 
 * @param name The name of the program.
 * @param version The version of the program.
 */ 
void printVersion(std::string name, std::string version);

/**
 * Prints a line of '-' with variable length.
 * 
 * @param length Number of '-'.
 */
void printTabline(int length);

/**
 * Prints the menu.
 * 
 * @param name The name of the program.
 * @param version The version of the program.
 */
int printMenu(std::string name, std::string version);

#endif