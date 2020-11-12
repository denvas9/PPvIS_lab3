#pragma once

#ifndef WHALE_H
#define WHALE_H

#include "Ocean_life.h"
#include <fstream>
class Whale :public Ocean_life
{
private:
protected:
    int movementrange; //max movement range
    int hunger; // Hunger
    int gender; // gender (0 (male) and 1 (female) )
public:
    Whale(int newX, int newY);
    Whale();
    //~Whale();
    void move(Map& userMap);            // movement
    int getGender();                  // return gender
    int getHunger();                 // return time without food
    void checkPartner(std::vector<Whale>& vWolf, Map& userMap, bool& have_partn); //check for a partner for reproduction
    void setHunger(int set_Hunger);      // set time without food

    friend std::istream& operator >> (std::istream& in, Whale& whale); //read from file
    friend std::ostream& operator << (std::ostream& out, Whale& whale); //write to file
};
#endif