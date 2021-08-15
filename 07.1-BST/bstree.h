/**
 *   @file: bstree.h
 * @author: Nasseef Abukamail
 *   @date: August 05, 2021
 *  @brief: Binary search tree class
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "bnode.h"
using namespace std;

template <typename DataType>
class BSTree {
public:
    BSTree() { root = nullptr; }

    BNode<DataType>* search(DataType target) {return treeSearch(root, target);}
    
    void insert(DataType newData){treeInsert(root, newData);}
    
    void print(){printPostorder(root);}
    
    size_t size(){return treeSize(root);}

private:
    void treeInsert(BNode<DataType>* &root, DataType newData);
    BNode<DataType>* treeSearch(BNode<DataType>* &root, DataType newData);
    size_t treeSize(BNode<DataType> * root);
    void printInorder(BNode<DataType> * root);
    void printPreorder(BNode<DataType> * root);
    void printPostorder(BNode<DataType> * root);

    BNode<DataType>* root;
};
template <typename DataType>
void BSTree<DataType>::treeInsert(BNode<DataType>* &root, DataType newData) {
    if (root == nullptr) {
        root = new BNode<DataType>(newData, nullptr, nullptr);
        return;
    }

    if (newData < root->data)  // insert at the left subtree
    {
        treeInsert(root->left, newData);
    } else if (newData > root->data){
        treeInsert(root->right, newData);
    }
    //else, already in the tree, ignore it
}
template <typename DataType>
BNode<DataType>* BSTree<DataType>::treeSearch(BNode<DataType>* &root, DataType target) {
    if (root == nullptr) { //tree is empty
        return nullptr;
    }
    if (target == root->data) //found the target
    {
        return root;
    }
    if (target < root->data)  // search the left subtree
    {
        return treeSearch(root->left, target);
    }
    else { //search the right subtree
        return treeSearch(root->right, target);
    }
   
}


template <typename DataType>
void BSTree<DataType>::printPreorder(BNode<DataType>* root) {
    if (root != nullptr)
    {
        cout << setw(4) << root->data;
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

template <typename DataType>
void BSTree<DataType>::printInorder(BNode<DataType>* root) {
    if (root != nullptr)
    {
        printInorder(root->left);
        cout << setw(4) << root->data;
        printInorder(root->right);
    }
}
template <typename DataType>
void BSTree<DataType>::printPostorder(BNode<DataType>* root) {
    if (root != nullptr)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << setw(4) << root->data;
    }
}
template <typename DataType>
size_t BSTree<DataType>::treeSize(BNode<DataType>* root) {
    if(root == nullptr){
        return 0;
    }
    return 1 + treeSize(root->left) + treeSize(root->right);

}
