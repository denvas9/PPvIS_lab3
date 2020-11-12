// Ppvis_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
#include <vector>
#include "Whale.h"
#include "Plankton.h"
#include <time.h>
#include <stdlib.h>
#include "MyException.h"
void start();
void load();
using namespace std;

int main(void)
{
    srand(time(0));
    cout << "Welcome to OceanLife model" << endl
        << "Type '1' if you want to start new model." << endl
        << "Type '3' if you want to load model." << endl
        << "Type '5' if you want to quit program" << endl;
    int command;
    while (true)
    {
        cout << "Please, enter command: ";
        cin >> command;
        if (command == 1)
        {
            try
            {
                start();
            }
            catch (MyInputException& e)
            {
                cout << e.what() << endl;
                cin.clear();
                cin.sync();
            }
        }
        else if (command == 3)
        {
            try
            {
                load();
            }
            catch (MyFileException& e)
            {
                cout << e.what() << endl;
            }
            catch (MyInputException& e)
            {
                cout << e.what() << endl;
            }
        }
        else if (command == 5)
        {
            exit(5);
        }
        else
        {
            cout << "Try again" << endl;
            cin.clear();
            cin.sync();
        }
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
