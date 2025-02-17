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


void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int *ReverseArray(int const arr[], int size)


int main()
{
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original array: ";
    PrintArray(arr, SIZE);

    cout << "Reversed array: ";
    int *reversedArr = ReverseArray(arr, SIZE);
    PrintArray(reversedArr, SIZE);

    return 0;
}