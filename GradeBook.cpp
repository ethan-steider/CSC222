#include <iostream>
#include <fstream>

//	Write a program that averages student test scores and provides letter grades for the averages for a teacher to record in a grade book

//read students names and test scores from a file, calculate the average test score for each student, and assign a letter grade based on the average
// Do not assume a fixed number of students or test scores
// Data should be stored in partially filled arrays
// actual number of students represented in the file is counted as the file is read. 
// number of scores should be a global constant
// use the following grading scale:
// 90-100 A
// 80-89 B
// 70-79 C
// 60-69 D
// 0-59 F
// program should be modular and use parallel arrays. names stored as array of strings. test scores stored as 2d array, row for student and test scores in columns
//averages stored in a separate array of doubles

void readData(string names[], double scores[], int numStudents); // function prototype

//function to read data from file
void readData(string names[], double scores[], int numStudents); {
    std::ifstream inputFile("StudentGrades.txt");
    

}

//function to calculate average test score

//function to calculate letter grade

//function to produce formatted report

