// same output as GradeBook but with added student ID

// a function that reads data from a file containing number of students, number of tests as header 
//followed by records containing name, student ID, and test scores. Function assumes file is already open 
// receives file variable as input

// a function that reads the number of student records and the number of tests from the file. It
// dynamically allocates an array of structs to hold the student records. It uses a loop to read
// and store the student’s name and ID in the struct for each record. Before it reads the test
// scores for the record, it dynamically allocates an array to hold the test scores. When the
// function completes, it returns the pointer to the array structs and also returns the number of
// students and number of test scores as well


//A function that is provided with the student data array and uses the test scores that are
// stored there to calculate the average of the test grades and the course grade for each
// student. These values are stored in the struct. Use the function you wrote in the original
// version to calculate the letter grade. Here is the prototype for this function

//A function that is provided with the student data array and prints a formatted report. Here is
//an example of what the report should look like






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