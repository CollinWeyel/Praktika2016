/**
 * The main class who manages the programm.
 * 
 * Everything here manages the behavior of the choosen operations.
 * 
 * @author Collin Weyel
 * @file
 */

#include <iostream>
#include "ui.h"

/**
 * Repeats the menu and all functions.
 * 
 * Runs indefinetely till the user chooses to end the programm.
 */ 

int main(){
    std::string name = "Studentenverwaltung", version = "V0.1";

    while (true){
        switch (int choice = printMenu(name, version)){
        case 7:
            std::cout << "Das Programm wird beendet." << std::endl;
            return 0;
            break;
        default:
            std::cout << "Diese Funktion existiert noch nicht." << std::endl << std::endl;
            break;
        }
    }
}