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

const int Max_cols = 5;
const int Max_Rows = 15; // global constants
const string FileName = "StudentGrades.txt";

// function prototype
// function prototype
int getData(istream &inFile, string names[], int data[][Max_cols]); //function to read in data from file
char getLetterGrade(double average);   //function to calculate letter grade
void printReport(string names[], int data[][Max_cols], double averages[], int numStudents); //function to produce formatted report
int calculateAverages(int data[][Max_cols], double averages[], int numStudents);   //function to calculate average test scores


//function to produce formatted report
void printReport(string names[], int data[][Max_cols], double averages[], int numStudents){
    cout << "Gradebook" << endl;
    cout << "************************************" << endl;
    cout << "Name Average Score  Grade" << endl; // format header
    cout << "*** ************* ******* " << endl;
    for(int x =0 ; x < numStudents; x++){
        cout << names[x] << "  "; //
        cout << averages[x] << "  ";
        cout << getLetterGrade(averages[x]) << endl; // call getLetterGrade function
    }
}


char getLetterGrade(double average) //function to calculate letter grade
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

//function to calculate average test scores
int calculateAverages(int data[][Max_cols], double averages[], int numStudents) {
    for (int r = 0; r < numStudents; r++) { // loop through rows
        int sum = 0;
        for (int c = 0; c < Max_cols; c++) { // loop through columns
            sum += data[r][c]; // sum test scores
        }
        averages[r] = sum / Max_cols;
    }
}

int getData(istream &inFile, string names[], int data[][Max_cols])
{
    int records = 0;
    while(inFile >> names[records] && records < Max_Rows) // read in names
    {
        for(int c=0; c<Max_cols; c++) // read in test scores
        {
            inFile >> data[records][c];  // read in test scores
        }
        records++; 
    }
    return records;
}


int main() {
    string names[Max_Rows]; // array to store student names
    int data[Max_Rows][Max_cols]; // 2d array to store test scores
    double averages[Max_Rows]; // array to store averages
    int numStudents;   
    ifstream inFile;
    inFile.open(FileName);
    if (!inFile.is_open()) { // check if file is open
        cout << "Error opening file " << FileName << endl; // print error message if error with file
        return 1;
    }
    numStudents = getData(inFile, names, data); // call getData function
    calculateAverages(data, averages, numStudents); // calculate averages
    printReport(names, data, averages, numStudents); // print report
    inFile.close();
    
    return 0;
}