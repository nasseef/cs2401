
/**
 *   @file: list.h
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class List uses the DNode class to create a singular
 *          linked list.
 *          The copy constructor and the overloaded = operator need to be
 *          implemented.
 */

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "dnode.h"
using namespace std;

class DList
{
public:
    DList(DNode *newHead = nullptr);
    ~DList();

     DNode<DataType>* listHead() {return head;} //returns a pointer to the head of the list
    
    //List algorithms
    size_t length() const;
    void output() const;
    DNode* search(DNode::DataType target);
    void headInsert(DNode::DataType value);
    void insertAfter(DNode *cursor, DNode::DataType value);
    void deleteNode(DNode *current);
private:
    DNode *head;
};
#endif