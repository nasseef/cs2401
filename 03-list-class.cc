/**
 *   @file: 03-node-class.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class List uses the Node class to create a singular
 *          linked list.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


class Node
{
public:
    //use the data type int for data, similar to typedef
    using DataType = int; 
    /**
     * Constructor: include default values for data and next
     * @param newData - data being stored, default is the constructor for 
     *                  type, 0 for numbers, false for bool
     * @param newNext - next pointer within the node, default nullptr
     */
    Node(const DataType newData = DataType(), Node * newNext = nullptr);

    //setters
    void setData(const DataType &newData);
    void setNext(Node *newNext);

    //getters
    DataType getData() const;
    const Node* getNext() const; //get the next field as constant
    Node* getNext(); //get the next field

private:
    DataType data;
    Node *next;
};

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



int main(int argc, char const *argv[]) {
    List myList;
    myList.headInsert(50);
    myList.headInsert(40);
    myList.headInsert(30);
    myList.headInsert(20);
    myList.headInsert(10);
    cout << "Length of the list: " << myList.length() << endl;

    cout << "List values" << endl;
    myList.output();

    myList.insert(25);
    Node *searchPtr = myList.search(20);
    if (searchPtr != nullptr)
    {
        cout << "searchPtr value: " << searchPtr->getData() << endl;
    }
    //Insert a new value after 20
    myList.insertAfter(searchPtr, 99);

    
    
    cout << "List values after inserting after 20" << endl;
    myList.output();

    //delete some nodes
    myList.deleteNode(searchPtr);
    cout << "List values after deleting 20" << endl;
    myList.output();
    //try deleting other nodes (first, last, nullptr)
    return 0;
} /// main


List::List(Node *newHead)
{
    head = newHead;
}

List::~List()
{
    //deallocate all the nodes
    Node *cursor = head;
    while(cursor != nullptr){
        deleteNode(cursor);
        cursor = cursor->getNext();
    }
}

size_t List::length() const{
    Node *cursor = head;
    size_t count = 0;
    while (cursor != nullptr)
    {
        count++;
        cursor = cursor->getNext();
    }
    return count;
}

void List::output() const{
    Node *cursor = head;
    while (cursor != nullptr)
    {
        cout << cursor->getData() << endl;
        cursor = cursor->getNext();
    }
}

Node* List::search(int target) {	
    Node *cursor = head;
	while(cursor != nullptr){
	   if(cursor->getData() == target){
		  return cursor;
	   }
	   cursor = cursor->getNext();
	}	
    return nullptr;
}

void List::headInsert(Node::DataType value){
    Node *temp = new Node(value);
    temp->setNext(head);
    head = temp;
}

void List::insert(Node::DataType value){
    headInsert(value);
}

void List::insertAfter(Node *previous, Node::DataType value){
    Node *temp = new Node(value);
    if(previous != nullptr){	
        temp->setNext(previous->getNext());
	    previous->setNext(temp);
    }
}

void List::deleteNode(Node *current){
    if(current == nullptr){//nothing to delete
		return;
	}
	if(current == head){//first node
		head = current->getNext();
		delete current;
	}
    else{ //find the previous pointer of  current
		Node *previous = head;
		while(previous->getNext() != current){
			previous = previous->getNext();
		}
		//skip over current in the list and delete it
		previous->setNext(current->getNext());
		delete current;
	
}

}
/**
 * Node: Node class implementation
 */

Node::Node(const DataType newData, Node * newNext)
{
    data = newData;
    next = newNext;
}


void Node::setData(const DataType &newData){
    data = newData;
}
void Node::setNext(Node *newNext){
    next = newNext;
}

//getters
Node::DataType Node::getData() const{
    return data;
}
const Node* Node::getNext() const{ //get the next field as constant
    return next;
}
Node* Node::getNext(){ //get the next field
    return next;
}