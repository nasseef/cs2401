/**
 *   @file: 03-node-class.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class List uses the Node class to create a singular
 *          linked list.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "list.h"

using namespace std;

int main(int argc, char const *argv[]) {
    
    List<int> numbers;
    numbers.headInsert(50);
    numbers.headInsert(40);
    numbers.headInsert(30);
    numbers.headInsert(20);
    numbers.headInsert(10);
    cout << "Length of the list: " << numbers.length() << endl;

    cout << "List values" << endl;
    //numbers.output();

    auto it = numbers.begin();
    //or
    //List<int>::iterator i = numbers.begin();
    for (; it != numbers.end(); ++it){
        (*it)++;
    }
    
    numbers.output();
    //Let's try a List of a different type

    List<string> names;

    names.headInsert("Jack");
    names.headInsert("Janet");
    names.headInsert("Chrissy");
    names.headInsert("Larry");

    //use the range based for loop this time
    for(auto name : names){
        cout << name << endl;
    }

    cout << "Using the constant iterator" << endl;
    //test the constant iterator
    for (auto it = names.cbegin(); it != names.cend(); it++)
    {
        cout << *it << endl;
    }
    return 0;
} /// main
