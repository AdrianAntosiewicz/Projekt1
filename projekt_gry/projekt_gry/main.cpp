#include<iostream>
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <vector>
#include <time.h>
#include"cBohater.h"
#include "cMinion.h"
using namespace sf;
using namespace std;


int main() {
	cBohater Bohater(400, 300, 100, 100);
	vector<cMinion> miniony;
	miniony.push_back(cMinion(1000, 400, 50, 50, 2, 1));
	miniony.push_back(cMinion(1000, 700, 50, 50, 2, 1));
	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	window.setFramerateLimit(50);
	Event event;
	srand(time(0));
	clock_t start, koniec;
	int ok = 1;
	while (true) {
		if (ok == 1) {
			start = clock();
			ok = 0;
		}		
		if (clock()-start > 1000) {
			ok = 1;
			for (int i = 0; i < miniony.size(); i++) {
				int los = rand() % 4;
				miniony[i].uptade(los);
			}
		}
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}
		Bohater.uptade();
		for (int i = 0; i < miniony.size(); i++) {
			miniony[i].ruch();
			if (Bohater.kolizja(miniony[i].get_shape())) {
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
		window.draw(Bohater);
		for (auto el : miniony) {
			window.draw(el);
		}
		window.display();
	}


	return 0;
}