#include "Ocean_life.h"
#include <stdlib.h>
#include <time.h>
#include "map.h"

Ocean_life::Ocean_life()
{
    x = 0;
    y = 0;
    life = true;
    isNew = false;
}
Ocean_life::Ocean_life(int newX, int newY)
{
    x = newX;
    y = newY;
    life = true;
    isNew = false;
}
void Ocean_life::setX(int xA)
{
    x = xA;
    return;
}
void Ocean_life::setY(int yA)
{
    y = yA;
    return;
}
void Ocean_life::setLife(bool newLife)
{
    life = newLife;
    return;
}
int Ocean_life::getY()
{
    return y;
}
int Ocean_life::getX()
{
    return x;
}
bool Ocean_life::getLife()
{
    return life;
}
bool Ocean_life::getisNew()
{
    return isNew;
}
void Ocean_life::setisNew(bool set_isNew)
{
    isNew = set_isNew;
    return;
}
void Ocean_life::chooseMovement(int& newX, int& newY, int dist, Map& userMap)
{
    int xA = getX();
    int yA = getY();
    newX = getX();
    newY = getY();
    bool poz[8];
    for (int pos_num = 0; pos_num < 8; pos_num++)
    {
        poz[pos_num] = true;
    }
    if ((xA - dist) < 1)
    {
        poz[0] = poz[7] = poz[6] = false;
    }
    if ((yA - dist) < 1)
    {
        poz[0] = poz[1] = poz[2] = false;
    }
    if ((xA + dist) > userMap.userLength)
    {
        poz[2] = poz[3] = poz[4] = false;
    }
    if ((yA + dist) > userMap.userWidth)
    {
        poz[6] = poz[5] = poz[4] = false;
    }

    int summpoz = 0;
    for (int pos_num = 0; pos_num < 8; pos_num++)
    {
        if (poz[pos_num] == false)
        {
            summpoz++;
        }
    }
    if (summpoz == 8)
    {
        return;
    }

    int randpoz = rand() % 8;
    int allpoz = 0;
    while (allpoz < 8)
    {
        if (poz[randpoz] == true)
        {
            if (randpoz == 0)
            {
                newX = xA - dist;
                newY = yA - dist;
                break;
            }
            if (randpoz == 1)
            {
                newX = xA;
                newY = yA - dist;
                break;
            }
            if (randpoz == 2)
            {
                newX = xA + dist;
                newY = yA - dist;
                break;
            }
            if (randpoz == 3)
            {
                newX = xA + dist;
                newY = yA;
                break;
            }
            if (randpoz == 4)
            {
                newX = xA + dist;
                newY = yA + dist;
                break;
            }
            if (randpoz == 5)
            {
                newX = xA;
                newY = yA + dist;
                break;
            }
            if (randpoz == 6)
            {
                newX = xA - dist;
                newY = yA + dist;
                break;
            }
            if (randpoz == 7)
            {
                newX = xA - dist;
                newY = yA;
                break;
            }
        }
        else
        {
            allpoz++;
            randpoz++;
            if (randpoz > 7)
            {
                randpoz = 0;
            }
        }
    }
    return;
};






