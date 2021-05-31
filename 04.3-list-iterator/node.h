/**
 *   @file: node.h
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class Node header file that is used in a singular linked list.
 *          Implementation is included
 */

#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

template <typename DataType>
class Node {
   public:
    /**
     * Constructor: include default values for data and next
     * @param newData - data being stored, default is the constructor for
     *                  type, 0 for numbers, false for bool
     * @param newNext - next pointer within the node, default nullptr
     */
    Node(const DataType newData = DataType(), Node* newNext = nullptr) {
        data = newData;
        next = newNext;
    }

    // setters
    void setData(const DataType& newData){
        data = newData;
    }
    void setNext(Node<DataType>* newNext){
        next = newNext;
    }

    // getters
    /**
     * getData - returns the data item which can be modified
     *           using the iterator
     * @return - data stored at the node
     */
    DataType& getData(){
        return data;
    }
    /**
     * getData - returns a const data item which cannot be modified
     * @return - data stored at the node
     */
    const DataType& getData() const{
        return data;
    }
    const Node* getNext() const{  // get the next field as constant
       return next;            // get the next field
    }
    Node* getNext(){
         return next;
    }
   private:
    DataType data;
    Node* next;
};
#endif