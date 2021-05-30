/**
 *   @file: Dlist.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class DList implementation uses the DNode class to create a doubly
 *          linked Dlist.
 */


#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "dlist.h"

using namespace std;
DList::DList(DNode *newHead) { head = newHead; }

DList::~DList() {
    // deallocate all the Dnodes
    DNode *cursor = head;
    while (cursor != nullptr) {
        deleteNode(cursor);
        cursor = cursor->getNext();
    }
}

size_t DList::length() const {
    DNode *cursor = head;
    size_t count = 0;
    while (cursor != nullptr) {
        count++;
        cursor = cursor->getNext();
    }
    return count;
}

void DList::output() const {
    DNode *cursor = head;
    while (cursor != nullptr) {
        cout << cursor->getData() << endl;
        cursor = cursor->getNext();
    }
}

DNode *DList::search(int target) {
    DNode *cursor = head;
    while (cursor != nullptr) {
        if (cursor->getData() == target) {
            return cursor;
        }
        cursor = cursor->getNext();
    }
    return nullptr;
}

void DList::headInsert(DNode::DataType value) {
    DNode *temp = new DNode(value, nullptr, nullptr);

    if(head != nullptr) {
        head->setPrevious(temp);
        temp->setNext(head); 
    }
    head = temp;
}

void DList::insert(DNode::DataType value) { headInsert(value); }

void DList::insertAfter(DNode *cursor, DNode::DataType value) {
    if (cursor == nullptr) {
        return;
    }

    DNode *temp;
    temp = new DNode;
    temp->setData(value);
    temp->setNext(cursor->getNext());
    temp->setPrevious(cursor);
    if (cursor->getNext() != nullptr)  // check if at end of list
        cursor->getNext()->setPrevious(temp);
    cursor->setNext(temp);
}

void DList::deleteNode(DNode *cursor) {
    if (cursor == nullptr) {  // nothing to delete
        return;
    }
    if (cursor == head) {  // first node
        head = cursor->getNext();
        if (head != nullptr) //only node?
        {
            head->setPrevious(nullptr);
        }
    } else if (cursor->getNext() == nullptr) {  // end of list
        // find the previous pointer of  cursor
        DNode *previous = cursor->getPrevious();
        previous->setNext(nullptr);
    } else {  // somewhere in the middle
        // skip over cursor in the Dlist and delete it
        DNode *after = cursor->getNext();
        DNode *before = cursor->getPrevious();
        before->setNext(after);
        after->setPrevious(before);
    }
    delete cursor;
}
