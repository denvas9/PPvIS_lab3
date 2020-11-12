#include <fstream>
#include <iostream>
#include "Whale.h"
#include "Plankton.h"
#include <vector>
#include "map.h"
using namespace std;
void menu(vector<Plankton> vPlankton, vector<Whale> vWhale, Map UserMap);
void save(vector<Plankton> vPlankton, vector<Whale> vWhale, Map userMap)
{
    ofstream out("save.txt");
    if (!out)
    {
        cout << "Can't create Saveile!";
        menu(vPlankton, vWhale, userMap);
    }
    int qr = vPlankton.size();
    int qw = vWhale.size();
    out << userMap << qr << " " << qw << endl;
    for (int i = 0; i < qr; i++)
    {
        out << vPlankton[i] << endl;
    }
    for (int i = 0; i < qw; i++)
    {
        out << vWhale[i] << endl;
    }
    cout << "File with all content has been saved!" << endl;
    return;
}