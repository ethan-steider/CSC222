#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// struct to store student data
struct Student {
    string name;
    int ID;
    int *testScores;
    double average;
    char grade;
};

// function prototypes
void getData(istream &inFile, string names[], int data[][6], int &numStudents, int Max_cols, int Max_Rows); //function to read in data from file
void getDataStructs(istream &inFile, Student *&students, int &numStudents, int &numTests); //function to read in data from file
char getLetterGrade(double average);   //function to calculate letter grade
void printReport(Student *students, int numStudents); //function to print report
void calculateAverages(Student *students, int numStudents, int numTests);   //function to calculate average test scores


// testing push to branch
int main() {
    const int Max_cols = 6;
    const int Max_Rows = 15; // global constants
    const string FileName = "StudentGrades2.txt";
    string names[Max_Rows]; // array to store student names
    int data[Max_Rows][Max_cols]; // array to store test scores
    int numTests;
    int numStudents;   
    Student *students; // array of structs to store student data

    ifstream inFile; // input file stream
    inFile.open(FileName); // open the input file
    if(!inFile) // check if file opened successfully
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    getData(inFile, names, data, numStudents, Max_cols, Max_Rows); // read data from file

    inFile.clear();   // Clear error flags
    inFile.seekg(0);  // Reset file pointer

    getDataStructs(inFile, students, numStudents, numTests); // read data from file
    calculateAverages(students, numStudents, numTests); // calculate averages
    printReport(students, numStudents); // print report

    for(int x = 0; x < numStudents; x++){
        delete[] students[x].testScores; // deallocate test scores
    }
    delete[] students; // deallocate students
    inFile.close(); // close the input file
    return 0;
}

void getData(istream &inFile, string names[], int data[][6], int &numStudents, int Max_cols, int Max_Rows) {
    numStudents = 0;
    while(inFile >> names[numStudents]) { //read student name
        inFile >> data[numStudents][0]; // read student ID
        for(int i = 1; i < Max_cols; i++) { // read test scores
            inFile >> data[numStudents][i];
        }
        numStudents++;
    }
}



// This function reads the student data from the file and stores it in an array of structs
void getDataStructs(istream &inFile, Student *&students, int &numStudents, int &numTests){
    inFile >> numStudents; // read number of students
    inFile >> numTests; // read number of tests
    students = new Student[numStudents]; // dynamically allocate array of structs
    for (int x = 0; x < numStudents; x++){
        inFile >> students[x].name; // read student name
        inFile >> students[x].ID; // read student ID
        students[x].testScores = new int[numTests]; // dynamically allocate array of test scores
        for(int y = 0; y < numTests; y++){
            inFile >> students[x].testScores[y]; // read test scores
        }
    }
}



// This function receives the student data array, the number of students, and the number of tests
// as input parameters. It calculates the average test score for each student and the letter grade
// for the course. It stores these values in the struct for each student.
void calculateAverages(Student *students, int numStudents, int numTests){
    for(int x = 0; x < numStudents; x++){
        double total = 0;
        for(int y = 0; y < numTests; y++){
            total += students[x].testScores[y];
        }
        students[x].average = total / numTests;
        students[x].grade = getLetterGrade(students[x].average);
    }
}



// A function that is provided with the student data array and prints a formatted report.
void printReport(Student *students, int numStudents){
    cout << "Gradebook" << endl;
    cout << "************************************" << endl;
    cout << "Name       ID   Average  Grade" << endl; // format header
    cout << left << fixed << setprecision(2); // format output
    for(int x = 0; x < numStudents; x++){
        cout << setw(10) << students[x].name << " " << setw(4) << students[x].ID << " "
         << setw(8) << students[x].average << " " << students[x].grade << endl;
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


