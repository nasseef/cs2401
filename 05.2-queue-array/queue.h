/**
 *   @file: queue.h
 * @author: Nasseef Abukamail
 *   @date: July 21, 2021
 *  @brief: Circular array implementation of queues
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

const int CAPACITY = 30;
template <typename Item>
class Queue {
   public:
    Queue();
    void push(const Item& entry);
    Item pop();
    Item peek();
    size_t size() const { return numItems; }
    bool isEmpty() const { return (numItems == 0); }

   private:
    Item data[CAPACITY];  // Partially-filled array
    size_t front;         // Index of item at front of the queue
    size_t rear;          // Index of item at rear of the queue
    size_t numItems;      // Total number of items in the queue

    size_t nextIndex(size_t index) const { return (index + 1) % CAPACITY; }
};

template <class Item>
Queue<Item>::Queue( )
{
    numItems = 0;
    front = 0;
    rear = CAPACITY - 1;
}
template <class Item>
void Queue<Item>::push(const Item& entry)
{
    assert(size( ) < CAPACITY);
    rear = nextIndex(rear);
    data[rear] = entry;
    numItems++;
}
template <class Item>
Item Queue<Item>::pop( )
{
    assert(!isEmpty( ));
    Item removedItem = data[front];

    front = nextIndex(front);
    numItems--;    
    return removedItem;
}
template <class Item>
Item Queue<Item>::peek( )
{
    assert(!isEmpty( ));
    return data[front];
}

