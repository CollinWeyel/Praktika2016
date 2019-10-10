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

void printStudents(student *students){
    student working_student = *students;

    if (students == NULL){
        std::cout << "Es sind keine Studenten gespeichert." << std::endl << std::endl;
        return;
    }
    
    std::cout << std::endl;

    do{
        std::cout
            << working_student.firstname << " " << working_student.lastname << " (" << working_student.gender << ")" << std::endl
            << "\tMatrikelnummer: " << working_student.number << std::endl
            << "\tAbschlussnote: " << working_student.endresult << std::endl << std::endl;
    } while (&(working_student = *working_student.child) != NULL);
}

bool addStudent(student *students){
    student dummy;
    student working_student = *students;

    while (students != NULL && &(working_student = *working_student.child) != NULL);

    std::cout << "Bitte gib nun die Daten des Studenten ein." << std::endl << "Vorname: ";
    std::cin >> dummy.firstname;

    std::cout << "Nachname: ";
    std::cin >> dummy.lastname;

    std::cout << "Geschlecht (m/w): ";
    std::cin >> dummy.gender;

    std::cout << "Matrikelnummer: ";
    std::cin >> dummy.number;

    std::cout << "Abschlussnote: ";
    std::cin >> dummy.endresult;

    working_student.child = &dummy;

    return true;
}