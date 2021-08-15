/**
 *   @file: bnode.h
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Class BNode header file that is used in a singular linked list.
 *          Implementation is included
 */

#ifndef BBNODE_H
#define BBNODE_H
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

template <typename DataType>
struct BNode {
    BNode(DataType newData = DataType(), BNode* newLeft = nullptr, BNode* newRight = nullptr){
        data = newData;
        left = newLeft;
        right = newRight;
    }
    DataType data;
    BNode* left;
    BNode* right;
};
#endif