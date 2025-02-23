#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



// function prototypes

char getLetterGrade(double average);   //function to calculate letter grade




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


