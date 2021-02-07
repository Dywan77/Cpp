#ifndef __SYSTEM__
#define __SYSTEM__

class System
{
public :

	System(sf::RenderWindow& window);

	void drawing_txt(sf::RenderWindow& window);


private :

	sf::Image icon_app;

	unsigned int window_init_L = 1000;
	unsigned int window_init_h = 600;

	sf::Font font;
	sf::Text texte;

};




#endif
