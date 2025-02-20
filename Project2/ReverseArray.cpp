#include <iostream>
using namespace std;


// Function prototypes
int *ReverseArray( int const arr[], int size); // function to reverse the array using pointers
void PrintArray( int arr[], int size); // function to print the array



int main()
{
    // test with an array of size 10
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original array: ";
    PrintArray(arr, SIZE); 
    cout << "Reversed array: ";
    int *reversedArr = ReverseArray(arr, SIZE); 
    PrintArray(reversedArr, SIZE);
    delete[] reversedArr;


    // test with a different array size
    const int SIZE2 = 5;
    int arr2[SIZE2] = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    PrintArray(arr2, SIZE2);
    cout << "Reversed array: ";
    int *reversedArr2 = ReverseArray(arr2, SIZE2);
    PrintArray(reversedArr2, SIZE2);
    delete[] reversedArr2;
    return 0;

}


void PrintArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) // loop through the array
    {
        cout << arr[i] << " "; // print each element
    }
    cout << endl;
}

int *ReverseArray(int const arr[], int size) 
{
    int *reversedArr = new int[size]; // dynamically allocate memory for the reversed array
    for (int i = 0; i < size; i++) // loop through the original array
    {
        reversedArr[i] = arr[size - 1 - i]; // copy elements in reverse order
    }
    return reversedArr; // return pointer to the reversed array

}

