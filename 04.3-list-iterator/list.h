
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
#include <iterator>

#include "node.h"
using namespace std;

template <typename DataType>
class List {
   public:
    // create an iterator for the list class
    template <typename ItDataType>
    class Iterator {
       public:
        //C++ iterator implementation expects these properties
        using iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = Node <ItDataType>;
        using pointer = Node<ItDataType> *;
        using reference = Node<ItDataType> &;
        // initialize the iterator
        Iterator(Node<ItDataType> *initial = nullptr) { current = initial; }

        // Implement the * operator
        ItDataType &operator*() const { return current->getData(); }

        Node<ItDataType> *operator->() { return current; }
        // overload prefix ++ operator as in ++it
        Iterator &operator++() {
            current = current->getNext();
            return *this;
        }
        // overload postfix ++ operator as in it++
        Iterator operator++(int) {
            Iterator original = *this;
            current = current->getNext();
            return original;
        }

        //More operators
        bool operator==(const Iterator other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator other) const {
            return current != other.current;
        }

       private:
        Node<ItDataType> *current;
    };

    /**
     * Constant Iterator
     */
    template <typename ItDataType>
    class ConstIterator {
       public:
        //C++ iterator implementation expects these properties
        using iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = Node <ItDataType>;
        using pointer = Node<ItDataType> *;
        using reference = Node<ItDataType> &;

        // initialize the iterator
        ConstIterator(const Node<ItDataType> *initial = nullptr) { current = initial; }

        // Implement the * operator
        const ItDataType &operator*() const { return current->getData(); }

        const Node<ItDataType> *operator->() const { return current; }
        // overload prefix ++ operator as in ++it
        ConstIterator &operator++() {
            current = current->getNext();
            return *this;
        }
        // overload postfix ++ operator as in it++
        ConstIterator operator++(int) {
            ConstIterator original = *this;
            current = current->getNext();
            return original;
        }

        //More operators
        bool operator==(const ConstIterator other) const {
            return current == other.current;
        }

        bool operator!=(const ConstIterator other) const {
            return current != other.current;
        }

       private:
        const Node<ItDataType> *current;
    };



    List(Node<DataType> *newHead = nullptr);
    ~List();
    //overload the assignment operator (To be completed)

    //Copy constructor (to be completed)

    // Provide an iterator type to be consistant with STL iterators
    // Also, provide begin() and an end() Iterator functions that return
    // the begining of the data and the end of the data
    using iterator = Iterator<DataType>;
    Iterator<DataType> begin() { return Iterator<DataType>(head); }
    Iterator<DataType> end() { return Iterator<DataType>(); }

    //Implement the constant iterator
    using const_iterator = ConstIterator<DataType>;
    ConstIterator<DataType> cbegin() {return ConstIterator<DataType>(head);}
    ConstIterator<DataType> cend() { return ConstIterator<DataType>(); }

    // List algorithms
    size_t length() const;
    void output();
    Node<DataType> *search(DataType target);
    void headInsert(DataType value);
    void insert(DataType value);
    void insertAfter(Node<DataType> *previous, DataType value);
    void deleteNode(Node<DataType> *current);

   private:
    Node<DataType> *head;
};
#include "list.cc"
#endif