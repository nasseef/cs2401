/**
 *   @file: factorial.cc
 * @author: Nasseef Abukamail
 *   @date: July 27, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes
double factorialRec(int n);
double factorial(int n);
int main(int argc, char const *argv[]) {

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    double result = factorial(n);
    cout << "Factorial of " << n << " is " << result << endl;

    result = factorialRec(n);
    cout << "Recursive factorial of " << n << " is " << result << endl;

    return 0;
} /// main

double factorial(int n){
    double multiplier = n;
    for (size_t i = n - 1; i > 0; i--)
    {
        multiplier *= i;
    }
    return multiplier;
}
double factorialRec(int n){
    if (n == 0)
    {
        return 1;
    }
    return  n * factorialRec(n - 1);
}