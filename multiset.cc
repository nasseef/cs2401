/**
 *   @file: multiset.cc
 * @author: Nasseef Abukamail
 *   @date: May 25, 2021
 *  @brief: Demonstrate multiset class
 */
#include <fstream>
#include <iostream>
#include <set>  //includes  set and multiset
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

    multiset<string> names;
    names.insert("Jack");
    names.insert("Janet");
    names.insert("Chrissy");
    names.insert("Jack");
    
    // Iterate over all names in the list (sorted)
    // the iterator is of type: multiset<string>::iterator or we can use
    // auto and have C++ determine the type
    for (auto iter = names.begin(); iter != names.end(); iter++) {
        string word = *iter;
        cout << word << endl;
    }

    cout << "After erasing the first element 'Chrissy' should be removed" << endl;
    names.erase(names.begin());
    for (auto iter = names.begin(); iter != names.end(); iter++) {
        string word = *iter;
        cout << word << endl;
    }
    cout << "Size: " << names.size() << endl;
    
}
