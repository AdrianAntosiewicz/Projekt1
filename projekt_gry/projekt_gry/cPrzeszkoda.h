#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class cPrzeszkoda:public RectangleShape {
protected:
	double x_, y_, a_, b_;
	int id;
	sf::Texture tekstura;
	sf::Sprite sprajt;
public:
	cPrzeszkoda(double x, double y, float a, float b,int id);
	float left() { return RectangleShape::getPosition().x - a_ / 2; };//Te metody zwracaj¹ wspó³rzêdne krawêdzi
	float right() { return RectangleShape::getPosition().x + a_ / 2; };
	float top() { return RectangleShape::getPosition().y - b_ / 2; };
	float bottom() { return RectangleShape::getPosition().y + b_ / 2; };
	Sprite get_sprajt() { return sprajt; };
	int get_id() { return id; };
};
