/**
 *   @file: list.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class List implementation uses the Node class to create a singular
 *          linked list.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "list.h"

using namespace std;

template<typename DataType>
List<DataType>::List(Node<DataType> *newHead) { head = newHead; }

template<typename DataType>
List<DataType>::~List() {
    // deallocate all the nodes
    Node<DataType> *cursor = head;
    while (cursor != nullptr) {
        deleteNode(cursor);
        cursor = cursor->getNext();
    }
}

template<typename DataType>
size_t List<DataType>::length() const {
    Node<DataType> *cursor = head;
    size_t count = 0;
    while (cursor != nullptr) {
        count++;
        cursor = cursor->getNext();
    }
    return count;
}

template<typename DataType>
void List<DataType>::output() const {
    Node<DataType> *cursor = head;
    while (cursor != nullptr) {
        cout << cursor->getData() << endl;
        cursor = cursor->getNext();
    }
}

template<typename DataType>
Node<DataType> * List<DataType>::search(DataType target) {
    Node<DataType> *cursor = head;
    while (cursor != nullptr) {
        if (cursor->getData() == target) {
            return cursor;
        }
        cursor = cursor->getNext();
    }
    return nullptr;
}

template<typename DataType>
void List<DataType>::headInsert(DataType value) {
    Node<DataType> *temp = new Node<DataType>(value);
    temp->setNext(head);
    head = temp;
}

template<typename DataType>
void List<DataType>::insert(DataType value) { headInsert(value); }

template<typename DataType>
void List<DataType>::insertAfter(Node<DataType> *previous, DataType value) {
    Node<DataType> *temp = new Node<DataType>(value);
    if (previous != nullptr) {
        temp->setNext(previous->getNext());
        previous->setNext(temp);
    }
}

template<typename DataType>
void List<DataType>::deleteNode(Node<DataType> *current) {
    if (current == nullptr) {  // nothing to delete
        return;
    }
    if (current == head) {  // first node
        head = current->getNext();
        delete current;
    } else {  // find the previous pointer of  current
        Node<DataType> *previous = head;
        while (previous->getNext() != current) {
            previous = previous->getNext();
        }
        // skip over current in the list and delete it
        previous->setNext(current->getNext());
        delete current;
    }
}
