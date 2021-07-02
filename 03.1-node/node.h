/**
 *   @file: node.h
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class Node header file that is used in a singular linked list. 
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


class Node
{
public:
    //use the data type int for data, similar to typedef
    using DataType = int; 
    /**
     * Constructor: include default values for data and next
     * @param newData - data being stored, default is the constructor for 
     *                  type, 0 for numbers, false for bool
     * @param newNext - next pointer within the node, default nullptr
     */
    Node(const DataType newData = DataType(), Node * newNext = nullptr){
        data = newData;
        next = newNext;
    }

    

    //setters
    void setData(const DataType &newData){
        data = newData;
    }
    void setNext(Node *newNext){
        next = newNext;
    }

    //getters
    DataType getData() const{
        return data;
    }
    const Node* getNext() const{ //get the next field as constant
        return next;
    }
    Node* getNext(){ //get the next field
        return next;
    }
    
private:
    DataType data;
    Node *next;
};
#endif