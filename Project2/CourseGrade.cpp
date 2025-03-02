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


void calcAverage(student students[]. int studentCnt, int testsCnt)
{
    int i, j = 0;
    for (i < studentCnt; i++)
    {
        for (j < testsCnt; j++)
        {
            students[i].average += students[i].testScores[j];
        }
        students[i].average = students[i].average / testsCnt;
        students[i].letterGrade = getLetterGrade(students[i].average);
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
