//StudentInfo.c - function definitions for student information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#include <stdbool.h>
#include "StudentInfo.h"

//InitializeInfo - returns void, accepts the address of struct StudentInfo
//Sets the last name to a null string. This can be accomplished by setting the first character
//                                     in the last name array to the null terminator '\0'.
//Sets the student id to 0.
//Goes through the subject array (NUM_SUBJECTS) and for each subject
//     sets name to a null string and
//     sets mark to 0.


//AverageMark - returns float, accepts the address of struct Subject
//
//Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
//    Once an invalid mark is reached (mark equals zero), the loop terminates
//
//Returns the running total divided by the number of marks.


//MaximumMark - returns integer, accepts the address of struct Subject
//
//Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
//    Once an invalid mark is reached (mark equals zero), the loop terminates
//
//The index of the maximum mark is returned


//MinimumMark - returns integer, accepts the address struct Subject
//
//Uses a for-next loop to go through all the marks (up to NUM_SUBJECTS).
//    Once an invalid mark is reached (mark equals zero), the loop terminates
//
//The index of the minimum mark is returned
