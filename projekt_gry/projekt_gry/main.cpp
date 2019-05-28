#include<iostream>
#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <vector>
using namespace sf;
using namespace std;


int main() {
	RenderWindow window{ VideoMode(800,600),"Arkanoid" };
	window.setFramerateLimit(60);
	Event event;
	while (true) {
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}
		window.display();
	}


	return 0;
}