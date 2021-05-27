/**
 *   @file: node-main.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class Node driver to test the Node class used in a linked list. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "node.h"

using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {
    Node<int> *temp = new Node<int>(88);

    //create head and link it to temp
    Node<int> *head = new Node<int>();
    head->setData(99);
    head->setNext(temp);
    cout << "First node's data: " << head->getData() << endl;
    cout << "Second node's data: " << head->getNext()->getData() << endl;
    
    return 0;
} /// main