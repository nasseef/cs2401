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

    Athlete *player1 = new Athlete("Bob", 22);
    cout << "An Athlete" << endl;
    player1->display();
    cout << endl;

    BasketballPlayer *player2 = new BasketballPlayer("Jim", 23, 33.5);
    cout << "A Basketball player" << endl;
    player2->display();
    cout << endl;

    cout << "A Baseball player" << endl;
    BaseballPlayer *player3 = new BaseballPlayer("John", 28, .257);
    player3->display();

    Athlete* players[5];
    players[0] = player1;
    players[1] = player2;
    players[2] = player3;

    for (size_t i = 0; i < 3; i++)
    {
        players[i]->display();
    }
    

    return 0;
} /// main