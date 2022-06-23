#ifndef DICE_H
#define DICE_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <map>
#include <algorithm>

using namespace std;

class Dice
{
    public:
        Dice(int Number = 0);
        virtual ~Dice();
        int GetNumber() { return Number; }
        bool GetChange() { return Change; }
        void SetChange(bool val) { Change = val; }
        int Getscore() { return score; }
        void rollOne();
        void Setscore(int val) {score = val;}
    protected:

    private:
        int Number = 0;
        bool Change = false;
        int score = 0;
};

#endif // DICE_H
