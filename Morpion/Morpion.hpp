#ifndef __MORPION__
#define __MORPION__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/System/String.hpp>


class Morpion
{
public :
	Morpion(sf::RenderWindow& window);
	void drawing(sf::RenderWindow& window);
	void setPosition_croix(sf::RenderWindow& window);
	void setPosition_rond(sf::RenderWindow& window);
	void click(sf::RenderWindow& window);
	void verif(sf::RenderWindow& window, unsigned int quelle_case);
	void placer_croix(sf::RenderWindow& window, unsigned int quelle_case);
	void placer_rond(sf::RenderWindow& window, unsigned int quelle_case);
	void verif_winnner(sf::RenderWindow& window);

	void printgrille();

private :
	enum TypeCase { VIDE, ROND, CROIX };
	int Grille[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	unsigned int quelle_case = 0;
	unsigned int compteur_tour_croix = 0;
	unsigned int compteur_tour_rond = 0;
	bool turn_rond_or_croix = false;
	bool befor_this_turn_is = true;
	bool isEnd = false;
	bool draw_banner = false;
	bool winnerIs = false;
	sf::Texture font_image_texture, croix_texture, rond_texture;
	sf::Sprite font_image_sprite;

	sf::RectangleShape croix1, croix2, croix3, croix4, croix5;
	sf::RectangleShape rond1, rond2, rond3, rond4, rond5;
	sf::RectangleShape a, b, c, d, e, f, g, h, i;
	sf::RectangleShape banner_winner;

	sf::Vector2i positionSouris;

	sf::Text score_text1;
	sf::Text score_text2;
	sf::Text winner_rond_text;
	sf::Text winner_croix_text;

	sf::Font score_font;
};

#endif