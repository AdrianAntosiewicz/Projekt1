#include "cPlansza_3.h"

cPlansza_3::cPlansza_3() {
	przeciwnicy.push_back(new cStrzelec(900, 900, 96, 96, 2, 3));
	przeciwnicy.push_back(new cStrzelec(1200, 900, 96, 96, 2, 3));
	przeciwnicy.push_back(new cStrzelec(1300, 900, 96, 96, 2, 3));
	przeciwnicy.push_back(new cStrzelec(1400, 900, 96, 96, 2, 3));
	przeciwnicy.push_back(new cStrzelec(1500, 900, 96, 96, 2, 3));
	przeciwnicy.push_back(new cStrzelec(1050, 150, 96, 96, 2, 2));
	przeciwnicy.push_back(new cStrzelec(1100, 150, 96, 96, 2, 2));
	przeciwnicy.push_back(new cStrzelec(1200, 150, 96, 96, 2, 2));
	przeciwnicy.push_back(new cStrzelec(1300, 150, 96, 96, 2, 2));
	przeciwnicy.push_back(new cStrzelec(1100, 550, 96, 96, 2, 2));
	przeciwnicy.push_back(new cMinion(200, 800, 96, 96, 3, 6));
	przeciwnicy.push_back(new cMinion(300, 800, 96, 96, 3, 6));
	przeciwnicy.push_back(new cMinion(400, 800, 96, 96, 3, 6));
	przeciwnicy.push_back(new cMinion(500, 800, 96, 96, 3, 6));
	przeciwnicy.push_back(new cMinion(600, 800, 96, 96, 3, 6));
	przeciwnicy.push_back(new cMinion(700, 800, 96, 96, 3, 6));
	//Pszeszkody

	pszeszkody.push_back(new cPrzeszkoda(960, 32, 1920, 64, 1));
	pszeszkody.push_back(new cPrzeszkoda(960, 1048, 1920, 64, 1));
	pszeszkody.push_back(new cPrzeszkoda(32, 540, 64, 1080, 1));
	pszeszkody.push_back(new cPrzeszkoda(1888, 540, 64, 1080, 1));
	pszeszkody.push_back(new cPrzeszkoda(950, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1000, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1050, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1100, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1150, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1300, 300, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1350, 300, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1400, 300, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(1450, 300, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(300, 96, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(300, 160, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(300, 224, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(300, 288, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(300, 352, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(300, 416, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(96, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(146, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(196, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(246, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(296, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(346, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(396, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(446, 700, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(496, 700, 50, 64, 2));
}

void cPlansza_3::odliczanie(RenderWindow &window) {
	if (stan_odliczania == 2) {
		SoundBuffer b_count, b_runda3;
		b_count.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\odliczanie.wav");
		b_runda3.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\runda3.wav");
		Sound count, runda3;
		count.setBuffer(b_count);
		runda3.setBuffer(b_runda3);
		for (int i = 0; i < 270; i++) {
			window.display();
			window.clear();
			if (i == 60)
				count.play();
			if (i >= 60 && i < 270) {
				window.draw(s_podloga);
				for (auto el : pszeszkody) {
					if (el->get_id() == 1)
						window.draw(el->get_sprajt());
					if (el->get_id() == 2) {
						s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
						window.draw(s_ogien3);
					}

				}
				for (auto el : pociski) {
					window.draw(el);
				}

				window.draw(Bohater.get_sprajt());

				for (auto el : przeciwnicy) {
					window.draw(el->get_sprajt());
				}
			}

			if (i < 60) {
				if (muza == 1) {
					runda3.play();
					muza = 2;
				}
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("Runda 3", font, 100);
				tekst.setOutlineColor(Color::Red);
				tekst.setOutlineThickness(5);
				tekst.setPosition(800, 400);
				window.draw(tekst);
				if (i == 59)
					muza = 1;
			}

			if (i >= 60 && i < 120) {
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("3", font, 100);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(5);
				tekst.setPosition(940, 400);
				window.draw(tekst);
			}
			if (i >= 120 && i < 180) {
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("2", font, 100);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(5);
				tekst.setPosition(940, 400);
				window.draw(tekst);
			}
			if (i >= 180 && i < 240) {
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("1", font, 100);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(5);
				tekst.setPosition(940, 400);
				window.draw(tekst);
			}
			if (i >= 240 && i < 270) {
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("Start!", font, 100);
				tekst.setOutlineColor(Color::Black);
				tekst.setOutlineThickness(5);
				tekst.setPosition(850, 400);
				window.draw(tekst);
			}
		}
		stan_odliczania = 1;
	}
}