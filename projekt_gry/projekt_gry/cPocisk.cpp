#include "cPocisk.h"

cPocisk::cPocisk(double x, double y, float a, float b, double Vx, double Vy) :x_(x), y_(y), Vx(Vx), Vy(Vy) {
	RectangleShape::setPosition(x, y);
	RectangleShape::setSize({ a,b });
	RectangleShape::setFillColor(Color::Blue);
	RectangleShape::setOrigin(a / 2, b / 2);
};

bool cPocisk::kolizja_przeszkoda(cPrzeszkoda &R) {
	if (this->getGlobalBounds().intersects(R.getGlobalBounds()))
		return true;
	else
		return false;
}
bool cPocisk::kolizja_przeciwnik(cPrzeciwnik &R) {
	if (this->getGlobalBounds().intersects(R.getGlobalBounds()))
		return true;
	else
		return false;
}
bool cPocisk::kolizja_bohater(cBohater &R) {
	if (this->getGlobalBounds().intersects(R.getGlobalBounds()))
		return true;
	else
		return false;
}