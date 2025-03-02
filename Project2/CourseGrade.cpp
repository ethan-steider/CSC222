#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// structure to hold student data
struct student
{
    int idNum;
    string Name;
    double *Tests;
    double Average;
    char Grade;
};

// function prototypes from outline
char getLetterGrade(double average);   //function to calculate letter grade
student* getData(ifstream& file, int& studentCnt, int& testsCnt); //function to get data from file
void calcAverage(student students[], int studentCnt, int testsCnt); //function to calculate average
void printReport(student students[], int studentCnt, int testsCnt); //function to print report

string FileName = "StudentGrades2.txt"; // global variable for file name

int main() {

    ifstream inFile; // input file stream
    inFile.open(FileName); // open the input file
    if(!inFile) // check if file opened successfully
    {
        cout << "Error opening file." << endl;
        return 1; // exit program
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
        file >> students[i].idNum;

        students[i].Tests = new double[testsCnt]; 

        for (int j = 0; j < testsCnt; j++) 
        {
            file >> students[i].Tests[j];
        }
    }
    return students;
}

// This function prints the report using the data stored in the array of student structures.
void printReport(student students[], int studentCnt, int testsCnt)
{
    cout << "Student ID" << setw(10) << "Name" << setw(10) << "Average" << setw(10) << "Grade" << endl;
    for (int i = 0; i < studentCnt; i++)
    {
        cout << students[i].idNum << setw(17) << students[i].Name << setw(10) << students[i].Average << setw(10) << students[i].Grade << endl;
    }
}

// This function calculates the average test score for each student and assigns a letter grade based on the average
void calcAverage(student students[], int studentCnt, int testsCnt)
{
    for (int i = 0; i < studentCnt; i++)
    {
        students[i].Average = 0; // make average 0 tp start

        for (int j = 0; j < testsCnt; j++)
        {
            students[i].Average += students[i].Tests[j]; // add up all test scores
        }
        students[i].Average = students[i].Average / testsCnt; // divide by number of tests to get average
        students[i].Grade = getLetterGrade(students[i].Average); // get letter grade
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
    else if (average >= 0 && average < 60) 
    {
        return 'F';
    }
    else
    {
        return 'X';
    }
}
