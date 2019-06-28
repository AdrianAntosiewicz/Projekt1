#include "cMenu.h"

Menu::Menu() {
	if (!font.loadFromFile("arial.ttf"))
		cout << "Nie laduje" << endl;
	tekst[0].setFont(font);
	tekst[0].setCharacterSize(50);
	tekst[0].setFillColor(Color::Red);
	tekst[0].setString("Graj!");
	tekst[0].setOutlineColor(Color::Cyan);
	tekst[0].setOutlineThickness(3);
	tekst[0].setPosition(x / 2-20, y / 4 * 1);
	

	tekst[1].setFont(font);
	tekst[1].setCharacterSize(50);
	tekst[1].setFillColor(Color::White);
	tekst[1].setString("Poziom trudnosci");
	tekst[1].setOutlineColor(Color::Cyan);
	tekst[1].setOutlineThickness(3);
	tekst[1].setPosition((x / 2)-140, y / 4 * 2);

	tekst[2].setFont(font);
	tekst[2].setCharacterSize(50);
	tekst[2].setFillColor(Color::White);
	tekst[2].setString("Wyjscie");
	tekst[2].setOutlineColor(Color::Cyan);
	tekst[2].setOutlineThickness(3);
	tekst[2].setPosition(x / 2-40, y / 4 * 3);

	tekst2[0].setFont(font);
	tekst2[0].setCharacterSize(50);
	tekst2[0].setFillColor(Color::Red);
	tekst2[0].setString("Latwy");
	tekst2[0].setOutlineColor(Color::Cyan);
	tekst2[0].setOutlineThickness(3);
	tekst2[0].setPosition(x / 2-20, y / 4 * 1);


	tekst2[1].setFont(font);
	tekst2[1].setCharacterSize(50);
	tekst2[1].setFillColor(Color::White);
	tekst2[1].setString("Sredni");
	tekst2[1].setOutlineColor(Color::Cyan);
	tekst2[1].setOutlineThickness(3);
	tekst2[1].setPosition(x / 2-25, y / 4 * 2);

	tekst2[2].setFont(font);
	tekst2[2].setCharacterSize(50);
	tekst2[2].setFillColor(Color::White);
	tekst2[2].setString("Trudny");
	tekst2[2].setOutlineColor(Color::Cyan);
	tekst2[2].setOutlineThickness(3);
	tekst2[2].setPosition(x / 2-30, y / 4 * 3);

	wybor = 0;
	wybor2 = 0;
}

void Menu::move_up() {
	if (wybor - 1 >= 0) {
		tekst[wybor].setFillColor(Color::White);
		wybor--;
		tekst[wybor].setFillColor(Color::Red);
	}
}

void Menu::move_down() {
	if (wybor + 1 < 3) {
		tekst[wybor].setFillColor(Color::White);
		wybor++;
		tekst[wybor].setFillColor(Color::Red);
	}
}

void Menu::move_up2() {
	if (wybor2 - 1 >= 0) {
		tekst2[wybor2].setFillColor(Color::White);
		wybor2--;
		tekst2[wybor2].setFillColor(Color::Red);
	}
}

void Menu::move_down2() {
	if (wybor2 + 1 < 3) {
		tekst2[wybor2].setFillColor(Color::White);
		wybor2++;
		tekst2[wybor2].setFillColor(Color::Red);
	}
}

void Menu::draw(RenderWindow &window) {
	for (int i = 0; i < 3; i++) {
		window.draw(tekst[i]);
	}
}


void Menu::draw2(RenderWindow &window) {
	for (int i = 0; i < 3; i++) {
		window.draw(tekst2[i]);
	}
}

string funkcja_menu(RenderWindow &window) {
	Texture t_menu;
	t_menu.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\menu.jpg");
	Sprite s_menu;
	s_menu.setTexture(t_menu);

	Menu menu;
	int opcje = 1;
	string poziom_gry = "2_";
	while (true) {
		Event event;
		window.clear();
		window.draw(s_menu);
		while (window.pollEvent(event)) {
			if (opcje == 1) {
				switch (event.type) {

				case Event::KeyReleased:

					switch (event.key.code) {
					case Keyboard::Up:
						menu.move_up();
						break;
					case Keyboard::Down:
						menu.move_down();
						break;
					case Keyboard::Enter:
						if (menu.get_wybor() == 0)
							return poziom_gry;
						else if (menu.get_wybor() == 1) {
							poziom_gry = "opcje";
							return poziom_gry;
						}
						else if (menu.get_wybor() == 2) {
							window.close();
							exit(0);
						}
						break;
					}

					break;

				case Event::Closed:
					window.close();
					break;
				}
			}
		}

		menu.draw(window);

		window.display();
	}
}

string funkcja_opcje(RenderWindow &window) {
	Texture t_menu;
	t_menu.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\menu.jpg");
	Sprite s_menu;
	s_menu.setTexture(t_menu);

	Menu menu;
	string poziom_gry = "0";
	while (true) {
		Event event;
		window.clear();
		window.draw(s_menu);
		while (window.pollEvent(event)) {
				switch (event.type) {

				case Event::KeyReleased:

					switch (event.key.code) {
					case Keyboard::Up:
						menu.move_up2();
						break;
					case Keyboard::Down:
						menu.move_down2();
						break;
					case Keyboard::Enter:
						if (menu.get_wybor2() == 0) {
							poziom_gry = "latwy";
							return poziom_gry;
						}
						else if (menu.get_wybor2() == 1) {
							poziom_gry = "sredni";
							return poziom_gry;
						}
						else if (menu.get_wybor2() == 2) {
							poziom_gry = "trudny";
							return poziom_gry;
						}
						break;
					}

					break;

				case Event::Closed:
					window.close();
					break;
				}
		}

		menu.draw2(window);

		window.display();
	}
}

