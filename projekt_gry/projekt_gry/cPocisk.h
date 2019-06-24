#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "cPrzeciwnik.h"
#include "cPrzeszkoda.h"
#include "cBohater.h"

using namespace std;
using namespace sf;

class cPocisk : public CircleShape {
	double x_, y_, a_;
	double Vx, Vy;
	int id;
	sf::Texture tekstura;
	sf::Sprite sprajt;
public:
	cPocisk(double x, double y, float a,double Vx,double Vy, int id);
	bool kolizja_przeszkoda(cPrzeszkoda &R);
	bool kolizja_przeciwnik(cPrzeciwnik &R);
	bool kolizja_bohater(cBohater &R);
	void ruch() { CircleShape::move(Vx, Vy); sprajt.setPosition(this->getPosition().x, this->getPosition().y);};
	void set_id(int x) { id = x; };
	int get_id() { return id; };
	Sprite get_sprajt() { return sprajt; };
};
