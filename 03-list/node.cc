

/**
 *   @file: node.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class Node implementation that is used in a singular linked list. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "node.h"

using namespace std;
Node::Node(const DataType newData, Node * newNext)
{
    data = newData;
    next = newNext;
}


void Node::setData(const DataType &newData){
    data = newData;
}
void Node::setNext(Node *newNext){
    next = newNext;
}

//getters
Node::DataType Node::getData() const{
    return data;
}
const Node* Node::getNext() const{ //get the next field as constant
    return next;
}
Node* Node::getNext(){ //get the next field
    return next;
}
