#include<iostream>
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <vector>
#include <time.h>

#include"cBohater.h"
#include "cMinion.h"
#include"cPrzeciwnik.h"
#include "cPrzeszkoda.h"
using namespace sf;
using namespace std;


int main() {
	cBohater Bohater(300, 300, 100, 100);
	vector<cPrzeciwnik*> przeciwnicy;
	vector<cPrzeszkoda*> pszeszkody;
	//Przeciwnicy
	przeciwnicy.push_back(new cMinion(1000, 400, 50, 50, 2, 1));
	przeciwnicy.push_back(new cMinion(1000, 700, 50, 50, 2, 1));
	//Pszeszkody
	pszeszkody.push_back(new cPrzeszkoda(800,400,300,100));
	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	window.setFramerateLimit(60);
	Event event;
	srand(time(0));
	int frame = 0;
	while (true) {
		frame++;
		//--Nadawanie losowej prêdkoœci przeciwnikom
		if (frame > 59) {
			for (int i = 0; i < przeciwnicy.size(); i++) {
				int los = rand() % 4;
				przeciwnicy[i]->uptade(los);
			}
			frame = 0;
		}

		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}

		Bohater.uptade();
		//Sprawdzanie kolizji Bohatera z przeciwnikami 
		for (int i = 0; i < przeciwnicy.size(); i++) {
			przeciwnicy[i]->ruch();
			if (Bohater.kolizja_przeciwnik(*przeciwnicy[i])) {
				//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
			}
		}
		//Sprawdzanie kolizji Bohatera z Przeszkodami
		for (int i = 0; i < pszeszkody.size(); i++) {
			if (Bohater.kolizja_przeszkoda(*pszeszkody[i])) {
				//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
			}
		}
		//Rysowanie obiektów
		for (auto el : pszeszkody) {
			window.draw(*el);
		}
		window.draw(Bohater);
		for (auto el : przeciwnicy) {
			window.draw(*el);
		}
		window.display();
	}


	return 0;
}