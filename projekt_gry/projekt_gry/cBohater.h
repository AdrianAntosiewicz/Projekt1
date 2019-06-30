#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "cPrzeciwnik.h"
#include "cPrzeszkoda.h"
using namespace std;
using namespace sf;

class cBohater: public RectangleShape {
	double x_, y_, a_, b_;
	double Basic_velocity{ 6 }, Vx{ 0 }, Vy{ 0 };
	int zycie{ 4 };
	char last_click = '0', strona_kolizji = '0', strona_kolizji2 = '0';
	sf::Texture tekstura;
	sf::Sprite sprajt;
public:
	cBohater(double x, double y, float a, float b);
	void uptade();
	float left() { return RectangleShape::getPosition().x - a_ / 2; };//Te metody zwracaj¹ wspó³rzêdne krawêdzi
	float right() { return RectangleShape::getPosition().x + a_ / 2; };
	float top() { return RectangleShape::getPosition().y - b_ / 2; };
	float bottom() { return RectangleShape::getPosition().y + b_ / 2; };
	void set_vx(int x) { Vx = x; };
	void set_vy(int x) { Vy = x; };
	double get_vx() { return Vx; };
	double get_vy() { return Vy; };
	bool kolizja_przeciwnik(cPrzeciwnik &R);
	bool kolizja_przeszkoda( cPrzeszkoda &R);
	void zranienie() { zycie -= 1; };
	int get_life() { return zycie; };
	char get_last_click() { return last_click; };
	char get_strona_kolizji() { return strona_kolizji; };
	Sprite get_sprajt() { return sprajt; };
	int get_angle() { return sprajt.getRotation(); };
	void sprajt_rotate(int x) { sprajt.setRotation(x); };
	void set_strona_kolizji(char x) { strona_kolizji = x; };
	void set_strona_kolizji2(char x) { strona_kolizji = x; };
	double get_a() { return a_; };
	double get_b() { return b_; };
};
