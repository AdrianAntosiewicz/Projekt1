#include "cMur.h"

cMur::cMur(double x, double y, double a, double b) : cPrzeszkoda(x, y, a, b) {
	if(b>=a)
		tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\mur_pion.png");
	else if(a>b)
		tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\mur_poziom.png");
	sprajt.setTexture(tekstura);
	sprajt.setPosition(x, y);
	sprajt.setOrigin(a/2,b/2);
	sprajt.setTextureRect(IntRect(0,0,a,b));
}