#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
// example data
// Aaliyah 82 72 91 74 82

const int Max_cols = 7;
const int Max_Rows = 15;
const string FileName = "StudentGrades.txt";

// function prototype
// function prototype
int getData(istream &inFile, string names[], int data[][Max_cols]);
char getLetterGrade(double average);
void printReport(string names[], int data[][Max_cols], double averages[], int numStudents);


//function to produce formatted report
void 

//function to calculate average test scores



//function to calculate letter grade

char getLetterGrade(double average)
{
    if(average >= 90)
    {
        return 'A';
    }
    else if(average >= 80)
    {
        return 'B';
    }
    else if(average >= 70)
    {
        return 'C';
    }
    else if(average >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}


int getData(istream &inFile, string names[], int data[][Max_cols])
{
    int records = 0;
    while(inFile >> names[records] && records <= Max_Rows)
    {
        for(int c=0; c<Max_cols; c++)
        {
            inFile >> data[records][c];
        }
        records++;
    }
    return records;
}


int main() {
    // open file here
    // call readData function
    string names[Max_Rows];
    int data[Max_Rows][Max_cols];
    double averages[Max_Rows];
    int numStudents;
    ifstream inFile;
    inFile.open(FileName);
    if (!inFile.is_open()) {
        cout << "Error opening file " << FileName << endl;
        return 1;
    }
    numStudents = getData(inFile, names, data);
    inFile.close();
    // calculate averages

}