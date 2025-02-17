// program populated array with values
//function then called to reverse the array
// memory is deallocated in the function before it terminates
// function one reverses array by dynamicly creating array of size of input parameter
// then it copies the values from the input array to the new array in reverse order
// receives a constant array and its size returns pointer to the new array
// function two receives a constant array and its size then displays the contents of the array

#include <iostream>
using namespace std;

// Function prototypes
int *ReverseArray( int const arr[], int size);
void PrintArray( int arr[], int size);


void PrintArray(int arr[], int size) // function two
{
    for (int i = 0; i < size; i++) // loop through the array
    {
        cout << arr[i] << " "; // print each element
    }
    cout << endl;
}

int *ReverseArray(int const arr[], int size) // function one
{

}

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