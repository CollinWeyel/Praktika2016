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

void printStudents(student *students, int length){
    student working_student = *students;

    if (students == NULL){
        std::cout << "Es sind keine Studenten gespeichert." << std::endl << std::endl;
        return;
    }
    
    std::cout << std::endl;

    do{
        
    } while (&(working_student = *working_student.child) != NULL);
}

bool addStudent(student students[], int length){
    int empty = 0, free = -1;
    student new_student;

    for (int i = 0; i < length; i++){
        if (students[i].number == 0){
            empty++;
            if (free == -1) free = i;
        }
    }

    if (empty == 0){
        std::cout << "Es können keine weiteren Studenten hinzu gefügt werden." << std::endl << std::endl;
        return false;
    }

    std::cout << "Bitte gib nun die Daten des Studenten ein." << std::endl << "Vorname: ";
    std::cin >> new_student.firstname;

    std::cout << "Nachname: ";
    std::cin >> new_student.lastname;

    std::cout << "Geschlecht (m/w): ";
    std::cin >> new_student.gender;

    std::cout << "Matrikelnummer: ";
    std::cin >> new_student.number;

    std::cout << "Abschlussnote: ";
    std::cin >> new_student.endresult;

    students[free] = new_student;

    return true;
}