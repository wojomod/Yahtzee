#include "Scoreboard.h"
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

//Klasa Scoreboard opisuj�ca nasz� tablice wynik�w i funkcje pomocnicze do niej

Scoreboard::Scoreboard(string playerName)
{
    name = playerName;                      //Zmienne opisuj�ce dane wyniki dla r�nych kombinacji ko�ci
	aces = -1;                              //Domy�lnie ustawione s� na -1, �eby unikn�� wpisywania ponownego gdy ju� raz wybierzemy dan� opcje
	twos = -1;
	threes = -1;
	fours = -1;
	fives = -1;
	sixes = -1;
	threeKind = -1;
	fourKind = -1;
	fullHouse = -1;
	smallStrt = -1;
	largeStrt = -1;
	yahtzee = -1;
	chance = -1;
}
int Scoreboard::getTotalScore() {           //Funkcja do sumowania ca�ego wyniku dla konkretnego gracza na koniec rozgrywki
	int total = 0;
	total = aces + twos + threes + fours + fives + sixes + threeKind + fourKind + fullHouse + smallStrt + largeStrt + yahtzee + chance;
	return total;
}
int Scoreboard::setScore(int selection, int score) {        //G��wna funkcja, dzi�ki kt�rej jeste�my w stanie przypisywa� dane wyniki do konkretnych u�o�e� na tablicy
	switch (selection) {                                    //Posiada ona r�wnie� zabezpieczenie przed ponownym wpisaniem warto�ci w nasze pole
	case 1:                                                 //Gdy kto� spr�buje wpisa� co� w zaj�te pole, funkcja zwraca -1
	    if(aces == -1){
            aces = score;
            return 0;
	    }
        else if (aces != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 2:
	    if(twos == -1){
	        twos = score;
            return 0;
	    }
        else if (twos != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 3:
		if(threes == -1){
            threes = score;
            return 0;
	    }
        else if (threes != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 4:
		if(fours == -1){
            fours = score;
            return 0;
	    }
        else if (fours != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 5:
		if(fives == -1){
            fives = score;
            return 0;
	    }
        else if (fives != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 6:
		if(sixes == -1){
            sixes = score;
            return 0;
	    }
        else if (sixes != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 7:
		if(threeKind == -1){
            threeKind = score;
            return 0;
	    }
        else if (threeKind != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 8:
		if(fourKind == -1){
            fourKind = score;
            return 0;
	    }
        else if (fourKind != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 9:
		if(fullHouse == -1){
            fullHouse = score;
            return 0;
	    }
        else if (fullHouse != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 10:
		if(smallStrt == -1){
            smallStrt = score;
            return 0;
	    }
        else if (smallStrt != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 11:
		if(largeStrt == -1){
            largeStrt = score;
            return 0;
	    }
        else if (largeStrt != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 12:
		if(yahtzee == -1){
            yahtzee = score;
            return 0;
	    }
        else if (yahtzee != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;
	case 13:
		if(chance == -1){
            chance = score;
            return 0;
	    }
        else if (chance != -1){
            cout<<"Nie mozna wpisac tu wartosci! Wybierz ponownie kategorie"<<endl;
            return -1;
        }
		break;;
	default: cout << "/nTwoj wynik nie zostal poprawnie zapisany";
	}
}

void Scoreboard::printScoreboard() {                                        //Funkcja do wypisywania tablicy wynik�w po rzucie oraz po wpisaniu do niej warto�ci
	cout << "\n\n\t\tGracz " << name << " Tablica wynikow\n";
	cout << "\n 1) Jedynki: "<< check(aces) <<"\n 2) Dwojki: "<< check(twos) <<"\n 3) Trojki: "<<check(threes);
	cout << "\n 4) Czworki: "<<check(fours) <<"\n 5) Piatki: "<<check(fives) <<"\n 6) Szostki: "<<check(sixes);
	cout << "\n\n 7) 3x: " << check(threeKind)<<"\n 8) 4x: " << check(fourKind)<<"\n 9) 3x+2x: "<<check(fullHouse);
    cout << "\n 10) Maly strit: "<<check(smallStrt)<<"\n 11) Duzy strit: "<<check(largeStrt)<<"\n 12) General: "<<check(yahtzee);
	cout << "\n 13) Szansa: "<<check(chance);
}
string Scoreboard::check(int inty) {            //Funkcja, kt�ra sprawdza stan naszych p�l przy wypisywaniu funkcji printScoreboard
	if (inty == -1) {                           //Gdy gracz nic nie wpisa� do danego pola wypisywane jest puste pole, w przeciwnym wypadku wynik
		return " ";
	}
	else {
		return to_string(inty);
	}
}
Scoreboard::~Scoreboard()
{
    //dtor
}
