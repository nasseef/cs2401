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

template <typename DataType>
class Node
{
public:
    /**
     * Constructor: include default values for data and next
     * @param newData - data being stored, default is the constructor for 
     *                  type, 0 for numbers, false for bool
     * @param newNext - next pointer within the node, default nullptr
     */
    Node(const DataType newData = DataType(), Node * newNext = nullptr);

    //setters
    void setData(const DataType &newData);
    void setNext(Node<DataType> *newNext);

    //getters
    /**
     * getData - returns the data item which can be modified 
     *           using the iterator
     * @return - data stored at the node
     */
    DataType& getData();
    /**
     * getData - returns a const data item which cannot be modified 
     * @return - data stored at the node
     */
    const DataType& getData() const;
    const Node* getNext() const; //get the next field as constant
    Node* getNext(); //get the next field

private:
    DataType data;
    Node *next;
};
//must include the implementation file
#include "node.cc"
#endif