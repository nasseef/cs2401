/**
 *   @file: bag.cc
 * @author: Nasseef Abukamail
 *   @date: May 22, 2021
 *  @brief: The Bag class
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class Bag {
   public:
   static const size_t CAPACITY = 1000;  //shared with all objects
    /**
     * Bag: Initialize the bag to an empty array
     */
    Bag();

    /**
     * size - return the size of the bag
     * @return - return the number of values in the bag
     */
    size_t size() const;

    /**
     * insert - insert a value to the bag if capacity is not reached
     * @param value - new value to be added
     */
    bool insert(const int value);

    /**
     * erase - removes a single value from the bag
     * @param target - the value to be removed
     * @return - return true if the operation succeeds
     */
    bool erase(const int target);

    /**
     * eraseAll - remove all the values matching the target value
     * @param target - the value to be removed
     * @return - return true if the operation succeeds
     */
    bool eraseAll(const int target);

    /**
     * operator += - add content of a bag to another without exceeding capacity
     * @param otherBag - a bag of values
     */
    void  operator +=(const Bag &otherBag);

    /**
     * operator << - output the content of the bag in a nice format
     * @param out - output stream
     * @param b - a bag object to be output
     * @return - return the stream
     */
    friend ostream& operator <<(ostream &out, const Bag &b);

    private:
    int data[CAPACITY];
    size_t used;
};
/// Constants and function prototypes

int main(int argc, char const *argv[]) {
    Bag b1;
    b1.insert(10);
    b1.insert(20);
    b1.insert(20);
    b1.insert(20);
    b1.insert(10);
    b1.insert(5);
    b1.insert(15);
    b1.insert(20);
    cout << "b1: " << b1 << endl;
    //return 0;
    cout << "After erasing 10" << endl;
    if(b1.erase(10)){
        cout << "10 was removed from the bag" << endl;
    }
    else {
        cout << "10 was not found in the bag" << endl;
    }
    
    cout << "b1: " << b1 << endl;

    //return 0;
    cout << "After erasing all 20's" << endl;
    if (b1.eraseAll(20)){
        cout << "Eraseall succeeded, all occurrences of 20 removed" << endl;
    }
    else{
        cout << "EraseAll failed" << endl;
    }
    cout << "b1: " << b1 << endl;
    return 0;

    //testing += operator
    Bag b2;
    b2.insert(40);
    b2.insert(50);
    b2.insert(60);
    b2.insert(20);

    //let's add b2 to b1
    b1 += b2;
    cout << "b1 + b2: " << b1 << endl;

    return 0;
}  /// main

Bag::Bag(){
    used = 0;
}

size_t Bag::size() const {
    return used;
}

bool Bag::insert(const int value){
    if (used < CAPACITY)
    {
        data[used] = value;
        used++;
        return true;
    }
    return false;
}

bool Bag::erase(const int target){
    for (size_t i = 0; i < used; i++)
    {
        if (target == data[i])
        {
            used--;
            data[i] = data[used]; //move the last one in its place
            return true;
        }
    }
    return false;
}
bool Bag::eraseAll(const int target){
    size_t originalSize = used;
    size_t i = 0;
    while (i < used)
    {
        if (target == data[i])
        {
            used--;
            data[i] = data[used]; //move the last one in its place
        }
        else {
            i++;
        }
    }
    
    return used < originalSize;
}


void Bag::operator +=(const Bag &otherBag){
    //only add them if within capacity, otherwise ignore
    if (used + otherBag.used <= CAPACITY)
    {
        for (size_t i = 0; i < otherBag.used; i++)
        {
            insert(otherBag.data[i]);
        }
    }
}


ostream& operator <<(ostream &out, const Bag &b){
    out << "[";
    if (b.used > 0)
    {
        out << b.data[0];
    }
    
    for (size_t i = 1; i < b.used; i++)
    {
        out << ", " << b.data[i];
    }
    out << "]";
    return out;
}