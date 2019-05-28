#include "cBohater.h"

cBohater::cBohater(double x, double y, float a, float b) : x_(x), y_(y), a_(a), b_(b){
	shape.setPosition(x, y);
	shape.setSize({ a,b });//musz� by� nawiasy klamrowe bo argumentem jest wektor, mozna to zapisac inaczej: shape.setSize(vector2f(a,b));
	shape.setFillColor(Color::Red);
	shape.setOrigin(a / 2, b / 2);
}

void cBohater::draw(RenderTarget& target, RenderStates state) const {
	target.draw(shape, state);
}
void cBohater::uptade() {
	shape.move(Vx, Vy);
	if (Keyboard::isKeyPressed(Keyboard::Key::A) && this->left() > 0) {
		last_click = 'a';
		Vx = -Basic_velocity;
		Vy = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D) && this->right() < 1920) {
		last_click = 'd';
		Vx = Basic_velocity;
		Vy = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::W) && this->top() > 0) {
		last_click = 'w';
		Vy = -Basic_velocity;
		Vx = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) && this->bottom() < 1080) {
		last_click = 's';
		Vy = Basic_velocity;
		Vx = 0;
	}
	else {
		Vx = 0;
		Vy = 0;
	}
}
bool cBohater::kolizja(const RectangleShape &R) {
	if (R.getGlobalBounds().intersects(shape.getGlobalBounds()))
	{
		return true;
	}
	else
		return false;
}