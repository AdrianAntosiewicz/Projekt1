#include "cPrzeciwnik.h"

cPrzeciwnik::cPrzeciwnik(double x, double y, float a, float b, int life, double v) : x_(x), y_(y), a_(a), b_(b),zycie(life),Basic_velocity(v) {
	shape.setPosition(x, y);
	shape.setSize({ a,b });//musz¹ byæ nawiasy klamrowe bo argumentem jest wektor, mozna to zapisac inaczej: shape.setSize(vector2f(a,b));
	shape.setFillColor(Color::Green);
	shape.setOrigin(a / 2, b / 2);
}

void cPrzeciwnik::draw(RenderTarget& target, RenderStates state) const {
	target.draw(shape, state);
}
