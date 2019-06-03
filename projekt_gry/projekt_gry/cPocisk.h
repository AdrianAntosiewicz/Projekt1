#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "cPrzeciwnik.h"
#include "cPrzeszkoda.h"
#include "cBohater.h"

using namespace std;
using namespace sf;

class cPocisk : public RectangleShape {
	double x_, y_, a_, b_;
	double Vx, Vy;
public:
	cPocisk(double x, double y, float a, float b,double Vx,double Vy);
	bool kolizja_przeszkoda(cPrzeszkoda &R);
	bool kolizja_przeciwnik(cPrzeciwnik &R);
	bool kolizja_bohater(cBohater &R);
	void ruch() { RectangleShape::move(Vx, Vy); };
};
