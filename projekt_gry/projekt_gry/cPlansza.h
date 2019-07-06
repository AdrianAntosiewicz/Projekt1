#pragma once
#include "cPrzeciwnik.h"
#include "cMinion.h"
#include "cStrzelec.h"
#include "cPocisk.h"
#include "cBohater.h"
#include "SFML/Audio.hpp"

class cPlansza {
protected:
	vector<cPrzeciwnik*> przeciwnicy;
	vector<cPrzeszkoda*> pszeszkody;
	vector<cPocisk> pociski;
	cBohater Bohater{ 150,150,140,140 };
	int wybuch_x{ -1 }, wybuch_y{ -1 }, score{1};
	int frame_fast{ 0 }, frame_normal{ 0 }, strzal{ 0 }, frame_wybuch{ 0 }, frame_level{ 0 }, frame_hit{ 0 }, frame_ochrona{ 0 }, frame_ogien{ 0 }, kol{ 0 }, kol_pocisk{0};
	int play_music{ 1 }, stan_odliczania{ 2 }, muza{1};
	Music muzyka;
	SoundBuffer b_hit, b_hurt, b_laser, b_wybuch;
	Sound hitt, hurt, laser, wybuch;
	Texture t_splasz,t_ogien1,t_ogien2,t_ogien3,t_serce, t_wyb1, t_wyb2, t_wyb3, t_wyb4, t_wyb5, t_wyb6,t_hit,t_podloga;
	Sprite s_ogien1, s_ogien2, s_ogien3,s_serce, s_wyb1, s_wyb2, s_wyb3, s_wyb4, s_wyb5, s_wyb6,s_hit,s_podloga;
	vector<Sprite> splasze;
public:
	cPlansza();
	vector<cPrzeciwnik*> get_przeciwnicy() { return przeciwnicy; };
	vector<cPrzeszkoda*> get_pszeszkody() { return pszeszkody; };
	vector<cPocisk> get_pociski() { return pociski; };
	void poziom_trudnosci(int x);
	void nadawanie_predkosci_przeciwnikom();
	void aktualizuj();
	void pociski_bohatera();
	void kolizja_pociskow();
	void kolizja_bohater_przeszkody();
	void kolizja_bohater_przeciwnicy();
	void kolizja_przeciwnicy_przeszkody();
	void ruch_pociskow();
	void rysowanie_ognia(RenderWindow &window);
	void rysowanie_zycia(RenderWindow &window);
	void rysowanie_wybuchu(RenderWindow &window);
	void rysowanie_zdrowia_przeciwnikow(RenderWindow &window);
	void rysowanie_bohatera(RenderWindow &window);
	void rysowanie_splaszy(RenderWindow &window);
	void rysowanie_podlogi(RenderWindow &window);
	void start_muzyki();
	void koniec_muzyki();
	void set_stan_odliczania(int x) { stan_odliczania = x; };
	void koniec_bohatera();
	int ilosc_przecinikow() { return przeciwnicy.size(); };
	virtual void odliczanie(RenderWindow &window) = 0;
	int get_bohater_life() { return Bohater.get_life(); };
	void set_bohater_life(int x) { Bohater.set_life(x); };
	bool przegrana();
	vector<Sprite> get_splasze() { return splasze; };
	cBohater get_bohater() { return Bohater; };
};
