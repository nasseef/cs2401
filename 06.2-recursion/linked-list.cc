/**
 *   @file: linked-list.cc
 * @author: Nasseef Abukamail
 *   @date: July 29, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct Node{
    int num;
    Node* next;
};


void headInsert(Node* &head, int item);
void printList(Node* head);
void printListRec(Node* head);
int main(int argc, char const *argv[]) {
    Node* head = nullptr;

    for (size_t i = 5; i > 0; i--)
    {
        headInsert(head, i * i);
    }
    printList(head);
    cout << endl;
    
    cout << "Printing the list recursively" << endl;
    printListRec(head);
    cout << endl;
    return 0;
} /// main

void headInsert(Node* &head, int item){
    Node* temp = new Node();
    temp->num = item;
    temp->next = head;
    head = temp;
}

void printList(Node* head){
    while (head != nullptr)
    {
        //print the first node data
        cout << setw(4) << head->num;

        //print the rest of the list
        head = head->next;
    }
}
void printListRec(Node* head){
    if (head != nullptr) //base case
    {
        printListRec(head->next);
        cout << setw(4) << head->num;
    }
}