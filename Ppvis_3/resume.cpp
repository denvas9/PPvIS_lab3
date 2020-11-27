
#include <iostream>
#include "Whale.h"
#include "Plankton.h"
#include <vector>
#include "map.h"
using namespace std;
void menu(vector<Plankton> vPlankton, vector<Whale> vWhale, Map userMap);
// 
void resume(vector<Plankton>& vPlankton, vector<Whale>& vWhale, Map userMap)
{
    cout << endl;
    //Phase 1: Everything is moving
    cout << "Phase 1: Moving" << endl;
    int plankton_iter, whale_iter;
    for (plankton_iter = 0; plankton_iter < vPlankton.size(); plankton_iter++)
    {
        if (vPlankton[plankton_iter].getLife() == true)
        {
            vPlankton[plankton_iter].move(userMap, vPlankton);
            int xR = vPlankton[plankton_iter].getX();
            int yR = vPlankton[plankton_iter].getY();
            cout << "Plankton " << plankton_iter + 1 << " (" << vPlankton[plankton_iter].getHP() << ")" << " moved to (" << vPlankton[plankton_iter].getX() << ";" << vPlankton[plankton_iter].getY() << ")" << endl;
        }
    }
    for (int whale_iter = 0; whale_iter < vWhale.size(); whale_iter++)
    {
        if (vWhale[whale_iter].getLife() == true)
        {
                    vWhale[whale_iter].move(userMap);
                    cout << "Whale " << whale_iter + 1 << " moved to (" << vWhale[whale_iter].getX() << ";" << vWhale[whale_iter].getY() << ")" << endl;
        }
    }
    //Phase 2: Whales are eating (if there's anything to eat)
    cout << "Phase 2: Eating" << endl;
    for (whale_iter = 0; whale_iter < vWhale.size(); whale_iter++)
    {
        if (vWhale[whale_iter].getLife() == true)
        {
            int x_whale = vWhale[whale_iter].getX();
            int y_whale = vWhale[whale_iter].getY();
            for (plankton_iter = 0; plankton_iter < vPlankton.size(); plankton_iter++)
            {
                bool lifeR = vPlankton[plankton_iter].getLife();
                if (lifeR == true)
                {
                    int x_plankton = vPlankton[plankton_iter].getX();
                    int y_plankton = vPlankton[plankton_iter].getY();
                    if ((x_whale == x_plankton) && (y_whale == y_plankton))
                    {
                        vPlankton[plankton_iter].setLife(false);
                        cout << "Plankton " << plankton_iter + 1 << " (" << x_plankton << ";" << y_plankton
                            << ") has been eaten by Whale " << whale_iter + 1
                            << " (" << x_whale << ";" << y_whale << ")" << endl;
                        vWhale[whale_iter].setHunger(-1);
                        break;
                    }
                }
            }
        }
    }
    //Phase 3: EXPANSION
    cout << "Phase 3: EXPANSION" << endl;
    for (plankton_iter = 0; plankton_iter < vPlankton.size(); plankton_iter++)
    {
        if (vPlankton[plankton_iter].getLife() == true)
        {
            if (vPlankton[plankton_iter].getTimeFromBirth() == userMap.userBirthTime)
            {
                int x_plankton = vPlankton[plankton_iter].getX();
                int y_plankton = vPlankton[plankton_iter].getY();
                bool positions[9];
                vector<int> restHPPlankton_iters;
                int birth_indicat = 1;
                vPlankton[plankton_iter].PlanktonCheck(vPlankton, userMap, positions, restHPPlankton_iters);
                int rnd_choice = rand() % 2;
                if (rnd_choice == 0)
                {
                    int newX, newY;
                    vPlankton[plankton_iter].checkCoordforNewBirth(vPlankton, userMap, positions);
                    vPlankton[plankton_iter].producePlankton(newX, newY, positions);
                    if ((newX != x_plankton) || (newY != y_plankton))
                    {
                        Plankton tempPlankton(newX, newY);
                        vPlankton.push_back(tempPlankton);
                        cout << "Plankton " << vPlankton.size() << " (" << tempPlankton.getHP() << ")" << " (" << tempPlankton.getX() << ";"
                            << tempPlankton.getY() << ") has been born from Plankton " << plankton_iter + 1
                            << " (" << vPlankton[plankton_iter].getX() << ";" << vPlankton[plankton_iter].getY() << ")" << endl;
                        birth_indicat = 0;

                        vPlankton[vPlankton.size()-1].setisNew(true);
                        vPlankton[vPlankton.size()-1].setTimeFromBirth(-1);
                    }
                }
                if ((rnd_choice == 1) || (birth_indicat == 1))
                {
                    int rnd_restPlnk = rand() % restHPPlankton_iters.size();
                    int restoringPlanktonIter = restHPPlankton_iters[rnd_restPlnk];
                    vPlankton[restoringPlanktonIter].restoreHP();
                    cout << "Plankton " << plankton_iter + 1 << " (" << vPlankton[plankton_iter].getHP() << ")" << " (" << vPlankton[plankton_iter].getX() << ";" << vPlankton[plankton_iter].getY() << ")" << " restored HP for Plankton " << restoringPlanktonIter + 1 << endl;
                    vPlankton[restoringPlanktonIter].setisNew(true);
                }
                vPlankton[plankton_iter].setTimeFromBirth(0);
            }
            else
            vPlankton[plankton_iter].setTimeFromBirth(vPlankton[plankton_iter].getTimeFromBirth() + 1);
        }
    }
    for (whale_iter = 0; whale_iter < vWhale.size(); whale_iter++)
    {
        if ((vWhale[whale_iter].getLife() == true) && (vWhale[whale_iter].getisNew() == false))
        {
            int x_whale = vWhale[whale_iter].getX();
            int y_whale = vWhale[whale_iter].getY();
            bool have_partn = false;
            vWhale[whale_iter].checkPartner(vWhale, userMap, have_partn);
            if (have_partn == true)
                            {
                                vWhale.push_back(Whale(x_whale, y_whale));
                                cout << "Whale " << vWhale.size() << " (" << x_whale << ";" << y_whale
                                    << ") has been born from Whale " << whale_iter + 1
                                    << " (" << x_whale << ";" << y_whale << ")" << endl;
                            }
            vWhale[vWhale.size() - 1].setisNew(true);
        }
    }
    for (whale_iter = 0; whale_iter < vWhale.size(); whale_iter++)
    {
            vWhale[whale_iter].setisNew(false);
    }
    //Phase 4: DYING
    cout << "Phase 4: DYING" << endl;
    for (plankton_iter = 0; plankton_iter < vPlankton.size(); plankton_iter++)
    {
        if ((vPlankton[plankton_iter].getLife() == true) && (vPlankton[plankton_iter].getisNew()==false))
        {
            vPlankton[plankton_iter].reduceHP(userMap.HPreduce);
            cout << "Plankton " << plankton_iter + 1 << " (" << vPlankton[plankton_iter].getX() << ";" << vPlankton[plankton_iter].getY() << ")" << " lost " << userMap.HPreduce << " HP" << endl;
            if (vPlankton[plankton_iter].getHP() == 0)
            {
                int xR = vPlankton[plankton_iter].getX();
                int yR = vPlankton[plankton_iter].getY();
                vPlankton[plankton_iter].setLife(false);
                cout << "Plankton " << plankton_iter + 1 << " (" << vPlankton[plankton_iter].getX() << ";" << vPlankton[plankton_iter].getY() << ")" << " lost all HP and died" << endl;
            }
        }
    }
    for (whale_iter = 0; whale_iter < vWhale.size(); whale_iter++)
    {
        if ((vWhale[whale_iter].getLife() == true) && (vWhale[whale_iter].getisNew() == false))
        {
                if (vWhale[whale_iter].getHunger() == userMap.userHungerTime)
                {
                    vWhale[whale_iter].setLife(false);
                    cout << "Whale " << whale_iter + 1 << " (" << vWhale[whale_iter].getX() << ";" << vWhale[whale_iter].getY() << ")" << " died from hunger" << endl;
                }
                if (vWhale[whale_iter].getLife() == true)
                {
                    vWhale[whale_iter].setHunger(vWhale[whale_iter].getHunger() + 1);
                }
        }
    }

    for (whale_iter = 0; whale_iter < vWhale.size(); whale_iter++)
    {
        vWhale[whale_iter].setisNew(false);
    }
    for (plankton_iter = 0; plankton_iter < vPlankton.size(); plankton_iter++)
    {
        vPlankton[plankton_iter].setisNew(false);
    }
   
    cout << endl;
    menu(vPlankton, vWhale, userMap);
}