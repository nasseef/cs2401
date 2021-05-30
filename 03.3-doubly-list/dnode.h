/**
 *   @file: node.h
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class DNode header file that is used in a doubly linked list. 
 */

#ifndef DNODE_H
#define DNODE_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


class DNode
{
public:
    //use the data type int for data, similar to typedef
    using DataType = int; 
    /**
     * Constructor: include default values for data and next
     * @param newData - data being stored, default is the constructor for 
     *                  type, 0 for numbers, false for bool
     * @param newNext - next pointer within the dnode, default nullptr
     */
    DNode(const DataType newData = DataType(), DNode * newNext = nullptr, 
          DNode * newPrevious = nullptr);

    //setters
    void setData(const DataType &newData);
    void setNext(DNode *newNext);
    void setPrevious(DNode *newPrevious);

    //getters
    DataType getData() const;
    const DNode* getNext() const; //get the next field as constant
    DNode* getNext(); //get the next field
    DNode *getPrevious();

private:
    DataType data;
    DNode *next;
    DNode *previous;
};
#endif