#include "Dice.h"
#include <time.h>
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

Dice::Dice(int Number)
{
    this->Number = Number;
}
void Dice::rollOne()            //Funkcja s�u��ca do rzucania jedn� ko�ci� w zale�no�ci czy chcemy j� zostawi� czy te� nie
        {
            if(GetChange()== true)
                Setscore(Getscore());
            if(GetChange()==false && GetNumber()>0)
            Setscore(rand()%6+1);
        }
Dice::~Dice()
{
    //dtor
}
