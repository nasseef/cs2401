/**
 *   @file: main.cc
 * @author: Nasseef Abukamail
 *   @date: August 05, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "bnode.h"
#include "bstree.h"

using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    BSTree<int> numbers;
    numbers.insert(50);
    numbers.insert(40);
    numbers.insert(60);
    numbers.insert(45);
    numbers.insert(35);
    numbers.insert(55);
    numbers.insert(70);
    numbers.insert(80);
    numbers.insert(10);
    numbers.print();
    cout << endl;
    
    cout << "Tree size: " << numbers.size() << endl;
    
    BNode<int>* searchPtr = numbers.search(99);
    if (searchPtr == nullptr)
    {
        cout << "Not found" << endl;
    }
    else{
        cout << "Found: " << searchPtr->data << endl;
    }
    return 0;
} /// main