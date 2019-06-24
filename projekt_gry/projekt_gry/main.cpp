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
#include "cStrzelec.h"
#include "cMur.h"
using namespace sf;
using namespace std;


int main() {
	cBohater Bohater(300, 300, 140, 140);
	vector<cPrzeciwnik*> przeciwnicy;
	vector<cPrzeszkoda*> pszeszkody;
	vector<cPocisk> pociski;
	//Przeciwnicy
	przeciwnicy.push_back(new cMinion(1000, 400, 96, 96, 2, 1));
	przeciwnicy.push_back(new cMinion(1000, 700, 96, 96, 2, 1));
	przeciwnicy.push_back(new cStrzelec(900, 700, 96, 96, 2, 1));
	//Pszeszkody
	pszeszkody.push_back(new cMur(960,32,1920,64));
	pszeszkody.push_back(new cMur(960, 1048, 1920, 64));
	pszeszkody.push_back(new cMur(32, 540, 64, 1080));
	pszeszkody.push_back(new cMur(1888, 540, 64, 1080));
	pszeszkody.push_back(new cMur(1000, 500, 256, 64));
	pszeszkody.push_back(new cMur(1000, 800, 256, 64));
	pszeszkody.push_back(new cMur(1300, 192, 64, 256));

	//Tekstury
	Texture tekstura_podloga;
	tekstura_podloga.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\podloga.png");
	Sprite sprajt_podloga;
	sprajt_podloga.setTexture(tekstura_podloga);

	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	window.setFramerateLimit(60);
	Event event;
	srand(time(0));
	int frame = 0, kol=0,kol_pocisk=0, strzal=0;
	vector<cPocisk>::iterator itr_kol;
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
				if (cStrzelec *s = dynamic_cast<cStrzelec*>(przeciwnicy[i])) {
					int rad = rand() % 4;
					if (rad == 0) {
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->top()-3, 10, 0, -12,2));
					}
					if (rad == 1) {
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->bottom()+3, 10, 0, 12,2));
					}
					if (rad == 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->left()-2, przeciwnicy[i]->getPosition().y, 10,-12, 0,2));
					}
					if (rad == 3) {
						pociski.push_back(cPocisk(przeciwnicy[i]->right()+2, przeciwnicy[i]->getPosition().y, 10,12, 0,2));
					}
				}
			}
			frame = 0;
		}

		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}

		//Dodawanie pocisku
		if (Keyboard::isKeyPressed(Keyboard::Key::Up) && strzal>10) {
			cout << pociski.size() << endl;
			pociski.push_back(cPocisk(Bohater.getPosition().x+43, Bohater.top()-3, 10, 0, -12,1));
			cout << pociski.size() << endl;
			strzal = 0;
			Bohater.sprajt_rotate(0);
			//Bohater.setRotation(0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down) && strzal > 10) {
			pociski.push_back(cPocisk(Bohater.getPosition().x-43, Bohater.bottom()+3, 10, 0, 12,1));
			strzal = 0;
			Bohater.sprajt_rotate(180);
			//Bohater.setRotation(180);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && strzal > 10) {
			pociski.push_back(cPocisk(Bohater.left()-2, Bohater.getPosition().y-43, 10, -12, 0,1));
			strzal = 0;
			Bohater.sprajt_rotate(270);
			//Bohater.setRotation(270);
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Right) && strzal > 10) {
			pociski.push_back(cPocisk(Bohater.right()+2, Bohater.getPosition().y+43, 10, 12, 0,1));
			strzal = 0;
			Bohater.sprajt_rotate(90);
			//Bohater.setRotation(90);
		}
		//Ruch pociskow
		for (auto i = pociski.begin(); i < pociski.end(); i++) {
			i->ruch();
		}
		//Sprawdzanie kolizji pociskow z obiektami
		vector<cPocisk>::iterator itr;
		for (itr = pociski.begin(); itr != pociski.end(); itr++) {
			for (int j = 0; j < pszeszkody.size(); j++) {
					if (itr->kolizja_przeszkoda(*pszeszkody[j])) {
						kol_pocisk = 1;
						break;
					}
			}
			for (int j = 0; j < przeciwnicy.size(); j++) {
					if (itr->kolizja_przeciwnik(*przeciwnicy[j])) {
						kol_pocisk = 1;
						if(itr->get_id()==1)
							przeciwnicy[j]->zranienie();
						if (przeciwnicy[j]->get_life() == 0)
						{
							auto itr = przeciwnicy.begin();
							przeciwnicy.erase(itr+j);
						}
						break;
					}
			}
			if (itr->kolizja_bohater(Bohater)) {
				kol_pocisk = 1;
			}
			if (kol_pocisk == 1) {
				pociski.erase(itr);
				kol_pocisk = 2;
				break;
			}
		}
		//Sprawdzanie kolizji Bohatera z przeciwnikami 
		for (int i = 0; i < przeciwnicy.size(); i++) {
			przeciwnicy[i]->ruch();
			if (Bohater.kolizja_przeciwnik(*przeciwnicy[i])) {
				if (kol > 10) {
					kol = 0;
					//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
				}
			}
		}
		//Sprawdzanie kolizji Bohatera z Przeszkodami
		Bohater.uptade();
		for (int i = 0; i < pszeszkody.size(); i++) {
			if (Bohater.kolizja_przeszkoda(*pszeszkody[i])) {
				//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
				if(Bohater.get_last_click()=='d')
					Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
				if(Bohater.get_last_click() == 'a')
					Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
				if(Bohater.get_last_click() == 's')
					Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y-6);
				if (Bohater.get_last_click() == 'w')
					Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
			}
		}
		//Sprawdzanie kolizji przeciwnikow z przeszkodami
		for (int i = 0; i < przeciwnicy.size();i++) {
			for (int j = 0; j < pszeszkody.size(); j++) {
				if (przeciwnicy[i]->kolizja_przeszkoda(*pszeszkody[j])) {
					if (przeciwnicy[i]->get_vx() > 0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x-1, przeciwnicy[i]->getPosition().y);
					if (przeciwnicy[i]->get_vx() < -0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x +1, przeciwnicy[i]->getPosition().y);
					if (przeciwnicy[i]->get_vy() > 0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->getPosition().y-1);
					if (przeciwnicy[i]->get_vy() < -0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->getPosition().y + 1);
				}
			}
		}
		//Rysowanie obiektów
		window.draw(sprajt_podloga);

		for (auto el : pszeszkody) {
			window.draw(el->get_sprajt());
		}
		for (auto el : pociski) {
			window.draw(el);
		}
		window.draw(Bohater.get_sprajt());
		for (auto el : przeciwnicy) {
			window.draw(el->get_sprajt());
		}
		window.display();
	}


	return 0;
}