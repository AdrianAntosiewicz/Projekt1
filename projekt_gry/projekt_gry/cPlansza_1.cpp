#include"cPlansza_1.h"

cPlansza_1::cPlansza_1() {

	przeciwnicy.push_back(new cMinion(1000, 400, 96, 96, 2, 6));
	przeciwnicy.push_back(new cMinion(1800, 400, 96, 96, 2, 6));
	przeciwnicy.push_back(new cMinion(1800, 200, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(1800, 300, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(1800, 800, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(1800, 900, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(1000, 700, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(1000, 300, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(1000, 200, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(900, 200, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(700, 300, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(1000, 800, 96, 96, 3, 2));
	przeciwnicy.push_back(new cMinion(200, 950, 96, 96, 3, 2));

	pszeszkody.push_back(new cPrzeszkoda(960, 32, 1920, 64, 1));
	pszeszkody.push_back(new cPrzeszkoda(960, 1048, 1920, 64, 1));
	pszeszkody.push_back(new cPrzeszkoda(32, 540, 64, 1080, 1));
	pszeszkody.push_back(new cPrzeszkoda(1888, 540, 64, 1080, 1));
	pszeszkody.push_back(new cPrzeszkoda(348, 190, 64, 254, 1));
	pszeszkody.push_back(new cPrzeszkoda(285, 792, 445, 64, 1));
	pszeszkody.push_back(new cPrzeszkoda(1696, 540, 320, 64, 1));
	pszeszkody.push_back(new cPrzeszkoda(1504, 540, 64, 570, 1));
	pszeszkody.push_back(new cPrzeszkoda(900, 600, 50, 64, 2));
	pszeszkody.push_back(new cPrzeszkoda(900, 300, 50, 64, 2));
}

void cPlansza_1::odliczanie(RenderWindow &window){
	if (stan_odliczania == 2) {
		SoundBuffer b_count, b_runda1;
		b_count.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\odliczanie.wav");
		b_runda1.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\runda1.wav");
		Sound count, runda1;
		count.setBuffer(b_count);
		runda1.setBuffer(b_runda1);
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
					runda1.play();
					muza = 2;
				}
				Font font;
				font.loadFromFile("arial.ttf");
				Text tekst("Runda 1", font, 100);
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
		play_music = 1;
	}
}