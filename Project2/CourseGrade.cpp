#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// function prototypes
char getLetterGrade(double average);   //function to calculate letter grade
student* getData(ifstream& file, int& studentCnt, int& testsCnt); //function to get data from file
void calcAverage(student students[], int studentCnt, int testsCnt) //function to calculate average
void printReport(student students[], int studentCnt, int testsCnt); //function to print report


// testing push to branch
int main() {
    const int Max_cols = 6;
    const int Max_Rows = 15; // global constants
 

    ifstream inFile; // input file stream
    inFile.open(FileName); // open the input file
    if(!inFile) // check if file opened successfully
    {
        cout << "Error opening file." << endl;
        return 1;
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
