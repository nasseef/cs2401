/**
 *   @file: athlete.h
 * @author: Nasseef Abukamail
 *   @date: July 21, 2021
 *  @brief: Add Description
 */
#ifndef ATHLETE_H
#define ATHLETE_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

class Athlete {
   public:
    Athlete(string newName, size_t newAge);
    // getters and setters
    string getName() {return name;}
    size_t getAge() {return age;}
    //..
    void setName(string newName){name = newName;}
    void setAge(size_t newAge){age = newAge;}
    virtual void display();
    
   private:
    string name;
    size_t age;
};
Athlete::Athlete(string newName, size_t newAge){
    name = newName;
    age = newAge;
}
void Athlete::display(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}
#endif