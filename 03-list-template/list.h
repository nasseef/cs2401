
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

template<typename DataType>
class List
{
public:
    List(Node<DataType> *newHead = nullptr);
    ~List();

    //List algorithms
    size_t length() const;
    void output() const;
    Node<DataType>* search(DataType target);
    void headInsert(DataType value);
    void insert(DataType value);
    void insertAfter(Node<DataType> *previous, DataType value);
    void deleteNode(Node<DataType> *current);
private:
    Node<DataType> *head;
};
#include "list.cc"
#endif