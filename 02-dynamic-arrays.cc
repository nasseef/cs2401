/**
 *   @file: 02-dynamic-arrays.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    //create a dynamic array of integers
    int *numbers = new int[10];
    //now you can access it just like static arrays using []
    numbers[0] = 5;
    //5 is now stored in the first location
    //we can access it again using numbers[0] or *numbers
    //numbers points to the first location in the array

    //two ways to print the first element
    cout << "First element numbers[0]: " << numbers[0] << endl;
    cout << "First element *numbers: " << *numbers << endl;

    //two ways to store elements in the array
    numbers[1] = 88;
    *(numbers + 2) = 77; //store 77 at index 2
    *(numbers + 3) = 66;
    //two ways to print element 2
    cout << "First element numbers[2]: " << numbers[0] << endl;
    cout << "First element *(numbers+2): " << *(numbers+2) << endl;

    //Display the first 4 elements in the array using pointers
    for (size_t i = 0; i < 4; i++)
    {
        cout << "Element " << i << ": " << *(numbers + i) << endl;
    }
    
    //Deallocate the array when done
    delete [] numbers;

    //point to a static array
    char name[] = "John Smith";
    char *namePtr;
    namePtr = name;
    cout << "Name is " << namePtr << endl;

    //display the first letter in the name
    cout << "First letter in name: " << *namePtr << endl;

    //we can advance the pointer anywhere in the string name 
    //using the pointer namePtr
    //Let's say we want to display the last name starting at position 5
    namePtr += 5; //move the pointer to position 5
    cout << "Last name: " << namePtr << endl;

    //do not deallocate namePtr because it's pointing to static array    
    return 0;
} /// main