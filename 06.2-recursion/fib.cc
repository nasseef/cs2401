/**
 *   @file: fib.cc
 * @author: Nasseef Abukamail
 *   @date: July 30, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes

double fib(int n);
double fibRec(int n);

int main(int argc, char const *argv[]) {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " iteratively: " << fib(n) << endl;

    cout << "Fibonacci of " << n << " recursively: " << fibRec(n) << endl;
    
    return 0;
} /// main

double fib(int n){
    double first = 1;
    double second = 1;
    double third;
    while(n > 2){
        third = first + second;
        first = second;
        second = third;
        n--;
    }
    return third;
}
double fibRec(int n){
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibRec(n - 1) + fibRec(n - 2);
}