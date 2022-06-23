#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "Dice.h"
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

void showHand(Dice d1,Dice d2,Dice d3,Dice d4,Dice d5);
char rollOption(char g);
void wrongOption();
int calcUpperScore(int diceToScore, Dice d1,Dice d2,Dice d3,Dice d4,Dice d5);
int calcSumDices(Dice d1,Dice d2,Dice d3,Dice d4,Dice d5);
void writeToArray(int arr[5],Dice d1,Dice d2,Dice d3,Dice d4,Dice d5);
int smallStraight(vector<int> v,Dice d1,Dice d2,Dice d3,Dice d4,Dice d5);
int bigStraight(vector<int> v,Dice d1,Dice d2,Dice d3,Dice d4,Dice d5);
bool cmp(pair<string, int>& a, pair<string, int>& b);


#endif // FUNCTIONS_H_INCLUDED
