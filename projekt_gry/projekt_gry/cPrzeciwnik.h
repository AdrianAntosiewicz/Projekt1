#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class cPrzeciwnik{
protected:
	RectangleShape shape;
	double x_, y_, a_, b_;
	double Basic_velocity, Vx{ 0 }, Vy{ 0 };
	int zycie;
public:
	cPrzeciwnik(double x, double y, float a, float b,int life, double v);
	virtual void uptade(int x)=0;
	void ruch() { shape.move(Vx, Vy); };
	float left() { return shape.getPosition().x - a_ / 2; };//Te metody zwracaj¹ wspó³rzêdne krawêdzi
	float right() { return shape.getPosition().x + a_ / 2; };
	float top() { return shape.getPosition().y - b_ / 2; };
	float bottom() { return shape.getPosition().y + b_ / 2; };
	RectangleShape get_shape() { return shape; };
};
