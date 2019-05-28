#include<iostream>
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <vector>
#include"cBohater.h"
using namespace sf;
using namespace std;


int main() {
	cBohater Bohater(400, 300, 100, 100);
	RenderWindow window{ VideoMode(1920,1080),"Gra" };
	window.setFramerateLimit(60);
	Event event;
	while (true) {
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}
		Bohater.uptade();
		window.draw(Bohater);
		window.display();
	}


	return 0;
}