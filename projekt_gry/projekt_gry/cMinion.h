#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class cMinion : public Drawable {
	RectangleShape shape;
	void draw(RenderTarget& target, RenderStates state) const override;
	double x_, y_, a_, b_;
	double Basic_velocity{ 0 }, Vx{ 0 }, Vy{ 0 };
	int zycie;
public:
	cMinion(double x, double y, float a, float b,int life, double v);
	void uptade(int x);
	void ruch() { shape.move(Vx, Vy); };
	float left() { return shape.getPosition().x - a_ / 2; };//Te metody zwracaj¹ wspó³rzêdne krawêdzi
	float right() { return shape.getPosition().x + a_ / 2; };
	float top() { return shape.getPosition().y - b_ / 2; };
	float bottom() { return shape.getPosition().y + b_ / 2; };
	RectangleShape get_shape() { return shape; };
};
