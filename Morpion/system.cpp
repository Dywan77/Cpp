#include <iostream>
#include <SFML/Graphics.hpp>
#include "system.hpp"

System::System(sf::RenderWindow& window)
{
	window.create(sf::VideoMode(window_largeur, window_hauteur), "Dywan's Code", sf::Style::Close);

	if (!icon_app.loadFromFile("Ressources/icon_app.png"))
	{
		std::cout << "icon_app non chargée" << std::endl;
	}

	window.setIcon(1024, 1024, icon_app.getPixelsPtr());
}