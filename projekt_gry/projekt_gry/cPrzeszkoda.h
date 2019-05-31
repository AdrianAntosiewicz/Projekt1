#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class cPrzeszkoda:public RectangleShape {
	double x_, y_, a_, b_;
public:
	cPrzeszkoda(double x, double y, float a, float b);
	float left() { return RectangleShape::getPosition().x - a_ / 2; };//Te metody zwracaj� wsp�rz�dne kraw�dzi
	float right() { return RectangleShape::getPosition().x + a_ / 2; };
	float top() { return RectangleShape::getPosition().y - b_ / 2; };
	float bottom() { return RectangleShape::getPosition().y + b_ / 2; };
};
