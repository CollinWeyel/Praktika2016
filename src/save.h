#ifndef SAVE
#define SAVE

/**
 * Helper to save studens to csv and reimport them.
 * 
 * Saves students to csv and reads them from file.
 * 
 * @author Collin Weyel
 * @file
 */

#include <string>
#include "student.h"

/**
 * Exports students to csv.
 * 
 * @param students[] The students to be saved.
 * @param length The length of the students array.
 * @param filename The file to be written.
 */
bool exportStudents(student **students, std::string filename);

/**
 * Imports students to csv.
 * 
 * @param students[] Where the students should be written to.
 * @param length The length of the students array.
 * @param filename The file to be read.
 */
bool importStudents(student **students, std::string filename);

#endif