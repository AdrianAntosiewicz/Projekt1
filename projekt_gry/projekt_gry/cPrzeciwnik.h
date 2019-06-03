#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class cPrzeciwnik:public RectangleShape{
protected:
	double x_, y_, a_, b_;
	double Basic_velocity, Vx{ 0 }, Vy{ 0 };
	int zycie;
public:
	cPrzeciwnik(double x, double y, float a, float b,int life, double v);
	virtual void uptade(int x)=0;
	void zranienie() { zycie -= 1; };
	void ruch() { RectangleShape::move(Vx, Vy); };
	float left() { return RectangleShape::getPosition().x - a_ / 2; };//Te metody zwracaj¹ wspó³rzêdne krawêdzi
	float right() { return RectangleShape::getPosition().x + a_ / 2; };
	float top() { return RectangleShape::getPosition().y - b_ / 2; };
	float bottom() { return RectangleShape::getPosition().y + b_ / 2; };
};
