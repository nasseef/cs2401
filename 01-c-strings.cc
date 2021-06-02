/**
 *   @file: c-strings.cc
 * @author: Nasseef Abukamail
 *   @date: June 02, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    //declare a c-string, uses the first 6 locations of the array
    //The null character will be stored in position 5
    char last[100] = "Smith"; 

    //print last. Prints every character until '\0' is reached
    cout << last << endl;

    //Allocate exactly 6 characters
    char first[] = "John";
    cout << first << endl;
    
    //We can read the last name using cin
    cout << "Enter your last name: ";
    cin >> last;
    cout << last << endl;
    
    char name[100];
    //Let's read first and last name together
    //make sure you ignore the previous '\n' left by the previous cin
    cin.ignore(100, '\n');
    cout << "Enter your full name: ";
    cin.getline(name, 100);
    cout << name << endl;

    //using some string functions
    char name2[100];
    //copy name into name2
    strncpy(name2, name, 100);
    cout << name2 << endl;

    strncat(last, ", ", 100);
    strncat(last, first, 100);
    cout << last << endl;

    cout << "Name length: " << strlen(name) << endl;

    if (strncmp(last, "Smith, John", 100) == 0)
    {
        cout << "Two strings are equal" << endl;
    }
    else if (strncmp(last, "Smith, John", 100) < 0)
    {
        cout << "First string is smaller than the second" << endl;
    }
    else {
        cout << "First string is larger than the second" << endl;
    }
    
    
    return 0;
} /// main