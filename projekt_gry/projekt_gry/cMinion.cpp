#include "cMinion.h"

cMinion::cMinion(double x, double y, float a, float b, int life, double v) : cPrzeciwnik(x,y,a,b,life,v) {
}

void cMinion::uptade(int x) {
	if (x == 0) {
		Vy = -Basic_velocity;
		Vx = 0;
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
