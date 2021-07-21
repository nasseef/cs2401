/**
 *   @file: queue-main.cc
 * @author: Nasseef Abukamail
 *   @date: July 21, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "queue.h"
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    Queue<int> numbers;
    numbers.push(5);
    numbers.push(10);
    numbers.push(15);
    numbers.push(20);
    numbers.push(25);
    
    cout << "Peek at the front of the queue: " << numbers.peek() << endl;
    cout << "Pop the front two items off the queue\n";
    numbers.pop();
    numbers.pop();
    cout << "Peek at the front of the queue: " << numbers.peek() << endl;
    cout << endl;

    //queue of strings
    Queue<string> names;
    names.push("Jack");
    names.push("Janet");
    names.push("Chrissy");
    names.push("Larry");


    //remove and print all elements
    while (!names.isEmpty())
    {
        cout << "queue front: " << names.pop() << endl;
    }
    
    return 0;
} /// main