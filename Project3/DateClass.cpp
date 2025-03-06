// Date class should store a date in three integers month day and year. member functions to print
// the date in the following formats:
// 12/25/2021
// December 25, 2021
// 25 December 2021
// do not accept values for day greater than last day of month or less than
// do not accept values for month greater than 12 or less than 1

// date is represented via three integers the month is an integer between 1 and 12, day is an integer 
//between 1 and the last day of that month the year is a positive integer. The default date is 1/1/1900


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void setDate(int m, int day, int y);

int getMonth();
int getDay();
int getYear();

bool isLeapYear();
bool isLeapYear(int year);

int lastDay();
int lastDay(int month, int year);

void printDate1();
void printDate2();
void printDate3();

Date(int = 1, int = 1, int = 1900);

class Date {
    private:
        int month;
        int day;
        int year;
    public:
        void setDate(int m, int day, int y);
        int getMonth();
        int getDay();
        int getYear();
        bool isLeapYear();
        bool isLeapYear(int year);
        int lastDay();
        int lastDay(int month, int year);
        void printDate1();
        void printDate2();
        void printDate3();
        Date(int m = 1, int d = 1, int y = 1900);
};