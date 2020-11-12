
#include <iostream>
#include <vector>
#include "Whale.h"
#include "Plankton.h"
#include "map.h"
using namespace std;

void start();
void save(vector<Plankton> vFirstLifeForm, vector<Whale> vSecondLifeForm, Map userMap);
void load();
void resume(vector<Plankton>& vFirstLifeForm, vector<Whale>& vSecondLifeForm, Map userMap);

void menu(vector<Plankton> vFirstLifeForm, vector<Whale> vSecondLifeForm, Map userMap)
{
    unsigned int command;
    cout << "Commands: '1'-start_new; '2'-save; '3'-load; '0'-resume; '5'-quit." << endl;
    while (true)
    {
        cout << "Please, enter command: ";
        cin >> command;
        if (command == 1)
        {
            start();                            // start new simulation
        }
        else if (command == 2)
        {
            save(vFirstLifeForm, vSecondLifeForm, userMap);    // save
        }
        else if (command == 3)
        {
            load();                             // load
        }
        else if (command == 0)
        {
            resume(vFirstLifeForm, vSecondLifeForm, userMap);  // next turn
        }
        else if (command == 5)
        {
            exit(5);                          // exit  
        }
        else
        {
            cout << "Try again" << endl;
            cin.clear();
            cin.sync();
        }
    }
}