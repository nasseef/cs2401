/**
 *   @file: Baseball-player.h
 * @author: Nasseef Abukamail
 *   @date: July 21, 2021
 *  @brief: Add Description
 */
#ifndef BASEBALL_PLAYER_H
#define BASEBALL_PLAYER_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "athlete.h"

using namespace std;

class BaseballPlayer : public Athlete{
public:
    BaseballPlayer(string newName, size_t newAge, double newBattingAverage);
    double getBattingAverage() {return battingAverage;}
    void setBattingAverage(double newBattingAverage){battingAverage = newBattingAverage;}
    void display();
private:
    double battingAverage;
};

BaseballPlayer::BaseballPlayer(string newName, size_t newAge, double newBattingAverage)
    :Athlete(newName, newAge){
    battingAverage = newBattingAverage;
}

void BaseballPlayer::display(){
    Athlete::display();
    cout << "Batting average: " << battingAverage << endl;
}
#endif