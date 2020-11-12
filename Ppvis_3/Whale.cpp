#include "Whale.h"

Whale::Whale(int newX, int newY) : Ocean_life(newX, newY)
{
    hunger = 0;
    gender = rand() % 2;
    movementrange = 3;
}
Whale::Whale() : Ocean_life()
{
    hunger = 0;
    gender = rand() % 2;
    movementrange = 3;
}
void Whale::move(Map& userMap)
{
    int newX, newY;
    int distance = 1 + rand() % movementrange;
    chooseMovement(newX, newY, distance, userMap);
    x = newX;
    y = newY;
}
void Whale::setHunger(int set_Hunger)
{
    hunger = set_Hunger;
    return;
}
int Whale::getHunger()
{
    return hunger;
}
int Whale::getGender()
{
    return gender;
}
void Whale::checkPartner(std::vector<Whale>& vWolf, Map& userMap, bool& have_partn)
{
    int xA = getX();
    int yA = getY();
    int gA = getGender();
    int qw = vWolf.size();

    if (gA == 0) return;
    for (int iter = 0; iter < qw; iter++)
    {
        bool lifeW = vWolf[iter].Ocean_life::getLife();
        if (lifeW == true)
        {
            int xW = vWolf[iter].Ocean_life::getX();
            int yW = vWolf[iter].Ocean_life::getY();
            int gW = vWolf[iter].Whale::getGender();

            if ((xA == xW) && (yA == yW) && (gW != gA))
            {
                have_partn = true;
                break;
            }
        }
    }
    return;
}

std::istream& operator >> (std::istream& in, Whale& whale)
{
    int newX;
    int newY;
    bool newLife;
    bool newisNew;
    in >> newX >> newY >> newLife >> whale.hunger >> whale.gender >> newisNew;
    whale.setX(newX);
    whale.setY(newY);
    whale.setLife(newLife);
    whale.setisNew(newisNew);
    return in;
}
std::ostream& operator << (std::ostream& out, Whale& whale)
{
    int x = whale.getX();
    int y = whale.getY();
    bool life = whale.getLife();
    bool isnew = whale.getisNew();
    out << x << " " << y << " " << life << " " << whale.hunger << " " << whale.gender << " " << isnew << std::endl;
    return out;
}