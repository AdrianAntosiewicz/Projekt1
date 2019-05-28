#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class cBohater : public Drawable {
	RectangleShape shape;
	double x_, y_, a_, b_;
	double Basic_velocity{ 6 }, Vx{ 0 }, Vy{ 0 };
	int zycie{ 4 };
	void draw(RenderTarget& target, RenderStates state) const override;//Metoda odpowiedzialna za rysowanie
public:
	cBohater(double x, double y, float a, float b);
	void uptade();
	float left() { return shape.getPosition().x - a_ / 2; };//Te metody zwracaj� wsp�rz�dne kraw�dzi
	float right() { return shape.getPosition().x + a_ / 2; };
	float top() { return shape.getPosition().y - b_ / 2; };
	float bottom() { return shape.getPosition().y + b_ / 2; };
	RectangleShape get_shape() { return shape; };
};