#include "cBohater.h"


cBohater::cBohater(double x, double y, float a, float b) : x_(x), y_(y), a_(a), b_(b){
	RectangleShape::setPosition(x, y);
	RectangleShape::setSize({ a,b });//musz¹ byæ nawiasy klamrowe bo argumentem jest wektor, mozna to zapisac inaczej: shape.setSize(vector2f(a,b));
	RectangleShape::setFillColor(Color::Red);
	RectangleShape::setOrigin(a / 2, b / 2);
	tekstura.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\bohater.png");
	sprajt.setTexture(tekstura);
	sprajt.setPosition(x, y);
	sprajt.setOrigin(a / 2, b / 2);
}
void cBohater::uptade() {
	RectangleShape::move(Vx, Vy);
	sprajt.setPosition(this->getPosition().x,this->getPosition().y);
	if (Keyboard::isKeyPressed(Keyboard::Key::A) && strona_kolizji!='a') {
		last_click = 'a';
		strona_kolizji2 = '0';
		Vx = -Basic_velocity;
		Vy = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D) && strona_kolizji != 'd') {
		last_click = 'd';
		strona_kolizji2 = '0';
		Vx = Basic_velocity;
		Vy = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::W) && strona_kolizji != 'w') {
		last_click = 'w';
		strona_kolizji2 = '0';
		Vy = -Basic_velocity;
		Vx = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) && strona_kolizji != 's') {
		last_click = 's';
		strona_kolizji2 = '0';
		Vy = Basic_velocity;
		Vx = 0;
	}
	else {
		Vx = 0;
		Vy = 0;
	}
}
bool cBohater::kolizja_przeciwnik(cPrzeciwnik &R) {
	if (R.left() - this->right() <= 0 && R.left() - this->left() > 0 && this->top() - R.bottom() < 0 && R.top() - this->bottom() < 0 ) {
		this->setPosition(this->getPosition().x - 20, this->getPosition().y);//Kolizja prawo
		return true;
	}
	else if (this->left() - R.right() <= 0 && this->right() - R.right() > 0 && this->top() - R.bottom() < 0 && R.top() - this->bottom() < 0 ) {
		this->setPosition(this->getPosition().x + 20, this->getPosition().y);//kolizja lewo
		return true;
	}
	else if (this->top() - R.bottom() <= 0 && this->bottom() - R.bottom() > 0 && R.left() - this->right() < 0 && this->left() - R.right() < 0) {
		this->setPosition(this->getPosition().x, this->getPosition().y+20);//kolizja gora
		return true;
	}
	else if (R.top() - this->bottom() <= 0 && R.top() - this->top() > 0 && R.left() - this->right() < 0 && this->left() - R.right() < 0) {
		this->setPosition(this->getPosition().x, this->getPosition().y - 20);//kolizja dol
		return true;
	}
	else {
		return false;
	}
}
bool cBohater::kolizja_przeszkoda( cPrzeszkoda &R) {
	{
		//else if (R.left() - this->right() <= 0 && R.left() - this->left() > 0 && this->top() - R.bottom() < 0 && R.top() - this->bottom() < 0) {
		//	strona_kolizji = 'd';//Kolizja prawo
		//	return true;
		//}
		//else if (this->left() - R.right() <= 0 && this->right() - R.right() > 0 && this->top() - R.bottom() < 0 && R.top() - this->bottom() < 0) {
		//	strona_kolizji = 'a';//kolizja lewo
		//	return true;
		//}
		//else if (this->top() - R.bottom() <= 0 && this->bottom() - R.bottom() > 0 && R.left() - this->right() < 0 && this->left() - R.right() < 0) {
		//	strona_kolizji='w';//kolizja gora
		//	return true;
		//}
		//else if (R.top() - this->bottom() <= 0 && R.top() - this->top() > 0 && R.left() - this->right() < 0 && this->left() - R.right() < 0) {
		//	strona_kolizji='s';//kolizja dol
		//	return true;
		//}
	}
	if (this->getGlobalBounds().intersects(R.getGlobalBounds()))
		return true;
	else
		return false;
}
