#include <fstream>
#include "save.h"
#include <iostream>

// todo todo Repai export
bool exportStudents(student **students, std::string filename){
    std::ofstream output;
    student working_student = **students;

    output.open(filename);
    output << "";
    output.close();

    if (!students){
        return false;
    }

    output.open(filename, std::ios_base::app);

    do{
        output << working_student.firstname << ","
            << working_student.lastname << ","
            << working_student.gender << ","
            << working_student.number << ","
            << working_student.endresult << std::endl;
    } while (&(working_student = *working_student.child));

    output.close();

    return true;
}

bool importStudents(student **students, std::string filename){
    std::ifstream input;
    std::string line;
    student working_student;
    
    *students = &working_student;
    
    input.open(filename);

    while (std::getline(input, line)){
        student new_student;
        int pos = 0;

        new_student.child = NULL;

        new_student.firstname = line.substr(0, pos = line.find(','));
        line.erase(0, pos + 1);

        new_student.lastname = line.substr(0, pos = line.find(','));
        line.erase(0, pos + 1);

        new_student.gender = line.substr(0, pos = line.find(',')).c_str()[0];
        line.erase(0, pos + 1);

        new_student.number = std::stoi(line.substr(0, pos = line.find(',')));
        line.erase(0, pos + 1);

        new_student.endresult = std::stof(line.substr(0, pos = line.find(',')));

        if (!working_student.number){
            working_student = new_student;
        } else if (!working_student.child) {
            new_student.parent = &working_student;
            working_student.child = &new_student;
        } else {
            student *dummy = working_student.child;
            while (dummy->child) dummy = dummy->child;
            new_student.parent = dummy;
            dummy->child = &new_student;
        }
    }

    return true;
}