#include"cPlansza.h"

cPlansza::cPlansza() {
	//dzwieki
	b_hurt.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\hurt.wav");
	b_hit.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\hit.wav");
	b_laser.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\laser.wav");
	b_wybuch.loadFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\wybuch.wav");
	muzyka.openFromFile("C:\\Users\\DiDson\\Desktop\\dzwieki\\muzyka.wav");
	muzyka.setVolume(60);
	//tekstury ognia
	t_ogien1.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\ogien1.png");
	t_ogien2.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\ogien2.png");
	t_ogien3.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\ogien3.png");
	//pozostale tekstury
	t_serce.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\serce.png");
	t_hit.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\bohater_hit.png");
	t_splasz.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\splasz.png");
	t_podloga.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\podloga.png");
	//tekstury wybuchu
	t_wyb1.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch1.png");
	t_wyb2.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch2.png");
	t_wyb3.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch3.png");
	t_wyb4.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch4.png");
	t_wyb5.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch5.png");
	t_wyb6.loadFromFile("C:\\Users\\DiDson\\Desktop\\tekstury\\wybuch6.png");

	hurt.setBuffer(b_hurt);
	hitt.setBuffer(b_hit);
	laser.setBuffer(b_laser);
	wybuch.setBuffer(b_wybuch);

	s_ogien1.setTexture(t_ogien1);
	s_ogien2.setTexture(t_ogien2);
	s_ogien3.setTexture(t_ogien3);

	s_serce.setTexture(t_serce);
	s_hit.setTexture(t_hit);
	s_podloga.setTexture(t_podloga);

	s_wyb1.setTexture(t_wyb1);
	s_wyb2.setTexture(t_wyb2);
	s_wyb3.setTexture(t_wyb3);
	s_wyb4.setTexture(t_wyb4);
	s_wyb5.setTexture(t_wyb5);
	s_wyb6.setTexture(t_wyb6);
}

void cPlansza::nadawanie_predkosci_przeciwnikom() {

		if (frame_fast > 29) {
			for (int i = 0; i < przeciwnicy.size(); i++) {
				if (przeciwnicy[i]->get_basic_v() > 2) {
					int los = rand() % 4;
					przeciwnicy[i]->uptade(los);
				}
			}
			frame_fast = 0;
		}

		if (frame_normal > 59) {
			for (int i = 0; i < przeciwnicy.size(); i++) {
				int los = rand() % 4;
				przeciwnicy[i]->uptade(los);
				if (cStrzelec *s = dynamic_cast<cStrzelec*>(przeciwnicy[i])) {
					if (los == 0 && przeciwnicy[i]->get_basic_v() <= 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->top() - 3, 10, 0, -12, 2));
					}
					if (los == 1 && przeciwnicy[i]->get_basic_v() <= 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->bottom() + 3, 10, 0, 12, 2));
					}
					if (los == 2 && przeciwnicy[i]->get_basic_v() <= 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->left() - 2, przeciwnicy[i]->getPosition().y, 10, -12, 0, 2));
					}
					if (los == 3 && przeciwnicy[i]->get_basic_v() <= 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->right() + 2, przeciwnicy[i]->getPosition().y, 10, 12, 0, 2));
					}
					if (los == 0 && przeciwnicy[i]->get_basic_v() > 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x + 30, przeciwnicy[i]->top() - 3, 10, 0, -12, 2));
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x - 30, przeciwnicy[i]->top() - 3, 10, 0, -12, 2));
					}
					if (los == 1 && przeciwnicy[i]->get_basic_v() > 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x + 30, przeciwnicy[i]->bottom() + 3, 10, 0, 12, 2));
						pociski.push_back(cPocisk(przeciwnicy[i]->getPosition().x - 30, przeciwnicy[i]->bottom() + 3, 10, 0, 12, 2));
					}
					if (los == 2 && przeciwnicy[i]->get_basic_v() > 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->left() - 2, przeciwnicy[i]->getPosition().y + 30, 10, -12, 0, 2));
						pociski.push_back(cPocisk(przeciwnicy[i]->left() - 2, przeciwnicy[i]->getPosition().y - 30, 10, -12, 0, 2));
					}
					if (los == 3 && przeciwnicy[i]->get_basic_v() > 2) {
						pociski.push_back(cPocisk(przeciwnicy[i]->right() + 2, przeciwnicy[i]->getPosition().y + 30, 10, 12, 0, 2));
						pociski.push_back(cPocisk(przeciwnicy[i]->right() + 2, przeciwnicy[i]->getPosition().y - 30, 10, 12, 0, 2));
					}
				}
			}
			frame_normal = 0;
		}
}

void cPlansza::aktualizuj() {
	if (frame_wybuch > 0)
		frame_wybuch++;
	if (frame_level > 0) {
		frame_level++;
	}
	if (frame_hit > 0)
		frame_hit++;
	frame_ochrona++;
	frame_ogien++;
	frame_fast++;
	frame_normal++;
	kol++;
	kol_pocisk++;
	strzal++;
}

void cPlansza::pociski_bohatera() {
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && strzal > 10) {
		pociski.push_back(cPocisk(Bohater.getPosition().x + 43, Bohater.top() - 10, 10, 0, -12, 1));
		strzal = 0;
		Bohater.sprajt_rotate(0);
		//strzaly++;
		laser.play();
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && strzal > 10) {
		pociski.push_back(cPocisk(Bohater.getPosition().x - 43, Bohater.bottom() + 10, 10, 0, 12, 1));
		strzal = 0;
		Bohater.sprajt_rotate(180);
		//strzaly++;
		laser.play();
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && strzal > 10) {
		pociski.push_back(cPocisk(Bohater.left() - 8, Bohater.getPosition().y - 43, 10, -12, 0, 1));
		strzal = 0;
		Bohater.sprajt_rotate(270);
		//strzaly++;
		laser.play();
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right) && strzal > 10) {
		pociski.push_back(cPocisk(Bohater.right() + 8, Bohater.getPosition().y + 43, 10, 12, 0, 1));
		strzal = 0;
		Bohater.sprajt_rotate(90);
		//strzaly++;
		laser.play();
	}
}

void cPlansza::kolizja_pociskow() {
		vector<cPocisk>::iterator itr;
		for (itr = pociski.begin(); itr != pociski.end(); itr++) {
			for (int j = 0; j < pszeszkody.size(); j++) {
				if (itr->kolizja_przeszkoda(*pszeszkody[j]) && pszeszkody[j]->get_id() == 1) {
					kol_pocisk = 1;
					break;
				}
			}
			for (int j = 0; j < przeciwnicy.size(); j++) {
				if (itr->kolizja_przeciwnik(*przeciwnicy[j])) {
					kol_pocisk = 1;
					if (itr->get_id() == 1) {
						przeciwnicy[j]->zranienie();
						hitt.play();
					}
					if (przeciwnicy[j]->get_life() == 0)
					{
						auto itr = przeciwnicy.begin();
						wybuch_x = przeciwnicy[j]->getPosition().x;
						wybuch_y = przeciwnicy[j]->getPosition().y;
						Sprite s1;
						s1.setTexture(t_splasz);
						s1.setPosition(wybuch_x, wybuch_y);
						s1.setOrigin(48, 48);
						splasze.push_back(s1);
						frame_wybuch = 1;
						przeciwnicy.erase(itr + j);
						score += 1000;
					}
					break;
				}
			}
			if (itr->kolizja_bohater(Bohater)) {
				kol_pocisk = 1;
				frame_hit = 1;
				if (frame_ochrona > 15) {
					hurt.play();
					Bohater.zranienie();
					frame_ochrona = 0;
				}
			}
			if (kol_pocisk == 1) {
				pociski.erase(itr);
				kol_pocisk = 2;
				break;
			}
		}
}

void cPlansza::kolizja_bohater_przeszkody() {
		for (int i = 0; i < pszeszkody.size(); i++) {
			if (Bohater.kolizja_przeszkoda(*pszeszkody[i]) && pszeszkody[i]->get_id() == 1) {
				if (Bohater.get_last_click() == 'd')
					Bohater.setPosition(Bohater.getPosition().x - 6, Bohater.getPosition().y);
				if (Bohater.get_last_click() == 'a')
					Bohater.setPosition(Bohater.getPosition().x + 6, Bohater.getPosition().y);
				if (Bohater.get_last_click() == 's')
					Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 6);
				if (Bohater.get_last_click() == 'w')
					Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 6);
			}
			if (Bohater.kolizja_przeszkoda(*pszeszkody[i]) && pszeszkody[i]->get_id() == 2) {
				frame_hit = 1;
				if (frame_ochrona > 15) {
					hurt.play();
					Bohater.zranienie();
					frame_ochrona = 0;
				}
				if (Bohater.get_last_click() == 'd')
					Bohater.setPosition(Bohater.getPosition().x - 40, Bohater.getPosition().y);
				if (Bohater.get_last_click() == 'a')
					Bohater.setPosition(Bohater.getPosition().x + 40, Bohater.getPosition().y);
				if (Bohater.get_last_click() == 's')
					Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y - 40);
				if (Bohater.get_last_click() == 'w')
					Bohater.setPosition(Bohater.getPosition().x, Bohater.getPosition().y + 40);
			}
		}
		Bohater.set_strona_kolizji('0');
		Bohater.uptade();
}

void cPlansza::kolizja_bohater_przeciwnicy() {
		for (int i = 0; i < przeciwnicy.size(); i++) {
			przeciwnicy[i]->ruch();
			if (Bohater.kolizja_przeciwnik(*przeciwnicy[i])) {
				if (kol > 10) {
					kol = 0;
					frame_hit = 1;
					if (frame_ochrona > 15) {
						hurt.play();
						Bohater.zranienie();
						frame_ochrona = 0;
					}
					//--->Cos jeszcze mozna zrobic w kolizji, bo typ bool
				}
			}
		}
		if ((Bohater.getPosition().x < 30 || Bohater.getPosition().x>1890 || Bohater.getPosition().y < 30 || Bohater.getPosition().y>1050) && Bohater.get_life() != 0) {
			Bohater.setPosition(200, 200);
		}
}

void cPlansza::kolizja_przeciwnicy_przeszkody() {
		for (int i = 0; i < przeciwnicy.size(); i++) {
			for (int j = 0; j < pszeszkody.size(); j++) {
				if (przeciwnicy[i]->kolizja_przeszkoda(*pszeszkody[j])) {
					if (przeciwnicy[i]->get_vx() > 0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x - przeciwnicy[i]->get_vx(), przeciwnicy[i]->getPosition().y);
					if (przeciwnicy[i]->get_vx() < -0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x - przeciwnicy[i]->get_vx(), przeciwnicy[i]->getPosition().y);
					if (przeciwnicy[i]->get_vy() > 0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->getPosition().y - przeciwnicy[i]->get_vy());
					if (przeciwnicy[i]->get_vy() < -0.1)
						przeciwnicy[i]->setPosition(przeciwnicy[i]->getPosition().x, przeciwnicy[i]->getPosition().y - przeciwnicy[i]->get_vy());
				}
			}
		}
}

void cPlansza::ruch_pociskow() {
	for (auto i = pociski.begin(); i < pociski.end(); i++) {
		i->ruch();
	}
}

void cPlansza::rysowanie_ognia(RenderWindow &window) {
	for (auto el : pszeszkody) {
		if (el->get_id() == 2) {
			s_ogien1.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
			s_ogien2.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
			s_ogien3.setPosition(el->getPosition().x - 25, el->getPosition().y - 32);
			if (frame_ogien < 15) {
				window.draw(s_ogien1);
			}
			if (frame_ogien < 30 && frame_ogien >= 15) {
				window.draw(s_ogien2);
			}
			if (frame_ogien <= 45 && frame_ogien >= 30) {
				window.draw(s_ogien3);
			}
			if (frame_ogien == 45)
				frame_ogien = 0;

		}
	}
}

void cPlansza::rysowanie_zycia(RenderWindow &window) {
	if (Bohater.get_life() == 3) {
		s_serce.setPosition(0, 0);
		window.draw(s_serce);
		s_serce.setPosition(64, 0);
		window.draw(s_serce);
		s_serce.setPosition(128, 0);
		window.draw(s_serce);
	}

	if (Bohater.get_life() == 2) {
		s_serce.setPosition(0, 0);
		window.draw(s_serce);
		s_serce.setPosition(64, 0);
		window.draw(s_serce);
	}

	if (Bohater.get_life() == 1) {
		s_serce.setPosition(0, 0);
		window.draw(s_serce);
	}
}

void cPlansza::rysowanie_wybuchu(RenderWindow &window) {
	if (wybuch_x > 0) {
		if (frame_wybuch == 4)
			wybuch.play();
		if (frame_wybuch < 8) {
			s_wyb1.setOrigin(48, 48);
			s_wyb1.setPosition(wybuch_x, wybuch_y);
			window.draw(s_wyb1);
		}
		if (frame_wybuch >= 8 && frame_wybuch < 16) {
			s_wyb2.setOrigin(48, 48);
			s_wyb2.setPosition(wybuch_x, wybuch_y);
			window.draw(s_wyb2);
		}
		if (frame_wybuch >= 16 && frame_wybuch < 24) {
			s_wyb3.setOrigin(48, 48);
			s_wyb3.setPosition(wybuch_x, wybuch_y);
			window.draw(s_wyb3);
		}
		if (frame_wybuch >= 24 && frame_wybuch < 32) {
			s_wyb4.setOrigin(48, 48);
			s_wyb4.setPosition(wybuch_x, wybuch_y);
			window.draw(s_wyb4);
		}
		if (frame_wybuch >= 32 && frame_wybuch < 40) {
			s_wyb5.setOrigin(48, 48);
			s_wyb5.setPosition(wybuch_x, wybuch_y);
			window.draw(s_wyb5);
		}
		if (frame_wybuch >= 40 && frame_wybuch < 48) {
			s_wyb6.setOrigin(48, 48);
			s_wyb6.setPosition(wybuch_x, wybuch_y);
			window.draw(s_wyb6);
		}
		if (frame_wybuch == 49)
		{
			frame_wybuch = 0;
			wybuch_x = -1;
		}
	}
}

void cPlansza::rysowanie_zdrowia_przeciwnikow(RenderWindow &window) {
Font font;
font.loadFromFile("arial.ttf");
Text tekst;
tekst.setFont(font);
tekst.setOutlineColor(Color::Black);
tekst.setOutlineThickness(2);
for (int i = 0; i < przeciwnicy.size(); i++)
	{
	tekst.setPosition(przeciwnicy[i]->getPosition().x-20, przeciwnicy[i]->getPosition().y-85);
	char s1[10],s2[10];
	_itoa_s(przeciwnicy[i]->get_life(), s1, 10);
	_itoa_s(przeciwnicy[i]->get_basic_life(), s2, 10);
	string str1=s1,str2=s2,str;
	str = str1 + "/" + str2;
	tekst.setString(str);
	tekst.setFillColor(Color::Green);
	if ((float)przeciwnicy[i]->get_life() / (float)przeciwnicy[i]->get_basic_life() < 0.67 && (float)przeciwnicy[i]->get_life() / (float)przeciwnicy[i]->get_basic_life() > 0.34)
		tekst.setFillColor(Color::Yellow);
	if ((float)przeciwnicy[i]->get_life() / (float)przeciwnicy[i]->get_basic_life() < 0.34)
		tekst.setFillColor(Color::Red);
	window.draw(tekst);
	}
}

void cPlansza::rysowanie_bohatera(RenderWindow &window) {
	if (frame_hit == 0)
		window.draw(Bohater.get_sprajt());
	if (frame_hit > 0 && frame_hit <= 15) {
		s_hit.setPosition(Bohater.getPosition().x, Bohater.getPosition().y);
		s_hit.setOrigin(Bohater.get_a() / 2, Bohater.get_b() / 2);
		s_hit.setRotation(Bohater.get_angle());
		window.draw(s_hit);
		if (frame_hit == 15)
			frame_hit = 0;
	}
}

void cPlansza::rysowanie_splaszy(RenderWindow &window) {
	Sprite s;
	s.setTexture(t_splasz);
	s.setPosition(500, 500);
	splasze.push_back(s);
	for (auto el : splasze) {
		window.draw(el);
	}
}

void cPlansza::rysowanie_podlogi(RenderWindow &window) {
	window.draw(s_podloga);
}

void cPlansza::poziom_trudnosci(int x) {
	if (x == 2) {
		for (int i = 0; i < przeciwnicy.size(); i++) {
			przeciwnicy[i]->set_life(przeciwnicy[i]->get_life()*0.5);
			przeciwnicy[i]->set_basic_life(przeciwnicy[i]->get_basic_life()*0.5);
			przeciwnicy[i]->set_basic_v(przeciwnicy[i]->get_basic_v()*0.5);
		}
	}
	if (x == 3) {
		for (int i = 0; i < przeciwnicy.size(); i++) {
			przeciwnicy[i]->set_life(przeciwnicy[i]->get_life()*1.5);
			przeciwnicy[i]->set_basic_life(przeciwnicy[i]->get_basic_life()*1.5);
			przeciwnicy[i]->set_basic_v(przeciwnicy[i]->get_basic_v()*0.5);
		}
	}
}

void cPlansza::start_muzyki() {
	if (play_music == 1) {
		muzyka.play();
		play_music = 2;
	}
}

void cPlansza::koniec_muzyki() {
	muzyka.stop();
}

void cPlansza::koniec_bohatera() {
	if (Bohater.get_life() == 0 && Bohater.getPosition().x > 0) {
		wybuch_x = Bohater.getPosition().x;
		wybuch_y = Bohater.getPosition().y;
		frame_wybuch = 1;
		Bohater.setPosition(-200, -200);
	}
}

bool cPlansza::przegrana() {
	if (Bohater.get_life() == 0 && frame_ochrona > 70) {
		muzyka.stop();
		return true;
	}
	else
		return false;
}