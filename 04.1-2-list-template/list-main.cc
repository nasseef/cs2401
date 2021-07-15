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
    
    List<int> myList;
    myList.headInsert(50);
    myList.headInsert(40);
    myList.headInsert(30);
    myList.headInsert(20);
    myList.headInsert(10);
    cout << "Length of the list: " << myList.length() << endl;

    cout << "List values" << endl;
    myList.output();

    List<string> names;
    names.headInsert("Jack");
    names.headInsert("Janet");
    names.headInsert("Chrissy");
    
    cout << "List of names\n";
    names.output();
    return 0;
} /// main
