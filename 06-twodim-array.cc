/**
 *   @file: 06-twodim-array.cc
 * @author: Nasseef Abukamail
 *   @date: July 29, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes
const size_t MAX_ROWS = 4;
const size_t MAX_COLS = 5;

void printArray(int numbers[][5], size_t numRows, size_t numCols);
void printRow(int row[], size_t numItems);

int main(int argc, char const *argv[]) {

    int numbers[MAX_ROWS][MAX_COLS] = {
        {10, 20, 30, 40, 50},
        {4, 6, 8, 10, 12},
        {9, 8, 7, 6, 5},
        {11, 22, 33, 44, 55}
    };

    printArray(numbers, MAX_ROWS, MAX_COLS);
    
    cout << "Print the array using printRow" << endl;

    for (size_t i = 0; i < MAX_ROWS; i++)
    {
        printRow(numbers[i], MAX_COLS);
        cout << endl;
        
    }
    
    //dynamically allocated rows of different lengths
    char *names[10];
    names[0] = new char[20];
    strncpy(names[0], "Edward", 100);
    names[1] = strndup("John", 100);
    names[2] = strndup("Bob", 100);

    cout << "Names" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << names[i] << endl;
    }

    //deallocate all the elements
    for (size_t i = 0; i < 3; i++)
    {
        delete [] names[i];
    }

    return 0;
} /// main

void printArray(int numbers[][5], size_t numRows, size_t numCols){
    for (size_t i = 0; i < numRows; i++)
    {
        for (size_t j = 0; j < numCols; j++)
        {
            cout << setw(4) << numbers[i][j];
        }
        cout << endl;
    }
    
}
void printRow(int row[], size_t numItems){
    for (size_t i = 0; i < numItems; i++)
    {
        cout << setw(4) << row[i];
    }
}