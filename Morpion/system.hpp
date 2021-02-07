#ifndef __SYSTEM__
#define __SYSTEM__

#include <iostream>
#include <SFML/Graphics.hpp>

class System
{
public :

	System(sf::RenderWindow& window);


private :

	sf::Image icon_app;
	sf::RenderWindow window;
	unsigned int window_largeur = 1000;
	unsigned int window_hauteur = 600;


};



#endif