// same output as GradeBook but with added student ID
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int Max_cols = 6;
const int Max_Rows = 15; // global constants
const string FileName = "StudentGrades2.txt";

struct Student {
    string name;
    int ID;
    int *testScores;
    double average;
    char grade;
};

// function prototypes
void getData(istream &inFile, string names[], int data[][Max_cols]); //function to read in data from file
void getData(istream &inFile, Student *&students, int &numStudents, int &numTests);
char getLetterGrade(double average);   //function to calculate letter grade
void printReport(Student *students, int numStudents, int numTests);
void calculateAverages(int data[][Max_cols], double averages[], int numStudents);   //function to calculate average test scores

// a function that reads data from a file containing number of students, number of tests as header 
// followed by records containing name, student ID, and test scores. Function assumes file is already open 
// receives file variable as input
void getData(istream &inFile, string names[], int data[][Max_cols]) {
    int records = 0;
    while(inFile >> names[records]) { //read student name
        inFile >> data[records][0]; // read student ID
        for(int i = 1; i <= Max_cols; i++) { // read test scores
            inFile >> data[records][i];
        }
        records++;
    }
}


// A function that reads the number of student records and the number of tests from the file. It
// dynamically allocates an array of structs to hold the student records. It uses a loop to read
// and store the student’s name and ID in the struct for each record. Before it reads the test
// scores for the record, it dynamically allocates an array to hold the test scores. When the
// function completes, it returns the pointer to the array structs and also returns the number of
// students and number of test scores as well
void getData(istream &inFile, Student *&students, int &numStudents, int &numTests){
    inFile >> numStudents; // read number of students
    inFile >> numTests; // read number of tests
    students = new Student[numStudents]; // dynamically allocate array of structs
    for (int x = 0; x < numStudents; x++){
        inFile >> students[x].name; // read student name
        inFile >> students[x].ID; // read student ID
        students[x].testScores = new int[numTests]; // dynamically allocate array of test scores
        for(int y = 0; y <= numTests; y++){
            inFile >> students[x].testScores[y]; // read test scores
        }

    }
}

// A function that is provided with the student data array and uses the test scores that are
// stored there to calculate the average of the test grades and the course grade for each
// student. These values are stored in the struct.
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
    cout << "Name  ID  Average Score  Grade" << endl; // format header
    cout << "*** ************* ******* " << endl;
    for(int x =0 ; x < numStudents; x++){
        cout << students[x].name << "  "; 
        cout << students[x].ID << "  ";
        cout << students[x].average << "  ";
        cout << students[x].grade << endl; // call getLetterGrade function
    }
}

//The function from the original version of the program that receives the average test score
//and returns the letter grade.
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



int main() {
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
    getData(inFile, names, data); // read data from file
    Student *students;
    getData(inFile, students, numStudents, numTests); // read data from file
    calculateAverages(students, numStudents, numTests); // calculate averages
    printReport(students, numStudents); // print report
    inFile.close(); // close the input file
    return 0;




}