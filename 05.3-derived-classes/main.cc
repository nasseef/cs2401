/**
 *   @file: main.cc
 * @author: Nasseef Abukamail
 *   @date: July 21, 2021
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "athlete.h"
#include "basketball-player.h"
#include "baseball-player.h"
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    Athlete player1("Bob", 22);
    cout << "An Athlete" << endl;
    player1.display();
    cout << endl;

    BasketballPlayer player2("Jim", 23, 33.5);
    cout << "A Basketball player" << endl;
    player2.display();
    cout << endl;

    cout << "A Baseball player" << endl;
    BaseballPlayer player3("John", 28, .257);
    player3.display();
    return 0;
} /// main