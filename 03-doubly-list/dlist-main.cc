/**
 *   @file: 03-node-class.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Test the doubly linked list class
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "dlist.h"

using namespace std;

int main(int argc, char const *argv[]) {
    DList myList;
    myList.headInsert(50);
    myList.headInsert(40);
    myList.headInsert(30);
    myList.headInsert(20);
    myList.headInsert(10);

    cout << "Length of the list: " << myList.length() << endl;

    cout << "List values" << endl;
    myList.output();
    
    DNode *searchPtr = myList.search(50);
    if (searchPtr != nullptr)
    {
        cout << "searchPtr value: " << searchPtr->getData() << endl;
    }
    //Insert a new value after 20
    myList.insertAfter(searchPtr, 99);

    
    
    cout << "List values after inserting after 20" << endl;
    myList.output();
   
    //delete some nodes
    myList.deleteNode(searchPtr);
    cout << "List values after deleting 20" << endl;
    myList.output();
    //try deleting other nodes (first, last, nullptr)
    return 0;
} /// main
