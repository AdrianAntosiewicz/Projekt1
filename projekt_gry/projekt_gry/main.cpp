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
#include "cPocisk.h"
using namespace sf;
using namespace std;


int main() {
	cBohater Bohater(300, 300, 100, 100);
	vector<cPrzeciwnik*> przeciwnicy;
	vector<cPrzeszkoda*> pszeszkody;
	vector<cPocisk> pociski;
	//Przeciwnicy
	przeciwnicy.push_back(new cMinion(1000, 400, 50, 50, 2, 1));
	przeciwnicy.push_back(new cMinion(1000, 700, 50, 50, 2, 1));
	//Pszeszkody
	pszeszkody.push_back(new cPrzeszkoda(800,400,300,100));
	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	window.setFramerateLimit(60);
	Event event;
	srand(time(0));
	int frame = 0, kol=0,kol_pocisk=0, strzal=0;
	while (true) {
		frame++;
		kol++;
		kol_pocisk++;
		strzal++;
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
		//Dodawanie pocisku
		if (Keyboard::isKeyPressed(Keyboard::Key::Up) && strzal>10) {
			pociski.push_back(cPocisk(Bohater.getPosition().x, Bohater.top(), 10, 10, 0, -12));
			strzal = 0;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && strzal > 10) {
			pociski.push_back(cPocisk(Bohater.getPosition().x, Bohater.bottom(), 10, 10, 0, 12));
			strzal = 0;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && strzal > 10) {
			pociski.push_back(cPocisk(Bohater.left(), Bohater.getPosition().y, 10, 10, -12, 0));
			strzal = 0;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Key::Right) && strzal > 10) {
			pociski.push_back(cPocisk(Bohater.right(), Bohater.getPosition().y, 10, 10, 12, 0));
			strzal = 0;
		}
		//Ruch pociskow
		for (auto i = pociski.begin(); i < pociski.end(); i++) {
			i->ruch();
		}
		//Sprawdzanie kolizji pociskow z obiektami
		for (auto itr = pociski.begin(); itr != pociski.end(); itr++) {
			for (int j = 0; j < pszeszkody.size(); j++) {
				if (itr->kolizja_przeszkoda(*pszeszkody[j])) {
					kol_pocisk = 1;
					break;
				}
			}
			for (int j = 0; j < przeciwnicy.size(); j++) {
				if (itr->kolizja_przeciwnik(*przeciwnicy[j])) {
					kol_pocisk = 1;
					break;
				}
			}
			if (itr->kolizja_bohater(Bohater)) {
				kol_pocisk = 1;
			}
			if (kol_pocisk == 1) {
				kol_pocisk = 0;
				pociski.erase(itr);
				break;
			}
		}
		//Sprawdzanie kolizji Bohatera z przeciwnikami 
		for (int i = 0; i < przeciwnicy.size(); i++) {
			przeciwnicy[i]->ruch();
			if (Bohater.kolizja_przeciwnik(*przeciwnicy[i])) {
				if (kol > 10) {
					kol = 0;
					//--->Cos jeszcze mozna zrobic w kolizji, bo typ 
				}
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
		for (auto el : pociski) {
			window.draw(el);
		}
		window.draw(Bohater);
		for (auto el : przeciwnicy) {
			window.draw(*el);
		}
		window.display();
	}


	return 0;
}