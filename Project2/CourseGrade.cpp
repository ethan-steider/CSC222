#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// structure to hold student data
struct student
{
    int studentID;
    string Name;
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
        return 1;
    }

    int studentCnt = 0 ; 
    int testsCnt = 0; 

    student* students = getData(inFile, studentCnt, testsCnt); // get the data from the input file
    calcAverage(students, studentCnt, testsCnt); // calculate the average and letter grade for each student
    printReport(students, studentCnt, testsCnt); // print the report to the console

    delete[] students; 
    inFile.close(); 

    return 0;
}

// This function reads the data from the input file and stores it in an array of student structures.
student* getData(ifstream& file, int& studentCnt, int& testsCnt)
{
    file >> studentCnt;
    file >> testsCnt;

    student* students = new student[studentCnt]; // create array of student structures

    for (int i = 0; i < studentCnt; i++) // loop through each student
    {
   
        file >> students[i].Name;
        file >> students[i].studentID;

        students[i].testScores = new double[testsCnt]; 

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
    cout << "Student ID" << setw(10) << "Name" << setw(10) << "Average" << setw(10) << "Grade" << endl;
    for (int i = 0; i < studentCnt; i++)
    {
        cout << students[i].studentID << setw(17) << students[i].Name << setw(10) << students[i].average << setw(10) << students[i].letterGrade << endl;
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
