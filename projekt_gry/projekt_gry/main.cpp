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
#include "cPlansza_1.h"
#include "cPlansza_2.h"
#include "cPlansza_3.h"
using namespace sf;
using namespace std;


int main() {
	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	Event event;
	window.setFramerateLimit(60);
	int koniec_gry = 0;

	//G³ówna pêtla gry
	while(true){
		cPlansza_1 plansza1;
		cPlansza_2 plansza2;
		cPlansza_3 plansza3;

		srand(time(0));
		int frame_level = 0,level=1;
		string stan_gry = "1_";
		string stan_opcji = "0";

		//Pêtla obs³uguj¹ca zdarzenia w grze
		while (true) {
		//Obs³uga menu

		if (stan_gry == "1_") {
			stan_gry = funkcja_menu(window);
			if (stan_gry == "2_") {
				plansza1.set_stan_odliczania(2);
				plansza2.set_stan_odliczania(2);
				plansza3.set_stan_odliczania(2);
			}
		}
		if (stan_gry == "opcje") {
			stan_opcji = funkcja_opcje(window);
		}
		if (stan_opcji == "latwy") {
			stan_opcji = "0";
			stan_gry = "1_";
		}
		if (stan_opcji == "sredni") {
			plansza1.poziom_trudnosci(2);
			plansza2.poziom_trudnosci(2);
			plansza3.poziom_trudnosci(2);
			stan_opcji = "0";
			stan_gry = "1_";
		}
		if (stan_opcji == "trudny") {
			plansza1.poziom_trudnosci(3);
			plansza2.poziom_trudnosci(3);
			plansza3.poziom_trudnosci(3);
			stan_opcji = "0";
			stan_gry = "1_";
		}

		//Obs³uga gry
		else if (stan_gry == "2_") {
			//Puaza
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				stan_gry = "1_";
				plansza1.koniec_muzyki();
			}
			//obs³uga okna
			window.clear(Color::Black);
			window.pollEvent(event);
			if (event.type == Event::Closed) {
				window.close();
				break;
			}

			if (frame_level >= 1)
				frame_level++;

			//wywo³ywanie funkcji plansz
			if (level == 1) {
				plansza1.odliczanie(window);
				plansza1.aktualizuj();
				plansza1.start_muzyki();
				plansza1.pociski_bohatera();
				plansza1.ruch_pociskow();
				plansza1.nadawanie_predkosci_przeciwnikom();
				plansza1.kolizja_bohater_przeszkody();
				plansza1.kolizja_pociskow();
				plansza1.kolizja_bohater_przeciwnicy();
				plansza1.kolizja_przeciwnicy_przeszkody();
				plansza1.koniec_bohatera();

				//rysowanie
				plansza1.rysowanie_podlogi(window);
				for (auto el : plansza1.get_splasze()) {
					window.draw(el);
				}
				for (auto el : plansza1.get_przeciwnicy()) {
					window.draw(el->get_sprajt());
				}
				for (auto el : plansza1.get_pszeszkody()) {
					if (el->get_id() == 1)
						window.draw(el->get_sprajt());
					else if (el->get_id() == 2)
						plansza1.rysowanie_ognia(window);
				}
				for (auto el : plansza1.get_pociski()) {
					window.draw(el);
				}
				plansza1.rysowanie_ognia(window);
				plansza1.rysowanie_zycia(window);
				plansza1.rysowanie_wybuchu(window);
				plansza1.rysowanie_zdrowia_przeciwnikow(window);
				plansza1.rysowanie_bohatera(window);
			}

			if (level == 2) {
				plansza2.odliczanie(window);
				plansza2.aktualizuj();
				plansza2.start_muzyki();
				plansza2.pociski_bohatera();
				plansza2.ruch_pociskow();
				plansza2.nadawanie_predkosci_przeciwnikom();
				plansza2.kolizja_bohater_przeszkody();
				plansza2.kolizja_pociskow();
				plansza2.kolizja_bohater_przeciwnicy();
				plansza2.kolizja_przeciwnicy_przeszkody();
				plansza2.koniec_bohatera();

				//rysowanie
				plansza2.rysowanie_podlogi(window);
				for (auto el : plansza2.get_splasze()) {
					window.draw(el);
				}
				for (auto el : plansza2.get_przeciwnicy()) {
					window.draw(el->get_sprajt());
				}
				for (auto el : plansza2.get_pszeszkody()) {
					if (el->get_id() == 1)
						window.draw(el->get_sprajt());
					else if (el->get_id() == 2)
						plansza2.rysowanie_ognia(window);
				}
				for (auto el : plansza2.get_pociski()) {
					window.draw(el);
				}
				plansza2.rysowanie_ognia(window);
				plansza2.rysowanie_zycia(window);
				plansza2.rysowanie_wybuchu(window);
				plansza2.rysowanie_zdrowia_przeciwnikow(window);
				plansza2.rysowanie_bohatera(window);
			}

			if (level == 3) {
				plansza3.odliczanie(window);
				plansza3.aktualizuj();
				plansza3.start_muzyki();
				plansza3.pociski_bohatera();
				plansza3.ruch_pociskow();
				plansza3.nadawanie_predkosci_przeciwnikom();
				plansza3.kolizja_bohater_przeszkody();
				plansza3.kolizja_pociskow();
				plansza3.kolizja_bohater_przeciwnicy();
				plansza3.kolizja_przeciwnicy_przeszkody();
				plansza3.koniec_bohatera();

				//rysowanie
				plansza3.rysowanie_podlogi(window);
				for (auto el : plansza3.get_splasze()) {
					window.draw(el);
				}
				for (auto el : plansza3.get_przeciwnicy()) {
					window.draw(el->get_sprajt());
				}
				for (auto el : plansza3.get_pszeszkody()) {
					if (el->get_id() == 1)
						window.draw(el->get_sprajt());
					else if (el->get_id() == 2)
						plansza3.rysowanie_ognia(window);
				}
				for (auto el : plansza3.get_pociski()) {
					window.draw(el);
				}
				plansza3.rysowanie_ognia(window);
				plansza3.rysowanie_zycia(window);
				plansza3.rysowanie_wybuchu(window);
				plansza3.rysowanie_zdrowia_przeciwnikow(window);
				plansza3.rysowanie_bohatera(window);
			}

			//zmiana levelu
			if (plansza1.ilosc_przecinikow() == 0 && level == 1 && frame_level == 0)
				frame_level = 1;
			if (plansza2.ilosc_przecinikow() == 0 && level == 2 && frame_level == 0)
				frame_level = 1;
			if (plansza3.ilosc_przecinikow() == 0 && level == 3 && frame_level == 0)
				frame_level = 1;

			if (plansza1.ilosc_przecinikow() == 0 && level ==1 && frame_level == 120 ) {
				level = 2;
				plansza1.koniec_muzyki();
				frame_level = 0;
				plansza2.set_bohater_life(plansza1.get_bohater_life());
			}
			if (plansza2.ilosc_przecinikow() == 0 && level == 2 && frame_level == 120) {
				level = 3;
				plansza2.koniec_muzyki();
				frame_level = 0;
				plansza3.set_bohater_life(plansza2.get_bohater_life());
			}
			if (plansza3.ilosc_przecinikow() == 0 && level == 3 && frame_level==120) {
				frame_level = 0;
				plansza3.koniec_muzyki();
				koniec_gry = 1;
				break;
			}
			//sprawdzanie przegranej
			if (plansza1.przegrana()) {
				koniec_gry = 2;
				break;
			}
			if (plansza2.przegrana()) {
				koniec_gry = 2;
				break;
			}
			if (plansza3.przegrana()) {
				koniec_gry = 2;
				break;
			}

			window.display();
		}
	}
		//Wyœwietlanie wyniku gry
		for (int i = 0; i < 120;i++) {
			if (koniec_gry == 1) {
				window.clear();
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("Wygrales!", font, 100);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(5);
				tekst.setPosition(700, 400);
				window.draw(tekst);
				window.display();
			}
			if (koniec_gry == 2) {
				window.clear();
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("Przegrales!", font, 100);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(5);
				tekst.setPosition(700, 400);
				window.draw(tekst);
				window.display();
			}
		}
		koniec_gry = 0;
	}
	return 0;
}