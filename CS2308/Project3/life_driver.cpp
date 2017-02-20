/****************************************************
Name: Samantha Coyle
Date: 2/28/2017
Problem Number: 3
CS2308
Instructor: Komogortsev, TSU
*****************************************************/

// This is driver's code

#ifdef linux
#define LINUX true
#define WINDOWS false
#endif

#ifdef _WIN32
#define LINUX false
#define WINDOWS true
#endif

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

#include "life.h"

const char FILE_NAME[] = "glider_gun_fight.txt";

using namespace std;

const int NUM_GENERATIONS = 10; //set to a smaller number for debugging

int main()
{
    populateWorld(FILE_NAME);

    showWorld();

    for (int iteration = 0; iteration < NUM_GENERATIONS; iteration++)
    {

        if (WINDOWS)
        	system("cmd.exe /c cls"); //Windows only
        else
           system("clear"); //Linux only
        iterateGeneration();
        showWorld();
    }
    if (WINDOWS)
        system("cmd.exe /c PAUSE");
    return 0;
}

