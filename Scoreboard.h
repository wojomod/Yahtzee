#ifndef SCOREBOARD_H
#define SCOREBOARD_H
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

class Scoreboard
{
    public:
        string name;
        int yahtzee;
        Scoreboard(string);
        virtual ~Scoreboard();
        int setScore(int, int);
        int getTotalScore();
        void printScoreboard();
        string check(int);
    protected:

    private:
        int aces, twos, threes, fours, fives, sixes, threeKind, fourKind, fullHouse, smallStrt, largeStrt, chance;

};

#endif // SCOREBOARD_H
