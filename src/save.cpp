#include <fstream>
#include "save.h"

bool exportStudents(student *students, std::string filename){
    std::ofstream output;
    student working_student = *students;

    output.open(filename);
    output << "";
    output.close();

    if (students == NULL){
        return;
    }

    output.open(filename, std::ios_base::app);

    do{
        output << working_student.firstname << ","
            << working_student.lastname << ","
            << working_student.gender << ","
            << working_student.number << ","
            << working_student.endresult << std::endl;
    } while (&(working_student = *working_student.child) != NULL);

    output.close();

    return true;
}

bool importStudents(student *students, std::string filename){
    std::ifstream input;
    std::string line;
    
    input.open(filename);

    while (std::getline(input, line)){
        student new_student;
        int pos = 0;

        new_student.firstname = line.substr(0, pos = line.find(','));
        line.erase(0, pos + 1);

        new_student.lastname = line.substr(0, pos = line.find(','));
        line.erase(0, pos + 1);

        new_student.gender = line.substr(0, pos = line.find(',')).c_str()[0];
        line.erase(0, pos + 1);

        new_student.number = std::stoi(line.substr(0, pos = line.find(',')));
        line.erase(0, pos + 1);

        new_student.endresult = std::stof(line.substr(0, pos = line.find(',')));

        if (students != NULL){
            students->child = &new_student;
            students = &new_student;
        }

        students = &new_student;
    }

    return true;
}