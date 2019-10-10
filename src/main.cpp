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
#include "student.h"

/**
 * Repeats the menu and all functions.
 * 
 * Runs indefinetely till the user chooses to end the programm.
 * 
 * @param name Name of the program.
 * @param version Version of the program.
 * @param students Array to store the existing students.
 */
int main(){
    std::string name = "Studentenverwaltung", version = "V0.2";
    student students[10];

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