#include<iostream>
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <vector>
#include <time.h>
#include"cBohater.h"
#include "cMinion.h"
#include"cPrzeciwnik.h"
using namespace sf;
using namespace std;


int main() {
	cBohater Bohater(400, 300, 100, 100);
	vector<cPrzeciwnik*> przeciwnicy;
	przeciwnicy.push_back(new cMinion(1000, 400, 50, 50, 2, 1));
	przeciwnicy.push_back(new cMinion(1000, 700, 50, 50, 2, 1));
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
		//Sprawdzanie kolizji Bohatera z przeciwnikami i wywo³ywanie metody shape.move u przeciwikow
		for (int i = 0; i < przeciwnicy.size(); i++) {
			przeciwnicy[i]->ruch();
			if (Bohater.kolizja(przeciwnicy[i]->get_shape())) {
				if(Bohater.get_last_click()=='d')
					Bohater.set_vx(-30);
				if (Bohater.get_last_click() == 'a')
					Bohater.set_vx(30);
				if (Bohater.get_last_click() == 'w')
					Bohater.set_vy(30);
				if (Bohater.get_last_click() == 's')
					Bohater.set_vy(-30);
			}
		}
		//Rysowanie obiektów
		window.draw(Bohater.get_shape());
		for (auto el : przeciwnicy) {
			window.draw(el->get_shape());
		}
		window.display();
	}


	return 0;
}