#ifndef __MY_GAMME__
#define __MY_GAMME__

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{

public :

void start(sf::RenderWindow &window, sf::Texture &start_background, sf::Sprite &start_Sprite, sf::RectangleShape &rect_buton, sf::Texture &textureButon);

void initialise(sf::RenderWindow &window, sf::RectangleShape &compteurshape, sf::RectangleShape &line, sf::RectangleShape &line1, sf::RectangleShape &line2, sf::RectangleShape &line3, int &size_border, sf::RectangleShape &line4, sf::RectangleShape &pacman, sf::RectangleShape &food, sf::Texture &texture, sf::Texture &texture2);
void draw_border(sf::RenderWindow &window, sf::RectangleShape &compteurshape, sf::RectangleShape &line, sf::RectangleShape &line1, sf::RectangleShape &line2, sf::RectangleShape &line3, sf::RectangleShape &line4);

void eventf(sf::RenderWindow &window, sf::RectangleShape &pacman, sf::Event &event, sf::RectangleShape &food, int &speed_cube, sf::Texture &texture);

void loose_by_walls(sf::RenderWindow &window, sf::RectangleShape &compteurshape, sf::RectangleShape &line, sf::RectangleShape &line1, sf::RectangleShape &line2, sf::RectangleShape &line3, sf::RectangleShape &pacman, sf::RectangleShape &line4);


private :

};


#endif