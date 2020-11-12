#pragma once

#ifndef OCEAN_H
#define OCEAN_H

#include <vector>
#include "map.h"

class Ocean_life
{
protected:
    int x; // object X coordinate
    int y; // object Y coordinate
    bool life;      // is it alive?
    bool isNew;     // has it been born or restored during the current turn?
public:
    Ocean_life(int newX, int newY);
    Ocean_life();
    //virtual ~Ocean_life();

    int getX();      // return X
    int getY();      // return Y
    void setX(int xA);   // set X
    void setY(int yA);   // set Y
    void setLife(bool newLife);   // set life
    bool getLife();           // return life
    void setisNew(bool set_isNew);   // set isNew
    bool getisNew();           // return isNew
    void chooseMovement(int& newX, int& newY, int distance, Map& userMap); // choose a tile for movement
};

#endif