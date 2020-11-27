
#include "Plankton.h"

Plankton::Plankton(int newX, int newY) : Ocean_life(newX, newY)
{
    timeFromBirth = 0;
    HP = 100;
}
Plankton::Plankton() : Ocean_life()
{
    timeFromBirth = 0;
    HP = 100;
}
int Plankton::getTimeFromBirth()
{
    return timeFromBirth;
}
void Plankton::setTimeFromBirth(int temp)
{
    timeFromBirth = temp;
}
int Plankton::getHP()
{
    return HP;
}
void Plankton::restoreHP()
{
    HP = 100;
}
void Plankton::reduceHP(int reducing)
{
    HP -= reducing;
}
void Plankton::planktonMovement(std::vector<Plankton>& vPlankton, int& newX, int& newY, Map& userMap)
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
    if ((xA - 1) < 1)
    {
        poz[0] = poz[7] = poz[6] = false;
    }
    if ((yA - 1) < 1)
    {
        poz[0] = poz[1] = poz[2] = false;
    }
    if ((xA + 1) > userMap.userLength)
    {
        poz[2] = poz[3] = poz[4] = false;
    }
    if ((yA + 1) > userMap.userWidth)
    {
        poz[6] = poz[5] = poz[4] = false;
    }


    for (int iter = 0; iter < vPlankton.size(); iter++)
    {
        bool lifeR = vPlankton[iter].Ocean_life::getLife();
        if (lifeR == true)
        {
            int xR = vPlankton[iter].Ocean_life::getX();
            int yR = vPlankton[iter].Ocean_life::getY();

            if (((xA - 1) == xR) && ((yA - 1) == yR))
            {
                poz[0] = false;
            }
            if ((xA == xR) && ((yA - 1) == yR))
            {
                poz[1] = false;
            }
            if (((xA + 1) == xR) && ((yA - 1) == yR))
            {
                poz[2] = false;
            }
            if (((xA + 1) == xR) && (yA == yR))
            {
                poz[3] = false;
            }
            if (((xA + 1) == xR) && ((yA + 1) == yR))
            {
                poz[4] = false;
            }
            if ((xA == xR) && ((yA + 1) == yR))
            {
                poz[5] = false;
            }
            if (((xA - 1) == xR) && ((yA + 1) == yR))
            {
                poz[6] = false;
            }
            if (((xA - 1) == xR) && (yA == yR))
            {
                poz[7] = false;
            }
        }
    }

    int summpoz = 0;
    for (int j = 0; j < 8; j++)
    {
        if (poz[j] == false)
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
                newX = xA - 1;
                newY = yA - 1;
                break;
            }
            if (randpoz == 1)
            {
                newX = xA;
                newY = yA - 1;
                break;
            }
            if (randpoz == 2)
            {
                newX = xA + 1;
                newY = yA - 1;
                break;
            }
            if (randpoz == 3)
            {
                newX = xA + 1;
                newY = yA;
                break;
            }
            if (randpoz == 4)
            {
                newX = xA + 1;
                newY = yA + 1;
                break;
            }
            if (randpoz == 5)
            {
                newX = xA;
                newY = yA + 1;
                break;
            }
            if (randpoz == 6)
            {
                newX = xA - 1;
                newY = yA + 1;
                break;
            }
            if (randpoz == 7)
            {
                newX = xA - 1;
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
void Plankton::producePlankton(int& newX, int& newY, bool* positions)
{
    int xA = getX();
    int yA = getY();
    newX = getX();
    newY = getY();

    int summpoz = 0;
    for (int pos_num = 0; pos_num < 8; pos_num++)
    {
        if (positions[pos_num] == false)
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
        if (positions[randpoz] == true)
        {
            if (randpoz == 0)
            {
                newX = xA - 1;
                newY = yA - 1;
                break;
            }
            if (randpoz == 1)
            {
                newX = xA;
                newY = yA - 1;
                break;
            }
            if (randpoz == 2)
            {
                newX = xA + 1;
                newY = yA - 1;
                break;
            }
            if (randpoz == 3)
            {
                newX = xA + 1;
                newY = yA;
                break;
            }
            if (randpoz == 4)
            {
                newX = xA + 1;
                newY = yA + 1;
                break;
            }
            if (randpoz == 5)
            {
                newX = xA;
                newY = yA + 1;
                break;
            }
            if (randpoz == 6)
            {
                newX = xA - 1;
                newY = yA + 1;
                break;
            }
            if (randpoz == 7)
            {
                newX = xA - 1;
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
void Plankton::move(Map& userMap, std::vector<Plankton>& vPlankton)
{
    int newX, newY;
    planktonMovement(vPlankton, newX, newY, userMap);
    x = newX;
    y = newY;
}
void Plankton::PlanktonCheck(std::vector<Plankton>& vPlankton, Map& userMap, bool* positions, std::vector<int>& restPlank_iter)
{
    int xA = getX();
    int yA = getY();
    int qr = vPlankton.size();

    for (int pos_num = 0; pos_num < 8; pos_num++)
    {
        positions[pos_num] = false;
    }
    positions[8] = true;
    for (int i = 0; i < qr; i++)
    {
        bool lifeR = vPlankton[i].Ocean_life::getLife();
        if (lifeR == true)
        {
            int xR = vPlankton[i].Ocean_life::getX();
            int yR = vPlankton[i].Ocean_life::getY();

            if (((xA - 1) == xR) && ((yA - 1) == yR))
            {
                positions[0] = true;
                restPlank_iter.push_back(i);
            }
            if ((xA == xR) && ((yA - 1) == yR))
            {
                positions[1] = true;
                restPlank_iter.push_back(i);
            }
            if (((xA + 1) == xR) && ((yA - 1) == yR))
            {
                positions[2] = true;
                restPlank_iter.push_back(i);
            }
            if (((xA + 1) == xR) && (yA == yR))
            {
                positions[3] = true;
                restPlank_iter.push_back(i);
            }
            if (((xA + 1) == xR) && ((yA + 1) == yR))
            {
                positions[4] = true;
                restPlank_iter.push_back(i);
            }
            if ((xA == xR) && ((yA + 1) == yR))
            {
                positions[5] = true;
                restPlank_iter.push_back(i);
            }
            if (((xA - 1) == xR) && ((yA + 1) == yR))
            {
                positions[6] = true;
                restPlank_iter.push_back(i);
            }
            if (((xA - 1) == xR) && (yA == yR))
            {
                positions[7] = true;
                restPlank_iter.push_back(i);
            }
            if ((xA == xR) && (yA == yR))
            {
                restPlank_iter.push_back(i);
            }
        }
    }
    return;
}
void Plankton::checkCoordforNewBirth(std::vector<Plankton>& vPlankton, Map& userMap, bool* positions)
{
    int xA = getX();
    int yA = getY();
    int qr = vPlankton.size();

    for (int iterat = 0; iterat < 8; iterat++)
    {
        positions[iterat] = true;
    }
    positions[8] = false;
    if ((xA - 1) < 1)
    {
        positions[0] = positions[7] = positions[6] = false;
    }
    if ((yA - 1) < 1)
    {
        positions[0] = positions[1] = positions[2] = false;
    }
    if ((xA + 1) > userMap.userLength)
    {
        positions[2] = positions[3] = positions[4] = false;
    }
    if ((yA + 1) > userMap.userWidth)
    {
        positions[6] = positions[5] = positions[4] = false;
    }

    for (int i = 0; i < qr; i++)
    {
        bool lifeR = vPlankton[i].Ocean_life::getLife();
        if (lifeR == true)
        {
            int xR = vPlankton[i].Ocean_life::getX();
            int yR = vPlankton[i].Ocean_life::getY();

            if (((xA - 1) == xR) && ((yA - 1) == yR))
            {
                positions[0] = false;
            }
            if ((xA == xR) && ((yA - 1) == yR))
            {
                positions[1] = false;
            }
            if (((xA + 1) == xR) && ((yA - 1) == yR))
            {
                positions[2] = false;
            }
            if (((xA + 1) == xR) && (yA == yR))
            {
                positions[3] = false;
            }
            if (((xA + 1) == xR) && ((yA + 1) == yR))
            {
                positions[4] = false;
            }
            if ((xA == xR) && ((yA + 1) == yR))
            {
                positions[5] = false;
            }
            if (((xA - 1) == xR) && ((yA + 1) == yR))
            {
                positions[6] = false;
            }
            if (((xA - 1) == xR) && (yA == yR))
            {
                positions[7] = false;
            }
        }
    }
    return;
}

std::istream& operator >> (std::istream& in, Plankton& plankton)
{
    int newX;
    int newY;
    bool newLife;
    bool newisNew;
    in >> newX >> newY >> newLife >> plankton.timeFromBirth >> plankton.HP >> newisNew;
    plankton.setX(newX);
    plankton.setY(newY);
    plankton.setLife(newLife);
    plankton.setisNew(newisNew);
    return in;
}
std::ostream& operator << (std::ostream& out, Plankton& plankton)
{
    int x = plankton.getX();
    int y = plankton.getY();
    bool life = plankton.getLife();
    bool isnew = plankton.getisNew();
    out << x << " " << y << " " << life << " " << plankton.timeFromBirth << " " << plankton.HP << " " << isnew << std::endl;
    return out;
}