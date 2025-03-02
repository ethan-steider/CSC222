#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// structure to hold student data
struct student
{
    int studentID;
    string lastName;
    string firstName;
    double *testScores;
    double average;
    char letterGrade;
};

// function prototypes
char getLetterGrade(double average);   //function to calculate letter grade
student* getData(ifstream& file, int& studentCnt, int& testsCnt); //function to get data from file
void calcAverage(student students[], int studentCnt, int testsCnt); //function to calculate average
void printReport(student students[], int studentCnt, int testsCnt); //function to print report

string FileName = "StudentGrades2.txt"; // global constant

int main() {
    const int Max_Rows = 15; 
 

    ifstream inFile; // input file stream
    inFile.open(FileName); // open the input file
    if(!inFile) // check if file opened successfully
    {
        cout << "Error opening file." << endl;
    }

    int studentCnt = 0 ; 
    int testsCnt = 0; 

    student* students = getData(inFile, studentCnt, testsCnt); 
    calcAverage(students, studentCnt, testsCnt); 
    printReport(students, studentCnt, testsCnt); 

    delete[] students; s
    inFile.close(); 

    return 0;
}

// This function reads the data from the input file and stores it in an array of student structures.
student* getData(ifstream& file, int& studentCnt, int& testsCnt)
{
    file >> studentCnt;
    file >> testsCnt;

    student* students = new student[studentCnt]; // create array of student structures

    for (int i = 0; i < studentCnt; i++)
    {
        file >> students[i].studentID;
        file >> students[i].lastName;
        file >> students[i].firstName;

        for (int j = 0; j < testsCnt; j++)
        {
            file >> students[i].testScores[j];
        }
    }
    return students;
}

// This function prints the report to the console.
void printReport(student students[], int studentCnt, int testsCnt)
{
    cout << "Student ID" << setw(10) << "Last Name" << setw(10) << "First Name" << setw(10) << "Average" << setw(10) << "Grade" << endl;
    for (int i = 0; i < studentCnt; i++)
    {
        cout << students[i].studentID << setw(10) << students[i].lastName << setw(10) << students[i].firstName << setw(10) << students[i].average << setw(10) << students[i].letterGrade << endl;
    }
}


void calcAverage(student students[], int studentCnt, int testsCnt)
{
    for (int i = 0; i < studentCnt; i++)
    {
        students[i].average = 0; // make average 0 tp start

        for (int j = 0; j < testsCnt; j++)
        {
            students[i].average += students[i].testScores[j]; // add up all test scores
        }
        students[i].average = students[i].average / testsCnt; // divide by number of tests to get average
        students[i].letterGrade = getLetterGrade(students[i].average); // get letter grade
    }
}

// This function takes the average test score as input and returns the letter grade for the course.
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
