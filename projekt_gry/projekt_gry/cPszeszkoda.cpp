#include"cPrzeszkoda.h"

cPrzeszkoda::cPrzeszkoda(double x, double y, float a, float b, int id) :x_(x), y_(y), a_(a), b_(b), id(id) {
	RectangleShape::setPosition(x, y);
	RectangleShape::setSize({ a,b });
	RectangleShape::setFillColor(Color::Green);
	RectangleShape::setOrigin(a / 2, b / 2);
	if (b >= a && id==1)
		tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\mur_pion.png");
	else if (a > b && id==1)
		tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\mur_poziom.png");
	else if (id == 2) {
		tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\mur_poziom.png");
	}
	sprajt.setTexture(tekstura);
	sprajt.setPosition(x, y);
	sprajt.setOrigin(a / 2, b / 2);
	sprajt.setTextureRect(IntRect(0, 0, a, b));
};
