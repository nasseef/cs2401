/**
 *   @file: stack.h
 * @author: Nasseef Abukamail
 *   @date: July 17, 2021
 *  @brief: Stack class using linked lists
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "node.h"

using namespace std;

/// Constants and function prototypes


template <typename Item>
class Stack {
   public:
    Stack();
   
    /**
     * size - number of items in the stack
     * @return - number of items in the stack
     */
    size_t size() const { return numItems; }

    /**
     * isEmpty
     * @return - number of items in the stack
     */
    bool isEmpty() const { return numItems == 0; }

    /**
     * push - adds an item to the stack
     * @param - item to be added
     */
    void push(const Item &entry);

    /**
     * pop - removes an item from the stack and returns it
     */
    Item pop();

    /**
     * peek - returns the top item of the stack without removing it.
     */
    Item peek() const;

   private:
    Node<Item> *topPtr;
    size_t numItems;
};

template <typename Item>
Stack<Item>::Stack() {
    topPtr = nullptr;
    numItems = 0;
}




template <typename Item>
void Stack<Item>::push(const Item &entry) {
    // insert at the begining
    Node<Item> *temp = new Node<Item>(entry, topPtr);
    topPtr = temp;
    numItems++;
}

template <typename Item>
Item Stack<Item>::pop() {
    assert(!isEmpty());
    Node<Item> *delPtr = topPtr;
    Item topItem = topPtr->getData();
    topPtr = topPtr->getNext();
    delete delPtr;
    numItems--;
    return topItem;
}

template <typename Item>
Item Stack<Item>::peek() const {
    assert(!isEmpty());
    return topPtr->getData();
}

