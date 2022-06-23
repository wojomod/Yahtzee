#include "functions.h"
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

//Funkcje pomocnicze do zarz¹dzania koœcmi

void showHand(Dice d1,Dice d2,Dice d3,Dice d4,Dice d5){                 //Funkcja do wypisywania wartoœci wszystkich koœci jakie gracz wyrzuci³ w danym rzucie
    cout<<"Pierwsza kosc: "<<d1.Getscore()<<"\n";
    cout<<"Druga kosc: "<<d2.Getscore()<<"\n";
    cout<<"Trzecia kosc: "<<d3.Getscore()<<"\n";
    cout<<"Czwarta kosc: "<<d4.Getscore()<<"\n";
    cout<<"Piata kosc: "<<d5.Getscore()<<"\n\n\n\n\n";
}

char rollOption(char g){                                                            //Funkcja obs³uguj¹ca menu gracza po pierwszym i drugim rzucie
    if(g!='1'){
    char sel = ' ';
    cout<<"\tCo chcesz zrobic?\n\t 1)Wpisac wynik\n\t 2)Rzucic jeszcze raz\n";
    cin>> sel;
    return sel;
    }
    return g;
}

void wrongOption(){
    cout<<"\tPodana wartosc jest nieprawidlowa, prosze wpisz ponownie"<<endl;          //Funkcja do wypisywania b³êdów wartoœci
}

int calcUpperScore(int diceToScore, Dice d1,Dice d2,Dice d3,Dice d4,Dice d5){          //Funkcja do liczenia sumy wartoœci danych koœci
    int score = 0;                                                                     //Na przyk³¹d dla dwóch czwórek to osiem itd
    if(d1.Getscore()== diceToScore)                                                    //U¿ywana jest do wyliczania wyniku dla opcji od 1 do 6 na naszej tablicy wyników
        score = score + diceToScore;
    if(d2.Getscore()== diceToScore)
        score = score + diceToScore;
    if(d3.Getscore()== diceToScore)
        score = score + diceToScore;
    if(d4.Getscore()== diceToScore)
        score = score + diceToScore;
    if(d5.Getscore()== diceToScore)
        score = score + diceToScore;
    return score;
}

int calcSumDices(Dice d1,Dice d2,Dice d3,Dice d4,Dice d5){                              //Funkcja licz¹ca ca³kowit¹ sumê wszystkich koœci
    return d1.Getscore()+d2.Getscore()+d3.Getscore()+d4.Getscore()+d5.Getscore();
}

void writeToArray(int arr[5],Dice d1,Dice d2,Dice d3,Dice d4,Dice d5){                  //Funkcja wpisuj¹ca wszystkie wartoœci koœci do tablicy
    arr[0]=d1.Getscore();                                                               //U¿ywana jest przy liczeniu 3x, 4x oraz fula
    arr[1]=d2.Getscore();
    arr[2]=d3.Getscore();
    arr[3]=d4.Getscore();
    arr[4]=d5.Getscore();
}

int smallStraight(vector<int> v,Dice d1,Dice d2,Dice d3,Dice d4,Dice d5){              //Funckja wpisuj¹ca wszystkie wartoœci koœci do wektora i sortuj¹ca je
    int score1 = 0;
    v.push_back(d1.Getscore());                                                         //Usuwa równie¿ powtarzaj¹ce siê wartoœci koœci, ¿eby by³y unikatowe
    v.push_back(d2.Getscore());                                                         //U¿ywana jest ta funckaj do liczenia stritów, du¿ego i ma³ego
    v.push_back(d3.Getscore());
    v.push_back(d4.Getscore());
    v.push_back(d5.Getscore());
    //cout<<"wtv";
    sort(v.begin(),v.end());
    vector<int>::iterator ip;
    ip = unique(v.begin(), v.begin() + 5);
    v.resize(std::distance(v.begin(), ip));
    if(v.size()==4){
    cout<<"size4";
    if(v[0]==1 && v[1]==2 && v[2]==3 && v[3]==4){
        score1 = 30;
    }
    if(v[0]==2 && v[1]==3 && v[2]==4 && v[3]==5){
        score1 = 30;
    }
    if(v[0]==3 && v[1]==4 && v[2]==5 && v[3]==6){
        score1 = 30;
    }
    }
    if(v.size()==5){
    cout<<"size5";
    if(v[0]==1 && v[1]==2 && v[2]==3 && v[3]==4 && v[4]==5){
        score1 = 30;
    }
    if(v[0]==2 && v[1]==3 && v[2]==4 && v[3]==5 && v[4]==6){
        score1 = 30;
    }
    if(v[0]==1 && v[1]==3 && v[2]==4 && v[3]==5 && v[4]==6){
        score1 = 30;
    }
    if(v[0]==1 && v[1]==2 && v[2]==3 && v[3]==4 && v[4]==6){
        score1 = 30;
    }
    }
    return score1;
}

bool cmp(pair<string, int>& a, pair<string, int>& b){                                   //Funkcja pomocnicza do wypisywania tablicy wyników po zakoñczonej rozgrywce
    return a.second < b.second;
}

int bigStraight(vector<int> v,Dice d1,Dice d2,Dice d3,Dice d4,Dice d5){                 //Algorytm do liczenia dużego strita
    int score1 = 0;
    v.push_back(d1.Getscore());                                                         //Usuwa równie¿ powtarzaj¹ce siê wartoœci koœci, ¿eby by³y unikatowe
    v.push_back(d2.Getscore());                                                         //U¿ywana jest ta funckaj do liczenia stritów, du¿ego i ma³ego
    v.push_back(d3.Getscore());
    v.push_back(d4.Getscore());
    v.push_back(d5.Getscore());
    sort(v.begin(),v.end());
    vector<int>::iterator ip;
    ip = unique(v.begin(), v.begin() + 5);
    v.resize(std::distance(v.begin(), ip));
    if(v.size()==5){
        int diff = 0;
            for(unsigned int i=0;i<v.size()-1;i++){
                if (v[i]+1==v[i+1])
                    diff += 1;
                if (v[i]+1!=v[i+1])
                    diff = diff - 1;
            }
            if(diff==4)
            score1 = 40;
    }
    return score1;
}

