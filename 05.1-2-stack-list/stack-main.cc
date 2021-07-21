/**
 *   @file: stack-main.cc
 * @author: Nasseef Abukamail
 *   @date: July 17, 2021
 *  @brief: A driver program to test the stack template
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "stack.h"

using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {


    Stack<int> numbers;
    
    numbers.push(5);
    numbers.push(10);
    numbers.push(15);
    numbers.push(20);
    numbers.push(25);
    
    cout << "Peek at the top of the stack: " << numbers.peek() << endl;
    cout << "Pop the top two items off the stack\n";
    numbers.pop();
    numbers.pop();
    cout << "Peek at the top of the stack: " << numbers.peek() << endl;
    cout << endl;

    return 0;
    //stack of strings
    Stack<string> names;
    names.push("Jack");
    names.push("Janet");
    names.push("Chrissy");
    names.push("Larry");

    //Test the overloaded assignment operator
    Stack<string> names2 = names;

    while (!names2.isEmpty())
    {
        cout << "Stack top: " << names2.pop() << endl;
    }
    
    return 0;
} /// main