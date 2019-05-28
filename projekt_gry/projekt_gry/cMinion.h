#pragma once
#include "cPrzeciwnik.h"

class cMinion :protected cPrzeciwnik {

public:
	cMinion(double x, double y, float a, float b, int life, double v);
	void uptade(int x);
};
