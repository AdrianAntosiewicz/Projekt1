#include "cMinion.h"

cMinion::cMinion(double x, double y, float a, float b, int life, double v) : cPrzeciwnik(x,y,a,b,life,v) {
	if(v>3)
		tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\minion_fast.png");
	else if(v<3)
		tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\minion_normal.png");
	sprajt.setTexture(tekstura);
	sprajt.setPosition(x, y);
	sprajt.setOrigin(a / 2, b / 2);
}

void cMinion::uptade(int x) {
	if (x == 0) {
		Vy = -Basic_velocity;
		Vx = 0;
		this->sprajt_rotate(0);
	}
	else if (x == 1) {
		Vy = Basic_velocity;
		Vx = 0;
		this->sprajt_rotate(180);
	}
	else if (x == 2) {
		Vx = -Basic_velocity;
		Vy = 0;
		this->sprajt_rotate(270);
	}
	else if (x == 3) {
		Vx = Basic_velocity;
		Vy = 0;
		this->sprajt_rotate(90);
	}
}
