#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;
using namespace std;

string funkcja_menu(RenderWindow &window);
string funkcja_opcje(RenderWindow &window);

class Menu {
	int x = 1920, y = 1080, wybor,wybor2;
	Font font;
	Text tekst[3], tekst2[3];
public:
	Menu();
	void move_up();
	void move_down();
	void move_up2();
	void move_down2();
	int get_wybor() { return wybor; };
	int get_wybor2() { return wybor2; };
	void draw(RenderWindow &window);
	void draw2(RenderWindow &window);
};


