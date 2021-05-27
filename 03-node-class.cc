/**
 *   @file: 03-node-class.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class Node that represents a singular linked list. 
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


int main(int argc, char const *argv[]) {

    Node *temp = new Node(88);

    //create head and link it to temp
    Node *head = new Node();
    head->setData(99);
    head->setNext(temp);
    cout << "First node's data: " << head->getData() << endl;
    cout << "Second node's data: " << head->getNext()->getData() << endl;
    
    return 0;
} /// main

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