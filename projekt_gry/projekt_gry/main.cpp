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
#include "cMenu.h"
using namespace sf;
using namespace std;


int main() {
	cBohater Bohater(300, 300, 140, 140);
	vector<cPrzeciwnik*> przeciwnicy1,przeciwnicy2,przeciwnicy3;
	vector<cPrzeszkoda*> pszeszkody1,pszeszkody2,pszeszkody3;
	vector<cPocisk> pociski;
	//Przeciwnicy
	przeciwnicy1.push_back(new cMinion(1000, 400, 96, 96, 2, 6));
	przeciwnicy1.push_back(new cMinion(1000, 700, 96, 96, 2, 1));
	przeciwnicy1.push_back(new cStrzelec(900, 700, 96, 96, 2, 1));
	przeciwnicy1.push_back(new cStrzelec(900, 900, 96, 96, 2, 3));
	przeciwnicy1.push_back(new cMinion(1000, 400, 96, 96, 2, 6));
	przeciwnicy1.push_back(new cMinion(1000, 700, 96, 96, 2, 1));
	przeciwnicy1.push_back(new cStrzelec(900, 700, 96, 96, 2, 1));
	przeciwnicy1.push_back(new cStrzelec(900, 900, 96, 96, 2, 3));
	przeciwnicy1.push_back(new cMinion(1000, 400, 96, 96, 2, 6));

	przeciwnicy2.push_back(new cMinion(1000, 700, 96, 96, 2, 1));
	przeciwnicy2.push_back(new cStrzelec(900, 700, 96, 96, 2, 1));
	przeciwnicy2.push_back(new cStrzelec(900, 900, 96, 96, 2, 3));

	przeciwnicy3.push_back(new cStrzelec(900, 900, 96, 96, 2, 3));
	//Pszeszkody
	pszeszkody1.push_back(new cPrzeszkoda(960,32,1920,64,1));
	pszeszkody1.push_back(new cPrzeszkoda(960, 1048, 1920, 64,1));
	pszeszkody1.push_back(new cPrzeszkoda(32, 540, 64, 1080,1));
	pszeszkody1.push_back(new cPrzeszkoda(1888, 540, 64, 1080,1));
	pszeszkody1.push_back(new cPrzeszkoda(1000, 500, 256, 64,1));
	pszeszkody1.push_back(new cPrzeszkoda(1000, 800, 256, 64,1));
	pszeszkody1.push_back(new cPrzeszkoda(1300, 192, 64, 256,1));
	pszeszkody1.push_back(new cPrzeszkoda(1200, 500, 64, 64, 2));

	pszeszkody2.push_back(new cPrzeszkoda(960, 32, 1920, 64, 1));
	pszeszkody2.push_back(new cPrzeszkoda(960, 1048, 1920, 64, 1));
	pszeszkody2.push_back(new cPrzeszkoda(32, 540, 64, 1080, 1));
	pszeszkody2.push_back(new cPrzeszkoda(1888, 540, 64, 1080, 1));

	pszeszkody3.push_back(new cPrzeszkoda(960, 32, 1920, 64, 1));
	pszeszkody3.push_back(new cPrzeszkoda(960, 1048, 1920, 64, 1));
	pszeszkody3.push_back(new cPrzeszkoda(32, 540, 64, 1080, 1));
	pszeszkody3.push_back(new cPrzeszkoda(1888, 540, 64, 1080, 1));
	pszeszkody3.push_back(new cPrzeszkoda(1300, 192, 64, 256, 1));

	//Tekstury
	Texture tekstura_podloga, t_wyb1, t_wyb2, t_wyb3, t_wyb4, t_wyb5, t_wyb6, t_splasz,t_menu;
		tekstura_podloga.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\podloga.png");
		t_wyb1.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch1.png");
		t_wyb2.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch2.png");
		t_wyb3.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch3.png");
		t_wyb4.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch4.png");
		t_wyb5.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch5.png");
		t_wyb6.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch6.png");
		t_splasz.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\splasz.png");
		Sprite sprajt_podloga, s_wyb1, s_wyb2, s_wyb3, s_wyb4, s_wyb5, s_wyb6,s_menu;
		sprajt_podloga.setTexture(tekstura_podloga);
		s_wyb1.setTexture(t_wyb1);
		s_wyb2.setTexture(t_wyb2);
		s_wyb3.setTexture(t_wyb3);
		s_wyb4.setTexture(t_wyb4);
		s_wyb5.setTexture(t_wyb5);
		s_wyb6.setTexture(t_wyb6);

	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	window.setFramerateLimit(60);
	Event event;
	srand(time(0));
	int frame_normal = 0, kol = 0, kol_pocisk = 0, strzal = 0, frame_fast = 0, frame_wybuch = 0, klatki = 0;
	vector<cPocisk>::iterator itr_kol;
	vector<Sprite> splasze;
	int wybuch_x = -1, wybuch_y = -1;
	int   level=1,odliczanie=1,frame_level=0;
	string stan_gry = "1_";
	string stan_opcji = "0";
	while (true) {
		if (stan_gry == "1_") {
			stan_gry = funkcja_menu(window);
			if (stan_gry == "2_")
				odliczanie = 2;
		}
		if (stan_gry == "opcje") {
			stan_opcji = funkcja_opcje(window);
		}
		if (stan_opcji == "latwy") {
			stan_opcji = "0";
			stan_gry = "1_";
		}
		if (stan_opcji == "sredni") {
			for (int i = 0; i < przeciwnicy1.size(); i++) {
				przeciwnicy1[i]->set_life(przeciwnicy1[i]->get_life()*0.5);
				przeciwnicy1[i]->set_basic_v(przeciwnicy1[i]->get_basic_v()*0.5);
			}
			stan_opcji = "0";
			stan_gry = "1_";
		}
		if (stan_opcji == "trudny") {
			for (int i = 0; i < przeciwnicy1.size(); i++) {
				przeciwnicy1[i]->set_life(przeciwnicy1[i]->get_life()*1.5);
				przeciwnicy1[i]->set_basic_v(przeciwnicy1[i]->get_basic_v()*0.5);
			}
			stan_opcji = "0";
			stan_gry = "1_";
		}

		else if (stan_gry == "2_") {
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				stan_gry = "1_";
			}
			if (odliczanie == 2 ) {
				for (int i = 0; i < 210; i++) {
					window.display();
					window.clear();
					if (level == 1) {
						window.draw(sprajt_podloga);
						for (auto el : pszeszkody1) {
							window.draw(el->get_sprajt());
						}
						for (auto el : pociski) {
							window.draw(el);
						}

						window.draw(Bohater.get_sprajt());

						for (auto el : przeciwnicy1) {
							window.draw(el->get_sprajt());
						}
					}

					if (level == 2) {
						window.draw(sprajt_podloga);
						for (auto el : pszeszkody2) {
							window.draw(el->get_sprajt());
						}
						for (auto el : pociski) {
							window.draw(el);
						}

						window.draw(Bohater.get_sprajt());

						for (auto el : przeciwnicy2) {
							window.draw(el->get_sprajt());
						}
					}

					if (level == 3) {
						window.draw(sprajt_podloga);
						for (auto el : pszeszkody3) {
							window.draw(el->get_sprajt());
						}
						for (auto el : pociski) {
							window.draw(el);
						}

						window.draw(Bohater.get_sprajt());

						for (auto el : przeciwnicy3) {
							window.draw(el->get_sprajt());
						}
					}

					if (i < 60) {
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("3", font, 100);
						tekst.setOutlineColor(Color::Black);
						tekst.setOutlineThickness(5);
						tekst.setPosition(940, 400);
						window.draw(tekst);
					}
					if (i < 120 && i>=60) {
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("2", font, 100);
						tekst.setOutlineColor(Color::Black);
						tekst.setOutlineThickness(5);
						tekst.setPosition(940, 400);
						window.draw(tekst);
					}
					if (i < 180 && i>=120) {
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("1", font, 100);
						tekst.setOutlineColor(Color::Black);
						tekst.setOutlineThickness(5);
						tekst.setPosition(940, 400);
						window.draw(tekst);
					}
					if (i < 210 && i >= 180) {
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("Start!", font, 100);
						tekst.setOutlineColor(Color::Black);
						tekst.setOutlineThickness(5);
						tekst.setPosition(850, 400);
						window.draw(tekst);
					}
				}
				odliczanie = 1;
			}

			if (frame_wybuch > 0)
				frame_wybuch++;
			if (frame_level > 0) {
				frame_level++;
			}
			frame_fast++;
			frame_normal++;
			kol++;
			kol_pocisk++;
			strzal++;
			//--Nadawanie losowej prêdkoœci przeciwnikom
			if (level == 1) {
				if (frame_fast > 29) {
					for (int i = 0; i < przeciwnicy1.size(); i++) {
						if (przeciwnicy1[i]->get_basic_v() > 2) {
							int los = rand() % 4;
							przeciwnicy1[i]->uptade(los);
						}
					}
					frame_fast = 0;
				}

				if (frame_normal > 59) {
					for (int i = 0; i < przeciwnicy1.size(); i++) {
						int los = rand() % 4;
						przeciwnicy1[i]->uptade(los);
						if (cStrzelec *s = dynamic_cast<cStrzelec*>(przeciwnicy1[i])) {
							if (los == 0 && przeciwnicy1[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x, przeciwnicy1[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy1[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x, przeciwnicy1[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy1[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->left() - 2, przeciwnicy1[i]->getPosition().y, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy1[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->right() + 2, przeciwnicy1[i]->getPosition().y, 10, 12, 0, 2));
							}
							if (los == 0 && przeciwnicy1[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x + 30, przeciwnicy1[i]->top() - 3, 10, 0, -12, 2));
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x - 30, przeciwnicy1[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy1[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x + 30, przeciwnicy1[i]->bottom() + 3, 10, 0, 12, 2));
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x - 30, przeciwnicy1[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy1[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->left() - 2, przeciwnicy1[i]->getPosition().y + 30, 10, -12, 0, 2));
								pociski.push_back(cPocisk(przeciwnicy1[i]->left() - 2, przeciwnicy1[i]->getPosition().y - 30, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy1[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->right() + 2, przeciwnicy1[i]->getPosition().y + 30, 10, 12, 0, 2));
								pociski.push_back(cPocisk(przeciwnicy1[i]->right() + 2, przeciwnicy1[i]->getPosition().y - 30, 10, 12, 0, 2));
							}
						}
					}
					frame_normal = 0;
				}
			}

			if (level == 2) {
				if (frame_fast > 29) {
					for (int i = 0; i < przeciwnicy2.size(); i++) {
						if (przeciwnicy2[i]->get_basic_v() > 2) {
							int los = rand() % 4;
							przeciwnicy2[i]->uptade(los);
						}
					}
					frame_fast = 0;
				}

				if (frame_normal > 59) {
					for (int i = 0; i < przeciwnicy2.size(); i++) {
						int los = rand() % 4;
						przeciwnicy2[i]->uptade(los);
						if (cStrzelec *s = dynamic_cast<cStrzelec*>(przeciwnicy2[i])) {
							if (los == 0 && przeciwnicy2[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x, przeciwnicy2[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy2[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x, przeciwnicy2[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy2[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->left() - 2, przeciwnicy2[i]->getPosition().y, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy2[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->right() + 2, przeciwnicy2[i]->getPosition().y, 10, 12, 0, 2));
							}
							if (los == 0 && przeciwnicy2[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x + 30, przeciwnicy2[i]->top() - 3, 10, 0, -12, 2));
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x - 30, przeciwnicy2[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy2[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x + 30, przeciwnicy2[i]->bottom() + 3, 10, 0, 12, 2));
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x - 30, przeciwnicy2[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy2[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->left() - 2, przeciwnicy2[i]->getPosition().y + 30, 10, -12, 0, 2));
								pociski.push_back(cPocisk(przeciwnicy2[i]->left() - 2, przeciwnicy2[i]->getPosition().y - 30, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy2[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->right() + 2, przeciwnicy2[i]->getPosition().y + 30, 10, 12, 0, 2));
								pociski.push_back(cPocisk(przeciwnicy2[i]->right() + 2, przeciwnicy2[i]->getPosition().y - 30, 10, 12, 0, 2));
							}
						}
					}
					frame_normal = 0;
				}
			}

			if (level == 3) {
				if (frame_fast > 29) {
					for (int i = 0; i < przeciwnicy3.size(); i++) {
						if (przeciwnicy3[i]->get_basic_v() > 2) {
							int los = rand() % 4;
							przeciwnicy3[i]->uptade(los);
						}
					}
					frame_fast = 0;
				}

				if (frame_normal > 59) {
					for (int i = 0; i < przeciwnicy3.size(); i++) {
						int los = rand() % 4;
						przeciwnicy3[i]->uptade(los);
						if (cStrzelec *s = dynamic_cast<cStrzelec*>(przeciwnicy3[i])) {
							if (los == 0 && przeciwnicy3[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x, przeciwnicy3[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy3[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x, przeciwnicy3[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy3[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->left() - 2, przeciwnicy3[i]->getPosition().y, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy3[i]->get_basic_v() < 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->right() + 2, przeciwnicy3[i]->getPosition().y, 10, 12, 0, 2));
							}
							if (los == 0 && przeciwnicy3[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x + 30, przeciwnicy3[i]->top() - 3, 10, 0, -12, 2));
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x - 30, przeciwnicy3[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy3[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x + 30, przeciwnicy3[i]->bottom() + 3, 10, 0, 12, 2));
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x - 30, przeciwnicy3[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy3[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->left() - 2, przeciwnicy3[i]->getPosition().y + 30, 10, -12, 0, 2));
								pociski.push_back(cPocisk(przeciwnicy3[i]->left() - 2, przeciwnicy3[i]->getPosition().y - 30, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy3[i]->get_basic_v() > 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->right() + 2, przeciwnicy3[i]->getPosition().y + 30, 10, 12, 0, 2));
								pociski.push_back(cPocisk(przeciwnicy3[i]->right() + 2, przeciwnicy3[i]->getPosition().y - 30, 10, 12, 0, 2));
							}
						}
					}
					frame_normal = 0;
				}
			}



			//obs³uga okna
			window.clear(Color::Black);
			window.pollEvent(event);
			if (event.type == Event::Closed) {
				window.close();
				break;
			}



			//Dodawanie pocisku
			if (Keyboard::isKeyPressed(Keyboard::Key::Up) && strzal > 10) {
				cout << pociski.size() << endl;
				pociski.push_back(cPocisk(Bohater.getPosition().x + 43, Bohater.top() - 3, 10, 0, -12, 1));
				cout << pociski.size() << endl;
				strzal = 0;
				Bohater.sprajt_rotate(0);
				//Bohater.setRotation(0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down) && strzal > 10) {
				pociski.push_back(cPocisk(Bohater.getPosition().x - 43, Bohater.bottom() + 3, 10, 0, 12, 1));
				strzal = 0;
				Bohater.sprajt_rotate(180);
				//Bohater.setRotation(180);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Left) && strzal > 10) {
				pociski.push_back(cPocisk(Bohater.left() - 2, Bohater.getPosition().y - 43, 10, -12, 0, 1));
				strzal = 0;
				Bohater.sprajt_rotate(270);
				//Bohater.setRotation(270);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right) && strzal > 10) {
				pociski.push_back(cPocisk(Bohater.right() + 2, Bohater.getPosition().y + 43, 10, 12, 0, 1));
				strzal = 0;
				Bohater.sprajt_rotate(90);
				//Bohater.setRotation(90);
			}
			//Ruch pociskow
			for (auto i = pociski.begin(); i < pociski.end(); i++) {
				i->ruch();
			}
			//Sprawdzanie kolizji pociskow z obiektami
			if (level == 1) {
				vector<cPocisk>::iterator itr;
				for (itr = pociski.begin(); itr != pociski.end(); itr++) {
					for (int j = 0; j < pszeszkody1.size(); j++) {
						if (itr->kolizja_przeszkoda(*pszeszkody1[j])) {
							kol_pocisk = 1;
							break;
						}
					}
					for (int j = 0; j < przeciwnicy1.size(); j++) {
						if (itr->kolizja_przeciwnik(*przeciwnicy1[j])) {
							kol_pocisk = 1;
							if (itr->get_id() == 1)
								przeciwnicy1[j]->zranienie();
							if (przeciwnicy1[j]->get_life() == 0)
							{
								auto itr = przeciwnicy1.begin();
								wybuch_x = przeciwnicy1[j]->getPosition().x;
								wybuch_y = przeciwnicy1[j]->getPosition().y;
								Sprite s1;
								s1.setTexture(t_splasz);
								s1.setPosition(wybuch_x, wybuch_y);
								s1.setOrigin(48, 48);
								splasze.push_back(s1);
								frame_wybuch = 1;
								przeciwnicy1.erase(itr + j);
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
			}

			if (level == 2) {
				vector<cPocisk>::iterator itr;
				for (itr = pociski.begin(); itr != pociski.end(); itr++) {
					for (int j = 0; j < pszeszkody2.size(); j++) {
						if (itr->kolizja_przeszkoda(*pszeszkody2[j])) {
							kol_pocisk = 1;
							break;
						}
					}
					for (int j = 0; j < przeciwnicy2.size(); j++) {
						if (itr->kolizja_przeciwnik(*przeciwnicy2[j])) {
							kol_pocisk = 1;
							if (itr->get_id() == 1)
								przeciwnicy2[j]->zranienie();
							if (przeciwnicy2[j]->get_life() == 0)
							{
								auto itr = przeciwnicy2.begin();
								wybuch_x = przeciwnicy2[j]->getPosition().x;
								wybuch_y = przeciwnicy2[j]->getPosition().y;
								Sprite s1;
								s1.setTexture(t_splasz);
								s1.setPosition(wybuch_x, wybuch_y);
								s1.setOrigin(48, 48);
								splasze.push_back(s1);
								frame_wybuch = 1;
								przeciwnicy2.erase(itr + j);
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
			}

			if (level == 3) {
				vector<cPocisk>::iterator itr;
				for (itr = pociski.begin(); itr != pociski.end(); itr++) {
					for (int j = 0; j < pszeszkody3.size(); j++) {
						if (itr->kolizja_przeszkoda(*pszeszkody3[j])) {
							kol_pocisk = 1;
							break;
						}
					}
					for (int j = 0; j < przeciwnicy3.size(); j++) {
						if (itr->kolizja_przeciwnik(*przeciwnicy3[j])) {
							kol_pocisk = 1;
							if (itr->get_id() == 1)
								przeciwnicy3[j]->zranienie();
							if (przeciwnicy3[j]->get_life() == 0)
							{
								auto itr = przeciwnicy3.begin();
								wybuch_x = przeciwnicy3[j]->getPosition().x;
								wybuch_y = przeciwnicy3[j]->getPosition().y;
								Sprite s1;
								s1.setTexture(t_splasz);
								s1.setPosition(wybuch_x, wybuch_y);
								s1.setOrigin(48, 48);
								splasze.push_back(s1);
								frame_wybuch = 1;
								przeciwnicy3.erase(itr + j);
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
			}

			//Sprawdzanie kolizji Bohatera z Przeszkodami
			if (level == 1) {
				for (int i = 0; i < pszeszkody1.size(); i++) {
					if (Bohater.kolizja_przeszkoda(*pszeszkody1[i]) && pszeszkody1[i]->get_id()==1) {
						//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						{
							//if (Bohater.get_strona_kolizji() == 'd')
							//	Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 'a')
							//	Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 's')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
							//if (Bohater.get_strona_kolizji() == 'w')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
						}
						if (Bohater.get_last_click() == 'd')
							Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 'a')
							Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 's')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
						if (Bohater.get_last_click() == 'w')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
					}
					if (Bohater.kolizja_przeszkoda(*pszeszkody1[i]) && pszeszkody1[i]->get_id() == 2) {
						//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						{
							//if (Bohater.get_strona_kolizji() == 'd')
							//	Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 'a')
							//	Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 's')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
							//if (Bohater.get_strona_kolizji() == 'w')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
						}
						if (Bohater.get_last_click() == 'd')
							Bohater.setPosition(Bohater.getPosition().x - 30, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 'a')
							Bohater.setPosition(Bohater.getPosition().x + 30, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 's')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 30);
						if (Bohater.get_last_click() == 'w')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 30);
					}
				}
				Bohater.set_strona_kolizji('0');
				Bohater.uptade();
			}

			if (level == 2) {
				for (int i = 0; i < pszeszkody2.size(); i++) {
					if (Bohater.kolizja_przeszkoda(*pszeszkody2[i]) && pszeszkody2[i]->get_id()==1) {
						//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						{
							//if (Bohater.get_strona_kolizji() == 'd')
							//	Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 'a')
							//	Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 's')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
							//if (Bohater.get_strona_kolizji() == 'w')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
						}
						if (Bohater.get_last_click() == 'd')
							Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 'a')
							Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 's')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
						if (Bohater.get_last_click() == 'w')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
					}
					if (Bohater.kolizja_przeszkoda(*pszeszkody2[i]) && pszeszkody2[i]->get_id() == 2) {
						//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						{
							//if (Bohater.get_strona_kolizji() == 'd')
							//	Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 'a')
							//	Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 's')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
							//if (Bohater.get_strona_kolizji() == 'w')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
						}
						if (Bohater.get_last_click() == 'd')
							Bohater.setPosition(Bohater.getPosition().x - 30, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 'a')
							Bohater.setPosition(Bohater.getPosition().x + 30, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 's')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 30);
						if (Bohater.get_last_click() == 'w')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 30);
					}
				}
				Bohater.set_strona_kolizji('0');
				Bohater.uptade();
			}

			if (level == 3) {
				for (int i = 0; i < pszeszkody3.size(); i++) {
					if (Bohater.kolizja_przeszkoda(*pszeszkody3[i]) && pszeszkody3[i]->get_id()==1) {
						//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						{
							//if (Bohater.get_strona_kolizji() == 'd')
							//	Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 'a')
							//	Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 's')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
							//if (Bohater.get_strona_kolizji() == 'w')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
						}
						if (Bohater.get_last_click() == 'd')
							Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 'a')
							Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 's')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
						if (Bohater.get_last_click() == 'w')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
					}
					if (Bohater.kolizja_przeszkoda(*pszeszkody3[i]) && pszeszkody3[i]->get_id() == 2) {
						//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						{
							//if (Bohater.get_strona_kolizji() == 'd')
							//	Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 'a')
							//	Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
							//if (Bohater.get_strona_kolizji() == 's')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
							//if (Bohater.get_strona_kolizji() == 'w')
							//	Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
						}
						if (Bohater.get_last_click() == 'd')
							Bohater.setPosition(Bohater.getPosition().x - 30, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 'a')
							Bohater.setPosition(Bohater.getPosition().x + 30, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 's')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 30);
						if (Bohater.get_last_click() == 'w')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 30);
					}
				}
				Bohater.set_strona_kolizji('0');
				Bohater.uptade();
			}

			//Sprawdzanie kolizji Bohatera z przeciwnikami
			if (level == 1) {
				for (int i = 0; i < przeciwnicy1.size(); i++) {
					przeciwnicy1[i]->ruch();
					if (Bohater.kolizja_przeciwnik(*przeciwnicy1[i])) {
						if (kol > 10) {
							kol = 0;
							cout << "hit" << endl;
							//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						}
					}
				}
				if (Bohater.getPosition().x < 30 || Bohater.getPosition().x>1890 || Bohater.getPosition().y < 30 || Bohater.getPosition().y>1050) {
					Bohater.setPosition(200, 200);
				}
			}

			if (level == 2) {
				for (int i = 0; i < przeciwnicy2.size(); i++) {
					przeciwnicy2[i]->ruch();
					if (Bohater.kolizja_przeciwnik(*przeciwnicy2[i])) {
						if (kol > 10) {
							kol = 0;
							cout << "hit" << endl;
							//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						}
					}
				}
				if (Bohater.getPosition().x < 30 || Bohater.getPosition().x>1890 || Bohater.getPosition().y < 30 || Bohater.getPosition().y>1050) {
					Bohater.setPosition(200, 200);
				}
			}

			if (level == 3) {
				for (int i = 0; i < przeciwnicy3.size(); i++) {
					przeciwnicy3[i]->ruch();
					if (Bohater.kolizja_przeciwnik(*przeciwnicy3[i])) {
						if (kol > 10) {
							kol = 0;
							cout << "hit" << endl;
							//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						}
					}
				}
				if (Bohater.getPosition().x < 30 || Bohater.getPosition().x>1890 || Bohater.getPosition().y < 30 || Bohater.getPosition().y>1050) {
					Bohater.setPosition(200, 200);
				}
			}

			//Sprawdzanie kolizji przeciwnikow z przeszkodami
			if (level == 1) {
				for (int i = 0; i < przeciwnicy1.size(); i++) {
					for (int j = 0; j < pszeszkody1.size(); j++) {
						if (przeciwnicy1[i]->kolizja_przeszkoda(*pszeszkody1[j])) {
							if (przeciwnicy1[i]->get_vx() > 0.1)
								przeciwnicy1[i]->setPosition(przeciwnicy1[i]->getPosition().x - przeciwnicy1[i]->get_vx(), przeciwnicy1[i]->getPosition().y);
							if (przeciwnicy1[i]->get_vx() < -0.1)
								przeciwnicy1[i]->setPosition(przeciwnicy1[i]->getPosition().x - przeciwnicy1[i]->get_vx(), przeciwnicy1[i]->getPosition().y);
							if (przeciwnicy1[i]->get_vy() > 0.1)
								przeciwnicy1[i]->setPosition(przeciwnicy1[i]->getPosition().x, przeciwnicy1[i]->getPosition().y - przeciwnicy1[i]->get_vy());
							if (przeciwnicy1[i]->get_vy() < -0.1)
								przeciwnicy1[i]->setPosition(przeciwnicy1[i]->getPosition().x, przeciwnicy1[i]->getPosition().y - przeciwnicy1[i]->get_vy());
						}
					}
				}
			}

			if (level == 2) {
				for (int i = 0; i < przeciwnicy2.size(); i++) {
					for (int j = 0; j < pszeszkody2.size(); j++) {
						if (przeciwnicy2[i]->kolizja_przeszkoda(*pszeszkody2[j])) {
							if (przeciwnicy2[i]->get_vx() > 0.1)
								przeciwnicy2[i]->setPosition(przeciwnicy2[i]->getPosition().x - przeciwnicy2[i]->get_vx(), przeciwnicy2[i]->getPosition().y);
							if (przeciwnicy2[i]->get_vx() < -0.1)
								przeciwnicy2[i]->setPosition(przeciwnicy2[i]->getPosition().x - przeciwnicy2[i]->get_vx(), przeciwnicy2[i]->getPosition().y);
							if (przeciwnicy2[i]->get_vy() > 0.1)
								przeciwnicy2[i]->setPosition(przeciwnicy2[i]->getPosition().x, przeciwnicy2[i]->getPosition().y - przeciwnicy2[i]->get_vy());
							if (przeciwnicy2[i]->get_vy() < -0.1)
								przeciwnicy2[i]->setPosition(przeciwnicy2[i]->getPosition().x, przeciwnicy2[i]->getPosition().y - przeciwnicy2[i]->get_vy());
						}
					}
				}
			}

			if (level == 3) {
				for (int i = 0; i < przeciwnicy3.size(); i++) {
					for (int j = 0; j < pszeszkody3.size(); j++) {
						if (przeciwnicy3[i]->kolizja_przeszkoda(*pszeszkody3[j])) {
							if (przeciwnicy3[i]->get_vx() > 0.1)
								przeciwnicy3[i]->setPosition(przeciwnicy3[i]->getPosition().x - przeciwnicy3[i]->get_vx(), przeciwnicy3[i]->getPosition().y);
							if (przeciwnicy3[i]->get_vx() < -0.1)
								przeciwnicy3[i]->setPosition(przeciwnicy3[i]->getPosition().x - przeciwnicy3[i]->get_vx(), przeciwnicy3[i]->getPosition().y);
							if (przeciwnicy3[i]->get_vy() > 0.1)
								przeciwnicy3[i]->setPosition(przeciwnicy3[i]->getPosition().x, przeciwnicy3[i]->getPosition().y - przeciwnicy3[i]->get_vy());
							if (przeciwnicy3[i]->get_vy() < -0.1)
								przeciwnicy3[i]->setPosition(przeciwnicy3[i]->getPosition().x, przeciwnicy3[i]->getPosition().y - przeciwnicy3[i]->get_vy());
						}
					}
				}
			}

			//Rysowanie obiektów
			//podloga
			window.draw(sprajt_podloga);
			//splasze
			for (auto el : splasze) {
				window.draw(el);
			}
			//reszta
			if (level == 1) {
				for (auto el : pszeszkody1) {
					window.draw(el->get_sprajt());
				}
				for (auto el : pociski) {
					window.draw(el);
				}

				window.draw(Bohater.get_sprajt());

				for (auto el : przeciwnicy1) {
					window.draw(el->get_sprajt());
				}
			}

			if (level == 2) {
				for (auto el : pszeszkody2) {
					window.draw(el->get_sprajt());
				}
				for (auto el : pociski) {
					window.draw(el);
				}

				window.draw(Bohater.get_sprajt());

				for (auto el : przeciwnicy2) {
					window.draw(el->get_sprajt());
				}
			}

			if (level == 3) {
				for (auto el : pszeszkody3) {
					window.draw(el->get_sprajt());
				}
				for (auto el : pociski) {
					window.draw(el);
				}

				window.draw(Bohater.get_sprajt());

				for (auto el : przeciwnicy3) {
					window.draw(el->get_sprajt());
				}
			}

			//rysowanie wybuchu
			if (wybuch_x > 0) {
				if (frame_wybuch < 8) {
					s_wyb1.setOrigin(48, 48);
					s_wyb1.setPosition(wybuch_x, wybuch_y);
					window.draw(s_wyb1);
				}
				if (frame_wybuch >= 8 && frame_wybuch < 16) {
					s_wyb2.setOrigin(48, 48);
					s_wyb2.setPosition(wybuch_x, wybuch_y);
					window.draw(s_wyb2);
				}
				if (frame_wybuch >= 16 && frame_wybuch < 24) {
					s_wyb3.setOrigin(48, 48);
					s_wyb3.setPosition(wybuch_x, wybuch_y);
					window.draw(s_wyb3);
				}
				if (frame_wybuch >= 24 && frame_wybuch < 32) {
					s_wyb4.setOrigin(48, 48);
					s_wyb4.setPosition(wybuch_x, wybuch_y);
					window.draw(s_wyb4);
				}
				if (frame_wybuch >= 32 && frame_wybuch < 40) {
					s_wyb5.setOrigin(48, 48);
					s_wyb5.setPosition(wybuch_x, wybuch_y);
					window.draw(s_wyb5);
				}
				if (frame_wybuch >= 40 && frame_wybuch < 48) {
					s_wyb6.setOrigin(48, 48);
					s_wyb6.setPosition(wybuch_x, wybuch_y);
					window.draw(s_wyb6);
				}
				if (frame_wybuch == 49)
				{
					frame_wybuch = 0;
					wybuch_x = -1;
				}
			}
			//zmiana levelu
			if (przeciwnicy1.size() == 0 && level == 1 && frame_level == 0)
				frame_level = 1;
			if (przeciwnicy2.size() == 0 && level == 2 && frame_level == 0)
				frame_level = 1;
			if (przeciwnicy3.size() == 0 && level == 3 && frame_level == 0)
				frame_level = 1;

			if (przeciwnicy1.size() == 0 && level ==1 && frame_level == 120 ) {
				level = 2;
				odliczanie = 2;
				splasze.clear();
				pociski.clear();
				wybuch_x = -100;
				wybuch_y = -100;
				frame_level = 0;
			}
			if (przeciwnicy2.size() == 0&&level==2 && frame_level==120) {
				level = 3;
				odliczanie = 2;
				splasze.clear();
				pociski.clear();
				frame_level = 0;
			}
			if (przeciwnicy3.size() == 0 && level ==3 && frame_level==120) {
				cout << "Koniec gry" << endl;
				frame_level = 0;
			}

			window.display();
		}
	}


	return 0;
}