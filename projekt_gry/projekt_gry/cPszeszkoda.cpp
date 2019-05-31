#include"cPrzeszkoda.h"

cPrzeszkoda::cPrzeszkoda(double x, double y, float a, float b) :x_(x), y_(y), a_(a), b_(b) {
	RectangleShape::setPosition(x, y);
	RectangleShape::setSize({ a,b });
	RectangleShape::setFillColor(Color::White);
	RectangleShape::setOrigin(a / 2, b / 2);
};