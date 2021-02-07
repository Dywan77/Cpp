#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/System/String.hpp>
#include "Morpion.hpp"

Morpion::Morpion(sf::RenderWindow& window)
{
	if (!font_image_texture.loadFromFile("Ressources/font.png"))
	{
		std::cout << "font.png NON CHARGER" << std::endl;
	}
	if (!rond_texture.loadFromFile("Ressources/rond.png"))
	{
		std::cout << "rond.png NON CHARGER" << std::endl;
	}
	if (!croix_texture.loadFromFile("Ressources/croix.png"))
	{
		std::cout << "croix.png NON CHARGER" << std::endl;
	}
	if (!score_font.loadFromFile("Ressources/arial.ttf"))
	{
		std::cout << "arial.ttf NON CHARGER" << std::endl;
	}

	score_text1.setFont(score_font);
	score_text1.setString("0");
	score_text1.setPosition(sf::Vector2f(341, 19));
	score_text1.setFillColor(sf::Color::Black);
	score_text1.setCharacterSize(40);

	score_text2.setFont(score_font);
	score_text2.setString("0");
	score_text2.setPosition(sf::Vector2f(419, 19));
	score_text2.setFillColor(sf::Color::Black);
	score_text2.setCharacterSize(40);

	winner_croix_text.setFont(score_font);
	winner_croix_text.setString("Les CROIX on gagner !");
	winner_croix_text.setFillColor(sf::Color::White);
	winner_croix_text.setPosition(sf::Vector2f(150, 4));
	winner_croix_text.setCharacterSize(70);

	winner_rond_text.setFont(score_font);
	winner_rond_text.setString("Les ROND on gagner !");
	winner_rond_text.setFillColor(sf::Color::White);
	winner_rond_text.setPosition(sf::Vector2f(150, 4));
	winner_rond_text.setCharacterSize(70);

	banner_winner.setSize(sf::Vector2f(1000, 90));
	banner_winner.setFillColor(sf::Color::Black);

	font_image_texture.setSmooth(true); font_image_sprite.setTexture(font_image_texture);
	rond_texture.setSmooth(true); rond1.setTexture(&rond_texture); rond2.setTexture(&rond_texture); rond3.setTexture(&rond_texture); rond4.setTexture(&rond_texture); rond5.setTexture(&rond_texture);
	croix_texture.setSmooth(true); croix1.setTexture(&croix_texture); croix2.setTexture(&croix_texture); croix3.setTexture(&croix_texture); croix4.setTexture(&croix_texture); croix5.setTexture(&croix_texture);

	croix1.setPosition(sf::Vector2f(755, 10)); croix2.setPosition(sf::Vector2f(755, 125)); croix3.setPosition(sf::Vector2f(755, 239)); croix4.setPosition(sf::Vector2f(755, 360)); croix5.setPosition(sf::Vector2f(755, 484));
	croix1.setSize(sf::Vector2f(110, 110)); croix2.setSize(sf::Vector2f(110, 110)); croix3.setSize(sf::Vector2f(110, 110)); croix4.setSize(sf::Vector2f(110, 110)); croix5.setSize(sf::Vector2f(110, 110));
	
	rond1.setPosition(sf::Vector2f(870, 10)); rond2.setPosition(sf::Vector2f(870, 125)); rond3.setPosition(sf::Vector2f(870, 239)); rond4.setPosition(sf::Vector2f(870, 360)); rond5.setPosition(sf::Vector2f(870, 484));
	rond1.setSize(sf::Vector2f(110, 110)); rond2.setSize(sf::Vector2f(110, 110)); rond3.setSize(sf::Vector2f(110, 110)); rond4.setSize(sf::Vector2f(110, 110)); rond5.setSize(sf::Vector2f(110, 110));

	a.setSize(sf::Vector2f(170, 145)); a.setFillColor(sf::Color::Black); a.setPosition(sf::Vector2f(115, 85));
	b.setSize(sf::Vector2f(150, 150)); b.setFillColor(sf::Color::Black); b.setPosition(sf::Vector2f(312, 95));
	c.setSize(sf::Vector2f(150, 150)); c.setFillColor(sf::Color::Black); c.setPosition(sf::Vector2f(509, 95)); // il faut les mettre bien precisement, mais j'ai la flemme

	d.setSize(sf::Vector2f(150, 150)); d.setFillColor(sf::Color::Black); d.setPosition(sf::Vector2f(123, 262));
	e.setSize(sf::Vector2f(150, 150)); e.setFillColor(sf::Color::Black); e.setPosition(sf::Vector2f(313, 262));
	f.setSize(sf::Vector2f(150, 150)); f.setFillColor(sf::Color::Black); f.setPosition(sf::Vector2f(510, 262));

	g.setSize(sf::Vector2f(150, 150)); g.setFillColor(sf::Color::Black); g.setPosition(sf::Vector2f(125, 436));
	h.setSize(sf::Vector2f(150, 150)); h.setFillColor(sf::Color::Black); h.setPosition(sf::Vector2f(311, 436));
	i.setSize(sf::Vector2f(150, 150)); i.setFillColor(sf::Color::Black); i.setPosition(sf::Vector2f(506, 436));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Grille[i][j] = 0;
		}
	}
}

void Morpion::setPosition_croix(sf::RenderWindow& window)
{
	positionSouris = sf::Mouse::getPosition(window);
	int MouseX = positionSouris.x;
	int MouseY = positionSouris.y;
	croix1.setPosition(sf::Vector2f(MouseX, MouseY));
}

void Morpion::setPosition_rond(sf::RenderWindow& window)
{
	positionSouris = sf::Mouse::getPosition(window);
	int MouseX = positionSouris.x;
	int MouseY = positionSouris.y;
	rond1.setPosition(sf::Vector2f(MouseX, MouseY));
}



void Morpion::drawing(sf::RenderWindow& window)
{
	window.draw(font_image_sprite);
	window.draw(croix1); window.draw(croix2); window.draw(croix3); window.draw(croix4); window.draw(croix5);
	window.draw(rond1); window.draw(rond2); window.draw(rond3); window.draw(rond4); window.draw(rond5);
	if (draw_banner) { window.draw(banner_winner); }
	window.draw(score_text1); window.draw(score_text2);
	if (winnerIs == true && isEnd == true) { window.draw(winner_rond_text); }
	if (winnerIs == false && isEnd == true) { window.draw(winner_rond_text); }
	//window.draw(a); window.draw(b); window.draw(c);
	//window.draw(d); window.draw(e); window.draw(f);
	//window.draw(g); window.draw(h); window.draw(i);
}

void Morpion::printgrille()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " tab[ " << i << " ][ " << j << " ] = " << Grille[i][j] << std::endl;
		}
	}
}


void Morpion::click(sf::RenderWindow& window)
{
	sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	sf::FloatRect a_press = a.getGlobalBounds();
	sf::FloatRect b_press = b.getGlobalBounds();
	sf::FloatRect c_press = c.getGlobalBounds();

	sf::FloatRect d_press = d.getGlobalBounds();
	sf::FloatRect e_press = e.getGlobalBounds();
	sf::FloatRect f_press = f.getGlobalBounds();

	sf::FloatRect g_press = g.getGlobalBounds();
	sf::FloatRect h_press = h.getGlobalBounds();
	sf::FloatRect i_press = i.getGlobalBounds();

	if (a_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 1;
			verif(window, quelle_case);
		}
	}

	if (b_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 2;
			verif(window, quelle_case);
		}
	}

	if (c_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 3;
			verif(window, quelle_case);
		}
	}

	if (d_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 4;
			verif(window, quelle_case);
		}
	}

	if (e_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 5;
			verif(window, quelle_case);
		}
	}

	if (f_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 6;
			verif(window, quelle_case);
		}
	}

	if (g_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 7;
			verif(window, quelle_case);
		}
	}

	if (h_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 8;
			verif(window, quelle_case);
		}
	}

	if (i_press.contains(mouse))
	{
		if (turn_rond_or_croix == false || befor_this_turn_is == true)
		{
			quelle_case = 9;
			verif(window, quelle_case);
		}
	}

			//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


	if (a_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 1;
			verif(window, quelle_case);
		}
	}

	if (b_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 2;
			verif(window, quelle_case);
		}
	}

	if (c_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 3;
			verif(window, quelle_case);
		}
	}

	if (d_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 4;
			verif(window, quelle_case);
		}
	}

	if (e_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 5;
			verif(window, quelle_case);
		}
	}

	if (f_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 6;
			verif(window, quelle_case);
		}
	}

	if (g_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 7;
			verif(window, quelle_case);
		}
	}

	if (h_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 8;
			verif(window, quelle_case);
		}
	}

	if (i_press.contains(mouse))
	{
		if (turn_rond_or_croix == true || befor_this_turn_is == false)
		{
			quelle_case = 9;
			verif(window, quelle_case);
		}
	}
}

void Morpion::verif(sf::RenderWindow& window, unsigned int quelle_case)
{
	if (quelle_case == 1)
	{
		if (Grille[0][0] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[0][0] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[0][0] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 2)
	{
		if (Grille[0][1] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[0][1] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[0][1] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 3)
	{
		if (Grille[0][2] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[0][2] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[0][2] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 4)
	{
		if (Grille[1][0] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[1][0] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[1][0] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 5)
	{
		if (Grille[1][1] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[1][1] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[1][1] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 6)
	{
		if (Grille[1][2] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[1][2] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[1][2] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 7)
	{
		if (Grille[2][0] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[2][0] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[2][0] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 8)
	{
		if (Grille[2][1] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[2][1] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[2][1] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}

	if (quelle_case == 9)
	{
		if (Grille[2][2] == 0)
		{
			if (turn_rond_or_croix == true)
			{
				placer_rond(window, quelle_case);
			}
			else { placer_croix(window, quelle_case); }
		}
		else if (Grille[2][2] == 1) { std::cout << "Deja une croix dessus" << std::endl; }
		else if (Grille[2][2] == 2) { std::cout << "Deja un rond dessus" << std::endl; }
	}
}

void Morpion::placer_croix(sf::RenderWindow& window, unsigned int quelle_case)
{
	if (quelle_case == 1)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[0][0] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(128, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[0][0] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(128, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[0][0] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(128, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[0][0] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(128, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[0][0] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(128, 95));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 2)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[0][1] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(312, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[0][1] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(312, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[0][1] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(312, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[0][1] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(312, 95));
			befor_this_turn_is = false;

		}
		if (compteur_tour_croix == 4)
		{
			Grille[0][1] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(312, 95));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 3)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[0][2] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(509, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[0][2] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(509, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[0][2] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(509, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[0][2] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(509, 95));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[0][2] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(509, 95));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 4)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[1][0] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(123, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[1][0] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(123, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[1][0] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(123, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[1][0] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(123, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[1][0] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(123, 262));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 5)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[1][1] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(313, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[1][1] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(313, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[1][1] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(313, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[1][1] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(313, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[1][1] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(313, 262));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 6)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[1][2] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(510, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[1][2] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(510, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[1][2] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(510, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[1][2] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(510, 262));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[1][2] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(510, 262));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 7)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[2][0] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(125, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[2][0] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(125, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[2][0] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(125, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[2][0] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(125, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[2][0] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(125, 436));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 8)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[2][1] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(311, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[2][1] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(311, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[2][1] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(311, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[2][1] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(311, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[2][1] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(311, 436));
			befor_this_turn_is = false;
		}
	}
	else if (quelle_case == 9)
	{
		if (compteur_tour_croix == 0)
		{
			Grille[2][2] = 1;
			croix1.setSize(sf::Vector2f(140, 140));
			croix1.setPosition(sf::Vector2f(506, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 1)
		{
			Grille[2][2] = 1;
			croix2.setSize(sf::Vector2f(140, 140));
			croix2.setPosition(sf::Vector2f(506, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 2)
		{
			Grille[2][2] = 1;
			croix3.setSize(sf::Vector2f(140, 140));
			croix3.setPosition(sf::Vector2f(506, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 3)
		{
			Grille[2][2] = 1;
			croix4.setSize(sf::Vector2f(140, 140));
			croix4.setPosition(sf::Vector2f(506, 436));
			befor_this_turn_is = false;
		}
		if (compteur_tour_croix == 4)
		{
			Grille[2][2] = 1;
			croix5.setSize(sf::Vector2f(140, 140));
			croix5.setPosition(sf::Vector2f(506, 436));
			befor_this_turn_is = false;
		}
	}
	
	turn_rond_or_croix = true;
	compteur_tour_croix++;
	verif_winnner(window);
}

void Morpion::placer_rond(sf::RenderWindow& window, unsigned int quelle_case)
{
	if (quelle_case == 1)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[0][0] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(125, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[0][0] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(125, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[0][0] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(125, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[0][0] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(125, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[0][0] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(125, 92));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 2)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[0][1] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(313, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[0][1] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(313, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[0][1] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(313, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[0][1] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(313, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[0][1] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(313, 92));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 3)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[0][2] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(508, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[0][2] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(508, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[0][2] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(508, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[0][2] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(508, 92));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[0][2] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(508, 92));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 4)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[1][0] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(125, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[1][0] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(125, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[1][0] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(125, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[1][0] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(125, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[1][0] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(125, 260));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 5)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[1][1] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(310, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[1][1] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(310, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[1][1] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(310, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[1][1] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(310, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[1][1] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(310, 260));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 6)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[1][2] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(508, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[1][2] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(508, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[1][2] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(508, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[1][2] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(508, 260));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[1][2] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(508, 260));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 7)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[2][0] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(124, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[2][0] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(124, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[2][0] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(124, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[2][0] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(124, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[2][0] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(124, 430));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 8)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[2][1] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(315, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[2][1] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(315, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[2][1] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(315, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[2][1] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(315, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[2][1] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(315, 430));
			befor_this_turn_is = true;
		}
	}
	else if (quelle_case == 9)
	{
		if (compteur_tour_rond == 0)
		{
			Grille[2][2] = 2;
			rond1.setSize(sf::Vector2f(140, 140));
			rond1.setPosition(sf::Vector2f(506, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 1)
		{
			Grille[2][2] = 2;
			rond2.setSize(sf::Vector2f(140, 140));
			rond2.setPosition(sf::Vector2f(506, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 2)
		{
			Grille[2][2] = 2;
			rond3.setSize(sf::Vector2f(140, 140));
			rond3.setPosition(sf::Vector2f(506, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 3)
		{
			Grille[2][2] = 2;
			rond4.setSize(sf::Vector2f(140, 140));
			rond4.setPosition(sf::Vector2f(506, 430));
			befor_this_turn_is = true;
		}
		if (compteur_tour_rond == 4)
		{
			Grille[2][2] = 2;
			rond5.setSize(sf::Vector2f(140, 140));
			rond5.setPosition(sf::Vector2f(506, 430));
			befor_this_turn_is = true;
		}
	}

	turn_rond_or_croix = false;
	compteur_tour_rond++;
	verif_winnner(window);
}

void Morpion::verif_winnner(sf::RenderWindow& window)
{
	if (Grille[0][0] == 1 && Grille[0][1] == 1 && Grille[0][2] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[1][0] == 1 && Grille[1][1] == 1 && Grille[1][2] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[2][0] == 1 && Grille[2][1] == 1 && Grille[2][2] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[0][0] == 1 && Grille[0][1] == 1 && Grille[0][2] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[1][0] == 1 && Grille[1][1] == 1 && Grille[1][2] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[2][0] == 1 && Grille[2][1] == 1 && Grille[2][2] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[0][2] == 1 && Grille[1][1] == 1 && Grille[2][0] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[0][0] == 1 && Grille[1][1] == 1 && Grille[2][2] == 1)
	{
		std::cout << "Le joueur Croix a gagner" << std::endl;
		isEnd = true;
	}


	//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


	if (Grille[0][0] == 2 && Grille[0][1] == 2 && Grille[0][2] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[1][0] == 2 && Grille[1][1] == 2 && Grille[1][2] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[2][0] == 2 && Grille[2][1] == 2 && Grille[2][2] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[0][0] == 2 && Grille[0][1] == 2 && Grille[0][2] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[1][0] == 2 && Grille[1][1] == 2 && Grille[1][2] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[2][0] == 2 && Grille[2][1] == 2 && Grille[2][2] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[0][2] == 2 && Grille[1][1] == 2 && Grille[2][0] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}
	if (Grille[0][0] == 2 && Grille[1][1] == 2 && Grille[2][2] == 2)
	{
		std::cout << "Le joueur Rond a gagner" << std::endl;
		isEnd = true;
	}

	if (isEnd == true)
	{
		draw_banner = true;
	}
}