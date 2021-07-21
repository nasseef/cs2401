/**
 *   @file: stack.h
 * @author: Nasseef Abukamail
 *   @date: July 17, 2021
 *  @brief: Add Description
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

/// Constants and function prototypes

const int CAPACITY = 64;

template <typename Item>
class Stack {
   public:
    Stack() { top = -1; }

    void push(const Item& entry);
    Item pop();
    size_t size() const { return top + 1; }
    bool isEmpty() const { return top == -1; }
    Item peek() const;

   private:
    Item data[CAPACITY];
    int top;
};

template <typename Item>
void Stack<Item>::push(const Item& entry) {
    assert(top < CAPACITY - 1);
    top++;
    data[top] = entry;
}

template <typename Item>
Item Stack<Item>::pop() {
    assert(!isEmpty());
    top--;
    return data[top + 1];
}

template <typename Item>
Item Stack<Item>::peek() const {
    assert(!isEmpty());
    return data[top];
}
