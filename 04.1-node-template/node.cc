

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
template <typename DataType>
Node<DataType>::Node(const DataType newData, Node<DataType> * newNext)
{
    data = newData;
    next = newNext;
}

template <typename DataType>
void Node<DataType>::setData(const DataType &newData){
    data = newData;
}
template <typename DataType>
void Node<DataType>::setNext(Node<DataType> *newNext){
    next = newNext;
}

//getters
template <typename DataType>
DataType Node<DataType>::getData() const{
    return data;
}

template <typename DataType>
const Node<DataType> * Node<DataType>::getNext() const{ //get the next field as constant
    return next;
}
template <typename DataType>
Node <DataType> * Node<DataType>::getNext(){ //get the next field
    return next;
}
