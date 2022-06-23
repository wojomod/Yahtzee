#include "Dice.h"
#include "Scoreboard.h"
#include "functions.h"
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



int main()
{
    srand(time(NULL));
    const int TURN = 3, ROUNDS = 13;
	int round = 0;
	char numPlayer = ' ';
	string playerName;
	vector<Scoreboard> players;
	Dice d1(1),d2(2),d3(3),d4(4),d5(5);

	// Ustawianie iloœci graczy oraz ich nazw

	cout << "\t Witaj w grze w kosci!";
	cout << "\n\n Ilu bedzie graczy? ";
	cin >> numPlayer;
	while(numPlayer != '4' && numPlayer != '3' && numPlayer != '2'){
        cout<<"Bledna ilosc graczy! Prosze wpisz ponownie ilosc graczy od 2 do 4: ";    //wybor ilosci graczy
		cin >> numPlayer;
		}
    int inumPlayer = numPlayer - '0';
    cin.ignore();
	for (int i = 0; i < inumPlayer; i++) {
		cout << "\nWpisz nazwe gracza " << i + 1 << ": ";                               //pêtla do wpisywania nazw graczy
        getline(cin, playerName);
		Scoreboard player(playerName);
		players.push_back(player);
	}
	while(round<ROUNDS){                //g³ówna pêtla programu licz¹ca rundy do 13
        round++;
        srand (time(NULL));
        cout<<"\n ******************** Runda numer "<<round<<" ***********************\n\n";

        for(int j =0;j<inumPlayer;j++){
            cout<<"\n\n ******************** "<<players[j].name<<",czy jestes gotowy/a? ***********************\n"<<endl;
            cout<<"\t Wybierz: \n 1) Zagraj \n 2) Wyjdz z gry \n 3) Wypisz tablice wynikow i zagraj\n";                     //Menu wyborów dla gracza na pocz¹tku kolejki
            char a = ' ';
            cin>>a;
            while(a!='1' && a!='2' && a!='3'){                              //Wybór opcji
                wrongOption();
                cin>>a;
            }
            if(a=='2'){
                cout<<"\tDziekujemy za gre!";
                Sleep(2000);
                return 0;
            }
            if(a=='3'){
               players[j].printScoreboard();
            }

            //TURY

            for(int k=0;k<TURN;k++){                        //pêtla obs³uguj¹ca ruch w jednej rundzie dla gracza, który sk³ada siê z 3 tur/rzutów kostk¹
            cout<<"\n\tTwoj "<<k+1<<" rzut\n";
            d1.rollOne();
            d2.rollOne();
            d3.rollOne();
            d4.rollOne();
            d5.rollOne();
            showHand(d1,d2,d3,d4,d5);
            char g = ' ';
            if(k==2){                                       //Warunek, ktory przenosi nas automatycznie do wpisywania wyników w momencie gdy rzuciliœmy ju¿ 3 raz koœci¹
                g ='1';
                d1.SetChange(false);
                d2.SetChange(false);
                d3.SetChange(false);
                d4.SetChange(false);
                d5.SetChange(false);
            }

            char s = rollOption(g);
            while(s!='1' && s!='2'){                        //Menu wyborów dla gracza po pierwszym i drugim rzucie w turze od linijki 93 do 266
                wrongOption();
                s=rollOption(g);
            }

            if(s=='1'){                                     //opcja
                players[j].printScoreboard();
                cout<<"\n Gdzie chcesz zapisac swoj wynik?\n";
                string sel = " ";
                label5:
                cin>>sel;
                for(unsigned int i=0;i<sel.size();i++){
                    while(isdigit(sel[i])==false){
                    wrongOption();
                    cin>>sel;
                    }
                }

                int diceToScore = stoi(sel);
                int score1 = 0;
                while(diceToScore>13||diceToScore<1){
                    wrongOption();
                    cin>>sel;
                    for(unsigned int i=0;i<sel.size();i++){
                        while(isdigit(sel[i])==false){
                        wrongOption();
                        cin>>sel;
                        }
                    }
                    diceToScore = stoi(sel);
                }
                if(diceToScore<7){                                        //Algorytm do liczenia jedynek, dwójek, trójek, czwórek, pi¹tek i szóstek
                    score1 = calcUpperScore(diceToScore,d1,d2,d3,d4,d5);
                }
                else if(diceToScore == 7){                                //Alorytm do liczenia 3 takich samych koœci
                    int arr[5];
                    writeToArray(arr,d1,d2,d3,d4,d5);
                    map<int, int>m;
                    map<int, int>::iterator itr;
                    for(int i=0;i<5;i++){
                        m[arr[i]]++;
                    }
                    for(itr=m.begin();itr!=m.end();itr++){
                        if(itr->second==3)
                            score1 = calcSumDices(d1,d2,d3,d4,d5);
                    }
                }
                else if(diceToScore == 8){                                //Algorytm do liczenia 4 takich samych koœci
                    int arr[5];
                    writeToArray(arr,d1,d2,d3,d4,d5);
                    map<int, int>m;
                    map<int, int>::iterator itr;
                    for(int i=0;i<5;i++){
                        m[arr[i]]++;
                    }
                    for(itr=m.begin();itr!=m.end();itr++){
                        if(itr->second==4)
                            score1 = calcSumDices(d1,d2,d3,d4,d5);
                    }
                }
                else if(diceToScore == 13){                                //Algorytm do liczenia szansy
                    score1 = calcSumDices(d1,d2,d3,d4,d5);
                }
                else if(diceToScore == 9){                                 //Algorytm do liczenia fula
                    int arr[5];
                    writeToArray(arr,d1,d2,d3,d4,d5);
                    map<int, int>m;
                    map<int, int>::iterator itr=m.begin();
                    map<int, int>::iterator itr2=m.end();
                    for(int i=0;i<5;i++){
                        m[arr[i]]++;
                    }
                    if(m.size()==2){
                        for(itr=m.begin();itr!=m.end();itr++){
                                for(itr2=m.end();itr2!=m.begin();itr2--){
                                    if(itr->second==3 && itr2->second==2)
                                        score1 = 25;
                                    if(itr->second==2 && itr2->second==3)
                                        score1 = 25;
                                }
                        }
                    }
                }
                else if(diceToScore == 10){                                 //Algorytm do liczenia ma³ego strita
                    vector<int> v;
                    score1=smallStraight(v,d1,d2,d3,d4,d5);
                }
                else if(diceToScore == 11){                                 //Algorytm do liczenia du¿ego strita
                    vector<int> v;
                    score1=bigStraight(v,d1,d2,d3,d4,d5);
                }
                else if(diceToScore == 12){                                 //Algorytm do liczenia genera³a
                    vector<int> v;
                    v.push_back(d1.Getscore());
                    v.push_back(d2.Getscore());
                    v.push_back(d3.Getscore());
                    v.push_back(d4.Getscore());
                    v.push_back(d5.Getscore());
                    if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3] && v[3]==v[4]){
                        score1 = 50;
                    }

                }
                if(players[j].setScore(diceToScore,score1)==-1){            //Funkcja do wpisywania wyniku, czyli zmiennej score1 do konkretnego pola
                        goto label5;                                        //Oraz sprawdzaj¹ca czy mo¿na wpisaæ w to pole jak¹œ wartoœæ
                }                                                           //Gdy nie mo¿na, funkcja odsy³a nas do ponownego wyboru
                break;

            }
            if(s=='2'){
                string opt;
                cout<<"\tWybierz kosci ktore chcesz zostawic, jesli chcesz zamienic wszystkie kosci wpisz: 6 \n Nie uzywaj spacji:  ";
                cin>> opt;

            for(unsigned int i=0;i<opt.size();i++){                         //Funkcja do wyboru koœci, które chcemy zostawiæ
                while(isdigit(opt[i])==false){                              //Oraz sprawdzaj¹ca czy wpisane przez nas wartoœci s¹ prawid³owe
                    wrongOption();
                    d1.SetChange(false);
                    d2.SetChange(false);
                    d3.SetChange(false);
                    d4.SetChange(false);
                    d5.SetChange(false);
                    cin>>opt;
                }
                int opt2[opt.length()];
                opt2[i] = opt[i] - '0';
                switch(opt2[i]){
                case 1:
                    d1.SetChange(true);
                    break;
                case 2:
                    d2.SetChange(true);
                    break;
                case 3:
                    d3.SetChange(true);
                    break;
                case 4:
                    d4.SetChange(true);
                    break;
                case 5:
                    d5.SetChange(true);
                    break;
                case 6:
                    d1.SetChange(false);
                    d2.SetChange(false);
                    d3.SetChange(false);
                    d4.SetChange(false);
                    d5.SetChange(false);
                    break;
                }
            }
            }
            }
            players[j].printScoreboard();                   //Wypisanie tablicy wyników dla konretnego gracza
            }

        }
        for(int j = 0;j<inumPlayer;j++){                    //Funkcja do wypisania sumarycznego wyniku gracza oo zakoñczeniu rozgrywki
            players[j].printScoreboard();
            cout<<"\n\n"<<players[j].name<<", twoj wynik to: "<<players[j].getTotalScore()<<endl;
        }
        vector<pair<string, int> > A;                       //Algorytm do utworzenia tablicy wyników wszystkich graczy, którzy brali udzia³ w rozgrywce
        map<string, int>w;
        for(int j = 0;j<inumPlayer;j++){
            w[players[j].name]=players[j].getTotalScore();
        }
        for (auto& it : w) {
            A.push_back(it);
        }
        sort(A.begin(), A.end(), cmp);
        for (auto& it : A) {
            cout <<"\n"<< it.first << ' '<< it.second;
        }
        cout<<" - wygrales";
        Sleep(10000);

return 0;
}
