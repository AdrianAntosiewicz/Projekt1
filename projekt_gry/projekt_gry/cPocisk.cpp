#include "cPocisk.h"

cPocisk::cPocisk(double x, double y, float a, double Vx, double Vy,int id) :x_(x), y_(y), Vx(Vx), Vy(Vy),id(id) {
	CircleShape::setPosition(x, y);
	CircleShape::setRadius({ a});
	if (id == 1) {
		CircleShape::setOutlineColor(Color::Blue);
		CircleShape::setFillColor(Color::Cyan);
		CircleShape::setOutlineThickness(4);
	}
	else if (id == 2) {
		CircleShape::setOutlineColor(Color::Red);
		CircleShape::setFillColor(Color::Yellow);
		CircleShape::setOutlineThickness(3);
	}


	CircleShape::setOrigin(a, a);
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