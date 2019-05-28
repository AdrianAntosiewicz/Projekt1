#include "cMinion.h"

cMinion::cMinion(double x, double y, float a, float b, int life, double v) : x_(x), y_(y), a_(a), b_(b),zycie(life),Basic_velocity(v) {
	shape.setPosition(x, y);
	shape.setSize({ a,b });//musz¹ byæ nawiasy klamrowe bo argumentem jest wektor, mozna to zapisac inaczej: shape.setSize(vector2f(a,b));
	shape.setFillColor(Color::Green);
	shape.setOrigin(a / 2, b / 2);
}

void cMinion::uptade(int x) {
	if (x == 0) {
		Vy = -Basic_velocity;
		Vx = 0;
		cout << Basic_velocity << endl;
	}
	else if (x == 1) {
		Vy = Basic_velocity;
		Vx = 0;
	}
	else if (x == 2) {
		Vx = -Basic_velocity;
		Vy = 0;
	}
	else if (x == 3) {
		Vx = Basic_velocity;
		Vy = 0;
	}
}

void cMinion::draw(RenderTarget& target, RenderStates state) const {
	target.draw(shape, state);
}