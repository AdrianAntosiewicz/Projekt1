#pragma once
#include<SFML/Graphics.hpp>
#include"cPrzeszkoda.h"

using namespace std;
using namespace sf;
class cPrzeciwnik:public RectangleShape{
protected:
	double x_, y_, a_, b_;
	double Basic_velocity, Vx{ 0 }, Vy{ 0 };
	int zycie,basic_life;
	sf::Texture tekstura;
	sf::Sprite sprajt;
public:
	cPrzeciwnik(double x, double y, float a, float b,int life, double v);
	virtual void uptade(int x)=0;
	void odbij_vx() { Vx = -Vx; };
	void odbij_vy() { Vx = -Vy; };
	double get_vx() { return Vx; };
	double get_vy() { return Vy; };
	double get_basic_v() { return Basic_velocity; };
	void set_basic_v(int x) { Basic_velocity += x; };
	int get_life() { return zycie; };
	int get_basic_life() { return basic_life; };
	void set_basic_life(int x) { basic_life += x; };
	void set_life(int x) { zycie += x; };
	void zranienie() { zycie -= 1; };
	Sprite get_sprajt() { return sprajt; };
	void ruch();
	bool kolizja_przeszkoda(cPrzeszkoda &R);
	void sprajt_rotate(int x) { sprajt.setRotation(x); };

	float left() { return RectangleShape::getPosition().x - a_ / 2; };//Te metody zwracaj¹ wspó³rzêdne krawêdzi
	float right() { return RectangleShape::getPosition().x + a_ / 2; };
	float top() { return RectangleShape::getPosition().y - b_ / 2; };
	float bottom() { return RectangleShape::getPosition().y + b_ / 2; };
};
