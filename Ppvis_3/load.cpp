#include <fstream>
#include "Whale.h"
#include "Plankton.h"
#include <vector>
#include "map.h"
#include "MyException.h"
using namespace std;
void menu(vector<Plankton> vFirstLifeForm, vector<Whale> vSecondLifeForm, Map userMap);
void load()
{
    ifstream in("save.txt");
    if (!in.is_open())
    {
        throw MyFileException();
    }
    Map userMap;
    vector<Plankton> vPlankton;
    vector<Whale> vWhale;
    Plankton tempPlankton;
    Whale tempWhale;
    unsigned int qr;
    unsigned int qw;
    in >> userMap >> qr >> qw;
    if (!in)
    {
        throw MyInputException();
    }
    for (unsigned int i = 0; i < qr; i++)
    {
        in >> tempPlankton;
        if (!in)
        {
            throw MyInputException();
        }
        vPlankton.push_back(tempPlankton);
    }
    for (unsigned int j = 0; j < qw; j++)
    {
        in >> tempWhale;
        if (!in)
        {
            throw MyInputException();
        }
        vWhale.push_back(tempWhale);
    }
    menu(vPlankton, vWhale, userMap); 
    return;
}