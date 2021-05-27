
/**
 *   @file: list.h
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class List uses the Node class to create a singular
 *          linked list.
 */

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "node.h"
using namespace std;

class List
{
public:
    List(Node *newHead = nullptr);
    ~List();

    //List algorithms
    size_t length() const;
    void output() const;
    Node* search(Node::DataType target);
    void headInsert(Node::DataType value);
    void insert(Node::DataType value);
    void insertAfter(Node *previous, Node::DataType value);
    void deleteNode(Node *current);
private:
    Node *head;
};
#endif