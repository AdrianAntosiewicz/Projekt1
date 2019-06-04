#include "cPrzeciwnik.h"

cPrzeciwnik::cPrzeciwnik(double x, double y, float a, float b, int life, double v) : x_(x), y_(y), a_(a), b_(b),zycie(life),Basic_velocity(v) {
	RectangleShape::setPosition(x, y);
	RectangleShape::setSize({ a,b });//musz¹ byæ nawiasy klamrowe bo argumentem jest wektor, mozna to zapisac inaczej: shape.setSize(vector2f(a,b));
	RectangleShape::setFillColor(Color::Green);
	RectangleShape::setOrigin(a / 2, b / 2);
}

bool cPrzeciwnik::kolizja_przeszkoda(cPrzeszkoda &R) {
	if (this->getGlobalBounds().intersects(R.getGlobalBounds()))
		return true;
	else
		return false;
}
