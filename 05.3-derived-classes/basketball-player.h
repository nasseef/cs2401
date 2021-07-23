/**
 *   @file: basketball-player.h
 * @author: Nasseef Abukamail
 *   @date: July 21, 2021
 *  @brief: Add Description
 */
#ifndef BASKETBALL_PLAYER_H
#define BASKETBALL_PLAYER_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "athlete.h"

using namespace std;

class BasketballPlayer : public Athlete{
public:
    BasketballPlayer(string newName, size_t newAge, double newPpg);
    double getPpg() {return ppg;}
    void setPpg(double newPpg){ppg = newPpg;}
    void display();
private:
    double ppg;
};

BasketballPlayer::BasketballPlayer(string newName, size_t newAge, double newPpg)
    :Athlete(newName, newAge){
    ppg = newPpg;
}

void BasketballPlayer::display(){
    Athlete::display();
    cout << "PPG: " << ppg << endl;
}
#endif