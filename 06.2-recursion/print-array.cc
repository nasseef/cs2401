/**
 *   @file: print-array.cc
 * @author: Nasseef Abukamail
 *   @date: July 29, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes
const size_t NUM_ITEMS = 5;
void revPrint(int numbers[], size_t numItems);
void revPrintRec(int numbers[], size_t numItems);

int main(int argc, char const *argv[]) {

    int numbers[NUM_ITEMS] = {10, 20, 30, 40, 50};

    revPrint(numbers, NUM_ITEMS);
    cout << endl;
    cout << "Printing recursively" << endl;
    revPrintRec(numbers, NUM_ITEMS);
    cout << endl;
    return 0;
} /// main

void revPrint(int numbers[], size_t numItems){
    for (int i = numItems - 1; i >= 0; i--)
    {
        cout << setw(4) << numbers[i];
    }
}
void revPrintRec(int numbers[], size_t numItems){
    if (numItems > 0)
    {
        revPrintRec(numbers, numItems - 1);  //tail recursion
        cout << setw(4) << numbers[numItems-1];
    }
}