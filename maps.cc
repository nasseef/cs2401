/**
 *   @file: maps.cc
 * @author: Nasseef Abukamail
 *   @date: May 26, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unordered_map>
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {
    unordered_map <string, int> map;
    map["Jack"] = 34;
    map["Janet"] = 25;
    map["Chrissy"] = 27;

    //use structured bindings (C++17)
    for(auto [key, value] : map){
        cout << key << ": " << value << endl; 
    }
    cout << "second one" << endl;
    for (auto kv : map)
    {
        cout << kv.first << ": " << kv.second << endl;
    }
    
    /*add code*/
    return 0;
} /// main