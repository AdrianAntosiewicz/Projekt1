#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"cPrzeciwnik.h"

using namespace std;
using namespace sf;
class cMinion : public cPrzeciwnik {
public:
	cMinion(double x, double y, float a, float b,int life, double v);
	void uptade(int x);
};
