
#include <iostream>
#include "map.h"
#include "Whale.h"
#include "Plankton.h"
#include <time.h>
#include <stdlib.h>
#include "MyException.h"
using namespace std;
template <class Creature>
bool checkPressence(std::vector<Creature>& vCreature, int& creature_X, int& creature_Y, Map& userMap)
{
    if (vCreature.empty()==true)
        return false;
    for (int i = 0; i < vCreature.size(); i++)
    {
        int xR = vCreature[i].getX();
        int yR = vCreature[i].getY();
        if ((creature_X == xR) && (creature_Y == yR))
        {
            return true;
        }
    }
    return false;
}
void menu(vector<Plankton> vPlankton, vector<Whale> vWhale, Map userMap);
void start()
{
    Map userMap;

    userMap.userLength = 1;
    userMap.userWidth = 1;

    do
    {
        cout << "Enter length of the field: ";
        cin >> userMap.userLength;
        if ((!cin) || (userMap.userLength < 1))
        {
            throw MyInputException();
        }

        cout << "Enter width of the field: ";
        cin >> userMap.userWidth;
        if ((!cin) || (userMap.userWidth < 1))
        {
            throw MyInputException();
        }
        if ((userMap.userLength == 1) && (userMap.userWidth == 1))
        {
            cout << "Too small field. Try again." << endl;
        }
    } while ((userMap.userLength == 1) && (userMap.userWidth == 1));

    cout << "Enter time which whale can survive without food: ";
    cin >> userMap.userHungerTime;
    if ((!cin) || (userMap.userHungerTime < 1))
    {
        throw MyInputException();
    }

    cout << "Enter the time needed for a new plankton to be born: ";
    cin >> userMap.userBirthTime;
    if ((!cin) || (userMap.userBirthTime < 1))
    {
        throw MyInputException();
    }

    cout << "Enter HP to reduce: ";
    cin >> userMap.HPreduce;
    if ((!cin) || (userMap.HPreduce <= 0))
    {
        throw MyInputException();
    }

    int wCount, pCount;
    cout << "Enter starting whale count: " << endl;
    cin >> wCount;
    if ((!cin) || (wCount<=0))
    {
        throw MyInputException();
    }
    cout << "Enter starting plankton count: " << endl;
    cin >> pCount;
    if ((!cin) || (pCount > (userMap.userLength * userMap.userWidth)) || (pCount <= 0))
    {
        throw MyInputException();
    }
    vector<Plankton> vPlankton;
    while (vPlankton.size()!= pCount)
    {
        int x_plankton = rand() % userMap.userLength + 1;
        int y_plankton = rand() % userMap.userWidth + 1;
        if (checkPressence(vPlankton, x_plankton, y_plankton, userMap) != true)
        {
            Plankton planktonStart(x_plankton, y_plankton);
            vPlankton.push_back(planktonStart);
            cout << "Plankton " << vPlankton.size() << " (" << planktonStart.getHP() << ")" << " (" << x_plankton << ";" << y_plankton << ") has been added" << endl;
        }
    }
    vector<Whale> vWhale;
    for (int i = 0; i < wCount; i++)
    {
        int x_whale = rand() % userMap.userLength + 1;
        int y_whale = rand() % userMap.userWidth + 1;
        Whale whaleStart(x_whale, y_whale);
        vWhale.push_back(whaleStart);
        cout << "Whale " << vWhale.size()  << " (" << x_whale << ";" << y_whale << ") has been added" << endl;
    }
    menu(vPlankton, vWhale, userMap);
}