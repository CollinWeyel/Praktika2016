#ifndef STUDENT
#define STUDENT

#include <string>

/**
 * Container class for everything related to students.
 * 
 * @author Collin Weyel
 * @file
 */

/**
 * Struct to save data belonging to a student.
 * 
 * @param firstname The firstname of the student.
 * @param lastname The lastname of the student.
 * @param gender The gender of the student.
 * @param numebr The number of the student.
 * @param endresult The endresult of the student.
 */
struct student{
    std::string firstname = "",
                lastname = "";
    char gender = ' ';
    int number = 0;
    float endresult = 0.0f;
};


#endif