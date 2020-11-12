#pragma once

#ifndef PLANKTON_H
#define PLANKTON_H

#include "Ocean_life.h"
#include <fstream>

class Plankton : public Ocean_life
{
    int timeFromBirth;  // time passed after reproduction (restoration)
    int HP; // Health
public:
    Plankton(int newX, int newY);
    Plankton();
    // ~Plankton();
    int getTimeFromBirth(); //returns time passed after reproduction (restoration)
    void setTimeFromBirth(int temp); //sets time passed after reproduction (restoration)
    int getHP(); // returns HP
    void restoreHP();// sets HP back to 100
    void reduceHP(int reducing); // reduces HP
    void move(Map& userMap, std::vector<Plankton>& vPlankton); // plankton movement
    void checkCoordforNewBirth(std::vector<Plankton>& vRabbit, Map& userMap, bool* poz); // determines which tiles are suitable for reproduction
    void PlanktonCheck(std::vector<Plankton>& vRabbit, Map& userMap, bool* poz, std::vector<int>& restRabX_iter); // determines plankton prescence on nearby tiles for possible restoration
    void producePlankton(int& newX, int& newY, bool* poz); // chooses a tile for reproduction
    void planktonMovement(std::vector<Plankton>& vPlankton, int& newX, int& newY, Map& userMap); // chooses a tile for movement

    friend std::istream& operator >> (std::istream& in, Plankton& plankton); //read from file
    friend std::ostream& operator << (std::ostream& out, Plankton& plankton); //write to file
};
#endif