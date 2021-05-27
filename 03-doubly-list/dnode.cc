

/**
 *   @file: dnode.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class Node implementation that is used in a singular linked list. 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "dnode.h"

using namespace std;
DNode::DNode(const DataType newData, DNode * newNext, DNode *newPrevious)
{
    data = newData;
    next = newNext;
    previous = newPrevious;
}


void DNode::setData(const DataType &newData){
    data = newData;
}
void DNode::setNext(DNode *newNext){
    next = newNext;
}

void DNode::setPrevious(DNode *newprevious){
    previous = newprevious;
}

//getters
DNode::DataType DNode::getData() const{
    return data;
}
const DNode* DNode::getNext() const{ //get the next field as constant
    return next;
}
DNode* DNode::getNext(){ //get the next field
    return next;
}
DNode* DNode::getPrevious(){ //get the Previous field
    return previous;
}
