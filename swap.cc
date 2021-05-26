/**
 *   @file: swap.cc
 * @author: Nasseef Abukamail
 *   @date: May 18, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes
void swap (int *intPtr1, int *intPtr2);
int main(int argc, char const *argv[]) {

    int x = 5, y = 6;
    cout << "Before swap: ";
    cout << "x = " << x << ", y = " << y << endl;
    swap(&x, &y);  	//send the addresses of x and y
    cout << "After swap: ";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
} /// main

void swap (int *intPtr1, int *intPtr2)
{
    int temp = *intPtr1;
    *intPtr1 = *intPtr2;
    *intPtr2 = temp;
}
