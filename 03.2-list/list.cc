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
List::List(Node *newHead) { head = newHead; }

List::~List() {
    // deallocate all the nodes
    Node *cursor = head;
    while (cursor != nullptr) {
        deleteNode(cursor);
        cursor = cursor->getNext();
    }
}

size_t List::length() const {
    Node *cursor = head;
    size_t count = 0;
    while (cursor != nullptr) {
        count++;
        cursor = cursor->getNext();
    }
    return count;
}

void List::output() const {
    Node *cursor = head;
    while (cursor != nullptr) {
        cout << cursor->getData() << endl;
        cursor = cursor->getNext();
    }
}

Node *List::search(int target) {
    Node *cursor = head;
    while (cursor != nullptr) {
        if (cursor->getData() == target) {
            return cursor;
        }
        cursor = cursor->getNext();
    }
    return nullptr;
}

void List::headInsert(Node::DataType value) {
    Node *temp = new Node(value);
    temp->setNext(head);
    head = temp;
}

void List::insert(Node::DataType value) { headInsert(value); }

void List::insertAfter(Node *previous, Node::DataType value) {
    Node *temp = new Node(value);
    if (previous != nullptr) {
        temp->setNext(previous->getNext());
        previous->setNext(temp);
    }
}

void List::deleteNode(Node *current) {
    if (current == nullptr) {  // nothing to delete
        return;
    }
    if (current == head) {  // first node
        head = current->getNext();
        delete current;
    } else {  // find the previous pointer of  current
        Node *previous = head;
        while (previous->getNext() != current) {
            previous = previous->getNext();
        }
        // skip over current in the list and delete it
        previous->setNext(current->getNext());
        delete current;
    }
}
