#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <SFML/Audio.hpp>
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
	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	int score = 1;
	int strzaly = 1;
	while(true){
	cBohater Bohater(150, 150, 140, 140);
	vector<cPrzeciwnik*> przeciwnicy1,przeciwnicy2,przeciwnicy3;
	vector<cPrzeszkoda*> pszeszkody1,pszeszkody2,pszeszkody3;
	vector<cPocisk> pociski;
	//Przeciwnicy
	przeciwnicy1.push_back(new cMinion(1000, 400, 96, 96, 2, 6));
	przeciwnicy1.push_back(new cMinion(1800, 400, 96, 96, 2, 6));
	przeciwnicy1.push_back(new cMinion(1800, 200, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(1800, 300, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(1800, 800, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(1800, 900, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(1000, 700, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(1000, 300, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(1000, 200, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(900, 200, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(700, 300, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(1000, 800, 96, 96, 3, 2));
	przeciwnicy1.push_back(new cMinion(200, 950, 96, 96, 3, 2));

	przeciwnicy2.push_back(new cMinion(600, 200, 96, 96, 3, 2));
	przeciwnicy2.push_back(new cMinion(1200, 700, 96, 96, 3, 2));
	przeciwnicy2.push_back(new cMinion(1300, 700, 96, 96, 3, 2));
	przeciwnicy2.push_back(new cMinion(1300, 900, 96, 96, 3, 6));
	przeciwnicy2.push_back(new cMinion(1400, 900, 96, 96, 3, 6));
	przeciwnicy2.push_back(new cMinion(1050, 200, 96, 96, 3, 6));
	przeciwnicy2.push_back(new cMinion(1050, 300, 96, 96, 3, 6));
	przeciwnicy2.push_back(new cMinion(1050, 400, 96, 96, 3, 6));
	przeciwnicy2.push_back(new cMinion(1050, 400, 96, 96, 3, 6));
	przeciwnicy2.push_back(new cMinion(1050, 400, 96, 96, 3, 6));
	przeciwnicy2.push_back(new cStrzelec(1050, 150, 96, 96, 2, 2));
	przeciwnicy2.push_back(new cStrzelec(1100, 150, 96, 96, 2, 2));
	przeciwnicy2.push_back(new cStrzelec(1200, 150, 96, 96, 2, 2));
	przeciwnicy2.push_back(new cStrzelec(1300, 150, 96, 96, 2, 2));
	przeciwnicy2.push_back(new cStrzelec(1100, 550, 96, 96, 2, 2));
	przeciwnicy2.push_back(new cStrzelec(1200, 550, 96, 96, 2, 2));
	przeciwnicy2.push_back(new cStrzelec(1300, 550, 96, 96, 2, 2));

	przeciwnicy3.push_back(new cStrzelec(900, 900, 96, 96, 2, 3));
	przeciwnicy3.push_back(new cStrzelec(1200, 900, 96, 96, 2, 3));
	przeciwnicy3.push_back(new cStrzelec(1300, 900, 96, 96, 2, 3));
	przeciwnicy3.push_back(new cStrzelec(1400, 900, 96, 96, 2, 3));
	przeciwnicy3.push_back(new cStrzelec(1500, 900, 96, 96, 2, 3));
	przeciwnicy3.push_back(new cStrzelec(1050, 150, 96, 96, 2, 2));
	przeciwnicy3.push_back(new cStrzelec(1100, 150, 96, 96, 2, 2));
	przeciwnicy3.push_back(new cStrzelec(1200, 150, 96, 96, 2, 2));
	przeciwnicy3.push_back(new cStrzelec(1300, 150, 96, 96, 2, 2));
	przeciwnicy3.push_back(new cStrzelec(1100, 550, 96, 96, 2, 2));
	przeciwnicy3.push_back(new cMinion(200, 800, 96, 96, 3, 6));
	przeciwnicy3.push_back(new cMinion(300, 800, 96, 96, 3, 6));
	przeciwnicy3.push_back(new cMinion(400, 800, 96, 96, 3, 6));
	przeciwnicy3.push_back(new cMinion(500, 800, 96, 96, 3, 6));
	przeciwnicy3.push_back(new cMinion(600, 800, 96, 96, 3, 6));
	przeciwnicy3.push_back(new cMinion(700, 800, 96, 96, 3, 6));
	//Pszeszkody
	pszeszkody1.push_back(new cPrzeszkoda(960,32,1920,64,1));
	pszeszkody1.push_back(new cPrzeszkoda(960, 1048, 1920, 64,1));
	pszeszkody1.push_back(new cPrzeszkoda(32, 540, 64, 1080,1));
	pszeszkody1.push_back(new cPrzeszkoda(1888, 540, 64, 1080,1));
	pszeszkody1.push_back(new cPrzeszkoda(348, 190, 64, 254,1));
	pszeszkody1.push_back(new cPrzeszkoda(285, 792, 445, 64,1));
	pszeszkody1.push_back(new cPrzeszkoda(1696, 540, 320, 64, 1));
	pszeszkody1.push_back(new cPrzeszkoda(1504, 540, 64, 570, 1));
	pszeszkody1.push_back(new cPrzeszkoda(900, 600, 50, 64, 2));
	pszeszkody1.push_back(new cPrzeszkoda(900, 300, 50, 64, 2));

	pszeszkody2.push_back(new cPrzeszkoda(960, 32, 1920, 64, 1));
	pszeszkody2.push_back(new cPrzeszkoda(960, 1048, 1920, 64, 1));
	pszeszkody2.push_back(new cPrzeszkoda(32, 540, 64, 1080, 1));
	pszeszkody2.push_back(new cPrzeszkoda(1888, 540, 64, 1080, 1));
	pszeszkody2.push_back(new cPrzeszkoda(445, 728, 952, 64, 1));
	pszeszkody2.push_back(new cPrzeszkoda(950, 223, 64, 318, 1));
	pszeszkody2.push_back(new cPrzeszkoda(1200, 400, 50, 64, 2));
	pszeszkody2.push_back(new cPrzeszkoda(1250, 400, 50, 64, 2));
	pszeszkody2.push_back(new cPrzeszkoda(1300, 400, 50, 64, 2));
	pszeszkody2.push_back(new cPrzeszkoda(1350, 400, 50, 64, 2));
	pszeszkody2.push_back(new cPrzeszkoda(1400, 700, 50, 64, 2));
	pszeszkody2.push_back(new cPrzeszkoda(1450, 700, 50, 64, 2));

	pszeszkody3.push_back(new cPrzeszkoda(960, 32, 1920, 64, 1));
	pszeszkody3.push_back(new cPrzeszkoda(960, 1048, 1920, 64, 1));
	pszeszkody3.push_back(new cPrzeszkoda(32, 540, 64, 1080, 1));
	pszeszkody3.push_back(new cPrzeszkoda(1888, 540, 64, 1080, 1));
	pszeszkody3.push_back(new cPrzeszkoda(950, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1000, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1050, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1100, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1150, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1300, 300, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1350, 300, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1400, 300, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(1450, 300, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(300, 96, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(300, 160, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(300, 224, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(300, 288, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(300, 352, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(300, 416, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(96, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(146, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(196, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(246, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(296, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(346, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(396, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(446, 700, 50, 64, 2));
	pszeszkody3.push_back(new cPrzeszkoda(496, 700, 50, 64, 2));

	//Tekstury
	Texture tekstura_podloga, t_wyb1, t_wyb2, t_wyb3, t_wyb4, t_wyb5, t_wyb6, t_splasz,t_menu,t_ogien1,t_ogien2,t_ogien3,t_hit,t_serce;
		tekstura_podloga.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\podloga.png");
		t_hit.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\bohater_hit.png");

		t_wyb1.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch1.png");
		t_wyb2.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch2.png");
		t_wyb3.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch3.png");
		t_wyb4.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch4.png");
		t_wyb5.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch5.png");
		t_wyb6.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch6.png");

		t_ogien1.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\ogien1.png");
		t_ogien2.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\ogien2.png");
		t_ogien3.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\ogien3.png");

		t_serce.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\serce.png");

		t_splasz.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\splasz.png");
		Sprite sprajt_podloga, s_wyb1, s_wyb2, s_wyb3, s_wyb4, s_wyb5, s_wyb6,s_menu,s_ogien1,s_ogien2,s_ogien3,s_hit,s_serce;
		sprajt_podloga.setTexture(tekstura_podloga);
		s_hit.setTexture(t_hit);

		s_wyb1.setTexture(t_wyb1);
		s_wyb2.setTexture(t_wyb2);
		s_wyb3.setTexture(t_wyb3);
		s_wyb4.setTexture(t_wyb4);
		s_wyb5.setTexture(t_wyb5);
		s_wyb6.setTexture(t_wyb6);

		s_ogien1.setTexture(t_ogien1);
		s_ogien2.setTexture(t_ogien2);
		s_ogien3.setTexture(t_ogien3);

		s_serce.setTexture(t_serce);

	//Muzyka
		Music muzyka;
		muzyka.openFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\muzyka.wav");
		muzyka.setVolume(60);
		SoundBuffer b_laser,b_runda1,b_runda2,b_runda3,b_wybuch,b_hurt,b_hit,b_count;
		b_laser.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\laser.wav");
		b_runda1.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\runda1.wav");
		b_runda2.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\runda2.wav");
		b_runda3.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\runda3.wav");
		b_wybuch.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\wybuch.wav");
		b_hurt.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\hurt.wav");
		b_hit.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\hit.wav");
		b_count.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\odliczanie.wav");
		Sound laser,runda1,runda2,runda3,wybuch,hurt,hitt,count;
		laser.setBuffer(b_laser);
		count.setBuffer(b_count);
		count.setVolume(80);
		hitt.setBuffer(b_hit);
		hitt.setVolume(60);
		runda1.setBuffer(b_runda1);
		runda2.setBuffer(b_runda2);
		runda3.setBuffer(b_runda3);
		wybuch.setBuffer(b_wybuch);
		wybuch.setVolume(50);
		hurt.setBuffer(b_hurt);
		hurt.setVolume(40);
	//

	window.setFramerateLimit(60);
	Event event;
	srand(time(0));
	int frame_normal = 0, kol = 0, kol_pocisk = 0, strzal = 0, frame_fast = 0, frame_wybuch = 0, frame_ogien=0;
	vector<cPocisk>::iterator itr_kol;
	vector<Sprite> splasze;
	int wybuch_x = -1, wybuch_y = -1;
	int   level = 1, odliczanie = 1, frame_level = 0, hit = 1, frame_hit = 0, frame_ochrona = 0, muza = 1,play_music=1;
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
			score += 10000;
			for (int i = 0; i < przeciwnicy1.size(); i++) {
				przeciwnicy1[i]->set_life(przeciwnicy1[i]->get_life()*0.5);
				przeciwnicy1[i]->set_basic_life(przeciwnicy1[i]->get_basic_life()*0.5);
				przeciwnicy1[i]->set_basic_v(przeciwnicy1[i]->get_basic_v()*0.5);
			}
			for (int i = 0; i < przeciwnicy2.size(); i++) {
				przeciwnicy2[i]->set_life(przeciwnicy2[i]->get_life()*0.5);
				przeciwnicy2[i]->set_basic_life(przeciwnicy2[i]->get_basic_life()*0.5);
				przeciwnicy2[i]->set_basic_v(przeciwnicy2[i]->get_basic_v()*0.5);
			}
			for (int i = 0; i < przeciwnicy3.size(); i++) {
				przeciwnicy3[i]->set_life(przeciwnicy3[i]->get_life()*0.5);
				przeciwnicy3[i]->set_basic_life(przeciwnicy3[i]->get_basic_life()*0.5);
				przeciwnicy3[i]->set_basic_v(przeciwnicy3[i]->get_basic_v()*0.5);
			}
			stan_opcji = "0";
			stan_gry = "1_";
		}
		if (stan_opcji == "trudny") {
			score += 50000;
			for (int i = 0; i < przeciwnicy1.size(); i++) {
				przeciwnicy1[i]->set_life(przeciwnicy1[i]->get_life()*1.5);
				przeciwnicy1[i]->set_basic_life(przeciwnicy1[i]->get_basic_life()*1.5);
				przeciwnicy1[i]->set_basic_v(przeciwnicy1[i]->get_basic_v()*0.5);
			}
			for (int i = 0; i < przeciwnicy2.size(); i++) {
				przeciwnicy2[i]->set_life(przeciwnicy2[i]->get_life()*1.5);
				przeciwnicy2[i]->set_basic_life(przeciwnicy2[i]->get_basic_life()*1.5);
				przeciwnicy2[i]->set_basic_v(przeciwnicy2[i]->get_basic_v()*0.5);
			}
			for (int i = 0; i < przeciwnicy3.size(); i++) {
				przeciwnicy3[i]->set_life(przeciwnicy3[i]->get_life()*1.5);
				przeciwnicy3[i]->set_basic_life(przeciwnicy3[i]->get_basic_life()*1.5);
				przeciwnicy3[i]->set_basic_v(przeciwnicy3[i]->get_basic_v()*0.5);
			}
			stan_opcji = "0";
			stan_gry = "1_";
		}

		else if (stan_gry == "2_") {

			if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				stan_gry = "1_";
			}
			if (odliczanie == 2 ) {
				for (int i = 0; i < 270; i++) {
					window.display();
					window.clear();
					if (i == 60)
						count.play();
					if (i >= 60 && i < 270) {
						if (level == 1) {
							window.draw(sprajt_podloga);
							for (auto el : pszeszkody1) {
								if(el->get_id() == 1)
									window.draw(el->get_sprajt());
								if (el->get_id() == 2) {
									s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
									window.draw(s_ogien3);
								}
									
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
								if (el->get_id() == 1)
									window.draw(el->get_sprajt());
								if (el->get_id() == 2) {
									s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
									window.draw(s_ogien3);
								}

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
								if (el->get_id() == 1)
									window.draw(el->get_sprajt());
								if (el->get_id() == 2) {
									s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
									window.draw(s_ogien3);
								}

							}
							for (auto el : pociski) {
								window.draw(el);
							}

							window.draw(Bohater.get_sprajt());

							for (auto el : przeciwnicy3) {
								window.draw(el->get_sprajt());
							}
						}
					}

					if (i < 60 && level==1) {
						if (muza == 1) {
							runda1.play();
							muza = 2;
						}
						window.draw(s_menu);
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("Runda 1", font, 100);
						tekst.setOutlineColor(Color::Red);
						tekst.setOutlineThickness(5);
						tekst.setPosition(800, 400);
						window.draw(tekst);
						if (i == 59)
							muza = 1;
					}

					if (i < 60 && level == 2) {
						if (muza == 1) {
							runda2.play();
							muza = 2;
						}
						window.draw(s_menu);
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("Runda 2", font, 100);
						tekst.setOutlineColor(Color::Red);
						tekst.setOutlineThickness(5);
						tekst.setPosition(800, 400);
						window.draw(tekst);
						if (i == 59)
							muza = 1;
					}

					if (i < 60 && level == 3) {
						if (muza == 1) {
							runda3.play();
							muza = 2;
						}
						window.draw(s_menu);
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("Runda 3", font, 100);
						tekst.setOutlineColor(Color::Red);
						tekst.setOutlineThickness(5);
						tekst.setPosition(800, 400);
						window.draw(tekst);
					}

					if (i >= 60 && i<120) {
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("3", font, 100);
						tekst.setOutlineColor(Color::Black);
						tekst.setOutlineThickness(5);
						tekst.setPosition(940, 400);
						window.draw(tekst);
					}
					if (i >= 120 && i <180) {
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("2", font, 100);
						tekst.setOutlineColor(Color::Black);
						tekst.setOutlineThickness(5);
						tekst.setPosition(940, 400);
						window.draw(tekst);
					}
					if (i >= 180 && i<240) {
						Font font;
						font.loadFromFile("arial.ttf");
						Text tekst("1", font, 100);
						tekst.setOutlineColor(Color::Black);
						tekst.setOutlineThickness(5);
						tekst.setPosition(940, 400);
						window.draw(tekst);
					}
					if (i >= 240 && i < 270) {
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
			if (play_music == 1) {
				muzyka.play();
				play_music = 2;
			}
			if (frame_wybuch > 0)
				frame_wybuch++;
			if (frame_level > 0) {
				frame_level++;
			}
			if (frame_hit > 0)
				frame_hit++;
			frame_ochrona++;
			frame_ogien++;
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
							if (los == 0 && przeciwnicy1[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x, przeciwnicy1[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy1[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->getPosition().x, przeciwnicy1[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy1[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy1[i]->left() - 2, przeciwnicy1[i]->getPosition().y, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy1[i]->get_basic_v() <= 2) {
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
							if (los == 0 && przeciwnicy2[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x, przeciwnicy2[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy2[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->getPosition().x, przeciwnicy2[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy2[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy2[i]->left() - 2, przeciwnicy2[i]->getPosition().y, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy2[i]->get_basic_v() <= 2) {
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
							if (los == 0 && przeciwnicy3[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x, przeciwnicy3[i]->top() - 3, 10, 0, -12, 2));
							}
							if (los == 1 && przeciwnicy3[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->getPosition().x, przeciwnicy3[i]->bottom() + 3, 10, 0, 12, 2));
							}
							if (los == 2 && przeciwnicy3[i]->get_basic_v() <= 2) {
								pociski.push_back(cPocisk(przeciwnicy3[i]->left() - 2, przeciwnicy3[i]->getPosition().y, 10, -12, 0, 2));
							}
							if (los == 3 && przeciwnicy3[i]->get_basic_v() <= 2) {
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
				pociski.push_back(cPocisk(Bohater.getPosition().x + 43, Bohater.top() - 3, 10, 0, -12, 1));
				strzal = 0;
				Bohater.sprajt_rotate(0);
				strzaly++;
				laser.play();
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down) && strzal > 10) {
				pociski.push_back(cPocisk(Bohater.getPosition().x - 43, Bohater.bottom() + 3, 10, 0, 12, 1));
				strzal = 0;
				Bohater.sprajt_rotate(180);
				strzaly++;
				laser.play();
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Left) && strzal > 10) {
				pociski.push_back(cPocisk(Bohater.left() - 2, Bohater.getPosition().y - 43, 10, -12, 0, 1));
				strzal = 0;
				Bohater.sprajt_rotate(270);
				strzaly++;
				laser.play();
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right) && strzal > 10) {
				pociski.push_back(cPocisk(Bohater.right() + 2, Bohater.getPosition().y + 43, 10, 12, 0, 1));
				strzal = 0;
				Bohater.sprajt_rotate(90);
				strzaly++;
				laser.play();
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
						if (itr->kolizja_przeszkoda(*pszeszkody1[j]) && pszeszkody1[j]->get_id()==1) {
							kol_pocisk = 1;
							break;
						}
					}
					for (int j = 0; j < przeciwnicy1.size(); j++) {
						if (itr->kolizja_przeciwnik(*przeciwnicy1[j])) {
							kol_pocisk = 1;
							if (itr->get_id() == 1) {
								przeciwnicy1[j]->zranienie();
								hitt.play();
							}
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
								score += 1000;
							}
							break;
						}
					}
					if (itr->kolizja_bohater(Bohater)) {
						kol_pocisk = 1;
						frame_hit = 1;
						if (frame_ochrona > 15) {
							hurt.play();
							Bohater.zranienie();
							frame_ochrona = 0;
						}
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
						if (itr->kolizja_przeszkoda(*pszeszkody2[j]) && pszeszkody2[j]->get_id() == 1) {
							kol_pocisk = 1;
							break;
						}
					}
					for (int j = 0; j < przeciwnicy2.size(); j++) {
						if (itr->kolizja_przeciwnik(*przeciwnicy2[j])) {
							kol_pocisk = 1;
							if (itr->get_id() == 1) {
								przeciwnicy2[j]->zranienie();
								hitt.play();
							}
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
								score += 1000;
							}

							break;
						}
					}
					if (itr->kolizja_bohater(Bohater)) {
						kol_pocisk = 1;
						frame_hit = 1;
						if (frame_ochrona > 15) {
							hurt.play();
							Bohater.zranienie();
							frame_ochrona = 0;
						}
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
						if (itr->kolizja_przeszkoda(*pszeszkody3[j]) && pszeszkody3[j]->get_id() == 1) {
							kol_pocisk = 1;
							break;
						}
					}
					for (int j = 0; j < przeciwnicy3.size(); j++) {
						if (itr->kolizja_przeciwnik(*przeciwnicy3[j])) {
							kol_pocisk = 1;
							if (itr->get_id() == 1) {
								przeciwnicy3[j]->zranienie();
								hitt.play();
							}
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
								score += 1000;
							}
							break;
						}
					}
					if (itr->kolizja_bohater(Bohater)) {
						kol_pocisk = 1;
						frame_hit = 1;
						hurt.play();
						if (frame_ochrona > 15) {
							Bohater.zranienie();
							frame_ochrona = 0;
						}
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
						frame_hit = 1;
						if (frame_ochrona > 15) {
							hurt.play();
							Bohater.zranienie();
							frame_ochrona = 0;
						}
						if (Bohater.get_last_click() == 'd')
							Bohater.setPosition(Bohater.getPosition().x - 40, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 'a')
							Bohater.setPosition(Bohater.getPosition().x + 40, Bohater.getPosition().y);
						if (Bohater.get_last_click() == 's')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 40);
						if (Bohater.get_last_click() == 'w')
							Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 40);
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
						frame_hit = 1;
						if (frame_ochrona > 15) {
							hurt.play();
							Bohater.zranienie();
							frame_ochrona = 0;
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
						frame_hit = 1;
						if (frame_ochrona > 15) {
							hurt.play();
							Bohater.zranienie();
							frame_ochrona = 0;
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
							frame_hit = 1;
							if (frame_ochrona > 15) {
								hurt.play();
								Bohater.zranienie();
								frame_ochrona = 0;
							}
							//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						}
					}
				}
				if ((Bohater.getPosition().x < 30 || Bohater.getPosition().x>1890 || Bohater.getPosition().y < 30 || Bohater.getPosition().y>1050) && Bohater.get_life()!=0) {
					Bohater.setPosition(200, 200);
				}
			}

			if (level == 2) {
				for (int i = 0; i < przeciwnicy2.size(); i++) {
					przeciwnicy2[i]->ruch();
					if (Bohater.kolizja_przeciwnik(*przeciwnicy2[i])) {
						if (kol > 10) {
							kol = 0;
							frame_hit = 1;
							if (frame_ochrona > 15) {
								hurt.play();
								Bohater.zranienie();
								frame_ochrona = 0;
							}
							//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						}
					}
				}
				if ((Bohater.getPosition().x < 30 || Bohater.getPosition().x>1890 || Bohater.getPosition().y < 30 || Bohater.getPosition().y>1050) && Bohater.get_life()!=0) {
					Bohater.setPosition(200, 200);
				}
			}

			if (level == 3) {
				for (int i = 0; i < przeciwnicy3.size(); i++) {
					przeciwnicy3[i]->ruch();
					if (Bohater.kolizja_przeciwnik(*przeciwnicy3[i])) {
						if (kol > 10) {
							kol = 0;
							frame_hit = 1;
							if (frame_ochrona > 15) {
								hurt.play();
								Bohater.zranienie();
								frame_ochrona = 0;
							}
							//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
						}
					}
				}
				if ((Bohater.getPosition().x < 30 || Bohater.getPosition().x>1890 || Bohater.getPosition().y < 30 || Bohater.getPosition().y>1050)&& Bohater.get_life()!=0) {
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
					if(el->get_id()==1)
					window.draw(el->get_sprajt());
					else if (el->get_id() == 2) {
						s_ogien1.setPosition(el->getPosition().x - 25, el->getPosition().y-32);
						s_ogien2.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						if (frame_ogien < 15) {
							window.draw(s_ogien1);
						}
						if (frame_ogien < 30 && frame_ogien >=15) {
							window.draw(s_ogien2);
						}
						if (frame_ogien <= 45 && frame_ogien >= 30) {
							window.draw(s_ogien3);
						}
						if (frame_ogien == 45)
							frame_ogien = 0;

					}
				}
				for (auto el : pociski) {
					window.draw(el);
				}
				if(frame_hit==0)
					window.draw(Bohater.get_sprajt());
				if (frame_hit > 0 && frame_hit <= 15) {
					s_hit.setPosition(Bohater.getPosition().x, Bohater.getPosition().y);
					s_hit.setOrigin(Bohater.get_a() / 2, Bohater.get_b() / 2);
					s_hit.setRotation(Bohater.get_angle());
					window.draw(s_hit);
					if (frame_hit == 15)
						frame_hit = 0;
				}

				for (auto el : przeciwnicy1) {
					window.draw(el->get_sprajt());
				}
			}

			if (level == 2) {
				for (auto el : pszeszkody2) {
					if (el->get_id() == 1)
						window.draw(el->get_sprajt());
					else if (el->get_id() == 2) {
						s_ogien1.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						s_ogien2.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						if (frame_ogien < 15) {
							window.draw(s_ogien1);
						}
						if (frame_ogien < 30 && frame_ogien >= 15) {
							window.draw(s_ogien2);
						}
						if (frame_ogien <= 45 && frame_ogien >= 30) {
							window.draw(s_ogien3);
						}
						if (frame_ogien == 45)
							frame_ogien = 0;

					}
				}
				for (auto el : pociski) {
					window.draw(el);
				}

				if (frame_hit == 0)
					window.draw(Bohater.get_sprajt());
				if (frame_hit > 0 && frame_hit <= 10) {
					s_hit.setPosition(Bohater.getPosition().x, Bohater.getPosition().y);
					s_hit.setOrigin(Bohater.get_a() / 2, Bohater.get_b() / 2);
					s_hit.setRotation(Bohater.get_angle());
					window.draw(s_hit);
					if (frame_hit == 10)
						frame_hit = 0;
				}

				if (frame_hit > 0 && frame_hit <= 10) {
					s_hit.setPosition(Bohater.getPosition().x, Bohater.getPosition().y);
					s_hit.setOrigin(Bohater.get_a() / 2, Bohater.get_b() / 2);
					s_hit.setRotation(Bohater.get_angle());
					window.draw(s_hit);
					if (frame_hit == 10)
						frame_hit = 0;
				}

				for (auto el : przeciwnicy2) {
					window.draw(el->get_sprajt());
				}
			}

			if (level == 3) {
				for (auto el : pszeszkody3) {
					if (el->get_id() == 1)
						window.draw(el->get_sprajt());
					else if (el->get_id() == 2) {
						s_ogien1.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						s_ogien2.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						if (frame_ogien < 15) {
							window.draw(s_ogien1);
						}
						if (frame_ogien < 30 && frame_ogien >= 15) {
							window.draw(s_ogien2);
						}
						if (frame_ogien <= 45 && frame_ogien >= 30) {
							window.draw(s_ogien3);
						}
						if (frame_ogien == 45)
							frame_ogien = 0;

					}
				}
				for (auto el : pociski) {
					window.draw(el);
				}

				if (frame_hit == 0)
					window.draw(Bohater.get_sprajt());
				if (frame_hit > 0 && frame_hit <= 10) {
					s_hit.setPosition(Bohater.getPosition().x, Bohater.getPosition().y);
					s_hit.setOrigin(Bohater.get_a() / 2, Bohater.get_b() / 2);
					s_hit.setRotation(Bohater.get_angle());
					window.draw(s_hit);
					if (frame_hit == 10)
						frame_hit = 0;
				}

				if (frame_hit > 0 && frame_hit <= 10) {
					s_hit.setPosition(Bohater.getPosition().x, Bohater.getPosition().y);
					s_hit.setOrigin(Bohater.get_a() / 2, Bohater.get_b() / 2);
					s_hit.setRotation(Bohater.get_angle());
					window.draw(s_hit);
					if (frame_hit == 10)
						frame_hit = 0;
				}

				for (auto el : przeciwnicy3) {
					window.draw(el->get_sprajt());
				}
			}

			//rysowanie zycia

			if (Bohater.get_life() == 3) {
				s_serce.setPosition(0, 0);
				window.draw(s_serce);
				s_serce.setPosition(64, 0);
				window.draw(s_serce);
				s_serce.setPosition(128, 0);
				window.draw(s_serce);
			}

			if (Bohater.get_life() == 2) {
				s_serce.setPosition(0, 0);
				window.draw(s_serce);
				s_serce.setPosition(64, 0);
				window.draw(s_serce);
			}

			if (Bohater.get_life() == 1) {
				s_serce.setPosition(0, 0);
				window.draw(s_serce);
			}

			//rysowanie wybuchu
			if (wybuch_x > 0) {
				if (frame_wybuch == 4)
					wybuch.play();
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
			//Koniec bohatera
			if (Bohater.get_life() == 0 && Bohater.getPosition().x>0) {
				wybuch_x = Bohater.getPosition().x;
				wybuch_y = Bohater.getPosition().y;
				frame_wybuch = 1;
				Bohater.setPosition(-200, -200);
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
				Bohater.setPosition(150, 150);
				Bohater.uptade();
				muzyka.stop();
				play_music = 1;
			}
			if (przeciwnicy2.size() == 0&&level==2 && frame_level==120) {
				level = 3;
				odliczanie = 2;
				splasze.clear();
				pociski.clear();
				wybuch_x = -100;
				wybuch_y = -100;
				frame_level = 0;
				Bohater.setPosition(150, 150);
				Bohater.uptade();
				muzyka.stop();
				play_music = 1;
			}
			if (przeciwnicy3.size() == 0 && level ==3 && frame_level==120) {
				frame_level = 0;
				wybuch_x = -100;
				wybuch_y = -100;
				frame_level = 0;
				Bohater.setPosition(200, 200);
				muzyka.stop();
				play_music = 1;
				break;
			}

			if (Bohater.get_life() == 0 && frame_ochrona>70) {
				muzyka.stop();
				break;
			}
			//rysowanie zdrowia przeciwnikow
			if (level == 1) {
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst;
				tekst.setFont(font);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(2);
				for (int i = 0; i < przeciwnicy1.size(); i++)
				{
					tekst.setPosition(przeciwnicy1[i]->getPosition().x-20, przeciwnicy1[i]->getPosition().y-85);
					char s1[10],s2[10];
					_itoa_s(przeciwnicy1[i]->get_life(), s1, 10);
					_itoa_s(przeciwnicy1[i]->get_basic_life(), s2, 10);
					string str1=s1,str2=s2,str;
					str = str1 + "/" + str2;
					tekst.setString(str);
					tekst.setFillColor(Color::Green);
					if ((float)przeciwnicy1[i]->get_life() / (float)przeciwnicy1[i]->get_basic_life() < 0.67 && (float)przeciwnicy1[i]->get_life() / (float)przeciwnicy1[i]->get_basic_life() > 0.34)
						tekst.setFillColor(Color::Yellow);
					if ((float)przeciwnicy1[i]->get_life() / (float)przeciwnicy1[i]->get_basic_life() < 0.34)
						tekst.setFillColor(Color::Red);
					window.draw(tekst);
				}
			}
			if (level == 2) {
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst;
				tekst.setFont(font);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(2);
				for (int i = 0; i < przeciwnicy2.size(); i++)
				{
					tekst.setPosition(przeciwnicy2[i]->getPosition().x - 20, przeciwnicy2[i]->getPosition().y - 85);
					char s1[10], s2[10];
					_itoa_s(przeciwnicy2[i]->get_life(), s1, 10);
					_itoa_s(przeciwnicy2[i]->get_basic_life(), s2, 10);
					string str1 = s1, str2 = s2, str;
					str = str1 + "/" + str2;
					tekst.setString(str);
					tekst.setFillColor(Color::Green);
					if ((float)przeciwnicy2[i]->get_life() / (float)przeciwnicy2[i]->get_basic_life() < 0.67 && (float)przeciwnicy2[i]->get_life() / (float)przeciwnicy2[i]->get_basic_life() > 0.34)
						tekst.setFillColor(Color::Yellow);
					if ((float)przeciwnicy2[i]->get_life() / (float)przeciwnicy2[i]->get_basic_life() < 0.34)
						tekst.setFillColor(Color::Red);
					window.draw(tekst);
				}
			}
			if (level == 3) {
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst;
				tekst.setFont(font);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(2);
				for (int i = 0; i < przeciwnicy3.size(); i++)
				{
					tekst.setPosition(przeciwnicy3[i]->getPosition().x - 20, przeciwnicy3[i]->getPosition().y - 85);
					char s1[10], s2[10];
					_itoa_s(przeciwnicy3[i]->get_life(), s1, 10);
					_itoa_s(przeciwnicy3[i]->get_basic_life(), s2, 10);
					string str1 = s1, str2 = s2, str;
					str = str1 + "/" + str2;
					tekst.setString(str);
					tekst.setFillColor(Color::Green);
					if ((float)przeciwnicy3[i]->get_life() / (float)przeciwnicy3[i]->get_basic_life() < 0.67 && (float)przeciwnicy3[i]->get_life() / (float)przeciwnicy3[i]->get_basic_life() > 0.34)
						tekst.setFillColor(Color::Yellow);
					if ((float)przeciwnicy3[i]->get_life() / (float)przeciwnicy3[i]->get_basic_life() < 0.34)
						tekst.setFillColor(Color::Red);
					window.draw(tekst);
				}
			}
			window.display();
		}
	}
	for (int i = 0; i < 180;i++) {
		float wynik;
		if(Bohater.get_life()==0)
			wynik = (float)score / (float)strzaly;
		if (Bohater.get_life() == 1)
			wynik = ((float)score*20) / (float)strzaly;
		if (Bohater.get_life() == 2)
			wynik = ((float)score * 60) / (float)strzaly;
		if (Bohater.get_life() == 3)
			wynik = ((float)score * 80) / (float)strzaly;
		(int)wynik;
		window.clear();
		Font font;
		font.loadFromFile("arial.ttf");
		Text tekst,opis;
		tekst.setFont(font);
		tekst.setCharacterSize(100);
		opis.setFont(font);
		opis.setCharacterSize(40);
		opis.setString("(Wynik zalezy od wystrzelonych pociskow, stanu zdrowia i poziomu trudnosci)");
		if (Bohater.get_life() == 0) {
			char s[10];
			string str,str2="Twoj wynik:  ";
			_itoa_s(wynik, s, 10);
			str = s;
			tekst.setString("    Przegrales!\n" + str2 + str);
		}
		if (Bohater.get_life() != 0) {
			char s[10];
			string str, str2 = "Twoj wynik:  ";
			_itoa_s(wynik, s, 10);
			str = s;
			tekst.setString("    Wygrales!\n" + str2 + str);
		}

		tekst.setOutlineColor(Color::Black);
		tekst.setOutlineThickness(5);
		tekst.setPosition(600, 400);
		opis.setOutlineColor(Color::Black);
		opis.setOutlineThickness(5);
		opis.setPosition(250, 300);
		window.draw(tekst);
		window.draw(opis);
		window.display();
	}
	score = 1;
	strzaly = 1;
	}
	return 0;
}