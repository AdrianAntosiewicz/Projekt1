#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class cBohater {
	RectangleShape shape;
	double x_, y_, a_, b_;
	double Basic_velocity{ 6 }, Vx{ 0 }, Vy{ 0 };
	int zycie{ 4 };
	char last_click='k';
public:
	cBohater(double x, double y, float a, float b);
	void uptade();
	float left() { return shape.getPosition().x - a_ / 2; };//Te metody zwracaj¹ wspó³rzêdne krawêdzi
	float right() { return shape.getPosition().x + a_ / 2; };
	float top() { return shape.getPosition().y - b_ / 2; };
	float bottom() { return shape.getPosition().y + b_ / 2; };
	void set_vx(int x) { Vx = x; };
	void set_vy(int x) { Vy = x; };
	RectangleShape get_shape() { return shape; };
	bool kolizja(const RectangleShape& R);
	char get_last_click() { return last_click; };
};
