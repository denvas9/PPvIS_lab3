#pragma once

#ifndef MAP_H
#define MAP_H

#include <fstream>

class Map
{
    public:
    int userLength;        // length of field
    int userWidth;         // width of field
    int userHungerTime;    // time for a whale to die from hunger
    int userBirthTime;     // time for plankton to reproduce
    int HPreduce;          // how much HP to reduce each turn for plankton

    friend std::istream& operator >> (std::istream& in, Map& userMap); //read from file
    friend std::ostream& operator << (std::ostream& out, Map& userMap); //write to file
};

#endif