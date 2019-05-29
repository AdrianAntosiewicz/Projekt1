#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class cPrzeszkoda {
	RectangleShape shape;
	double x_, y_, a_, b_;
public:
	cPrzeszkoda(double x, double y, double a, double b);

};
