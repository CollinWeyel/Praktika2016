#include "ui.h"
#include <iostream>

void printVersion(std::string name, std::string version){
    std::string tab = "    ";
    int length = 2 + 5 * tab.length() + name.length() + version.length();
    printTabline(length);
    std::cout << "-" << tab << tab << name << tab << version << tab << tab << "-" << std::endl;
    printTabline(length);
}

void printTabline(int length){
    for (int i = 0; i < length; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
}

int printMenu(std::string name, std::string version){
    int choice = 0;

    printVersion(name, version);

    std::cout 
        << "1) Student auflisten" << std::endl
        << "2) Student anlegen" << std::endl
        << "3) Student suchen" << std::endl
        << "4) Student bearbeiten" << std::endl
        << "5) Student importieren" << std::endl
        << "6) Student exportieren" << std::endl
        << "7) Programm beenden" << std::endl 
        << std::endl << "Eingabe > ";

    std::cin >> choice;

    return choice;
}

void printStudents(student students[], int length){
    int empty = 0;

    std::cout << std::endl;

    for (int i = 0; i < length; i++){
        if (students[i].number == 0){
            empty++;
            continue;
        }

        std::cout
            << students[i].firstname << " " << students[i].lastname << " (" << students[i].gender << ")" << std::endl
            << "\tMatrikelnummer: " << students[i].number << std::endl
            << "\tAbschlussnote: " << students[i].endresult << std::endl;
    }

    if (length == empty){
        std::cout << "Es sind keine Studenten gespeichert." << std::endl;
    }
    
    std::cout << std::endl;
}