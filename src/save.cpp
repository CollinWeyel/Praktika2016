#include <fstream>
#include "save.h"

bool exportStudents(student students[], int length, std::string filename){
    std::ofstream output;

    output.open(filename);
    output << "";
    output.close();

    output.open(filename, std::ios_base::app);

    for (int i = 0; i < length; i++){
        if (students[i].number == 0){
            continue;
        }

        output << students[i].firstname << ","
            << students[i].lastname << ","
            << students[i].gender << ","
            << students[i].number << ","
            << students[i].endresult << std::endl;
    }

    output.close();

    return true;
}

bool importStudents(student students[], int length, std::string filename){
    std::ifstream input;
    std::string line;
    int count = 0;
    
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

        students[count] = new_student;

        if (count == length - 1){
            break;
        }

        count++;
    }

    if (count != length){
        student dummy;
        for (int i = count; i < length; i++){
            students[i] = dummy;
        }
    }

    return true;
}