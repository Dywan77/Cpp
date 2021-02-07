#include <SFML/Graphics.hpp>
#include <iostream>
#include "System.h"


System::System(sf::RenderWindow& window)
{
    window.create(sf::VideoMode(window_init_L, window_init_h), "Dywan's Code", sf::Style::Close);
    if (!icon_app.loadFromFile("Ressources/logo.png"))
    {
        std::cout << "Erreur de chargement : Ressources/pi.jpg" << std::endl;
    }
    window.setIcon(232, 255, icon_app.getPixelsPtr());


    if (!font.loadFromFile("Ressources/font.ttf"))
    {
        std::cout << "FAILED TO LOAD font.ttf" << std::endl;
    }

    texte.setString("Va et Vient");
    texte.setFont(font);
    texte.setCharacterSize(75);
    texte.setPosition(sf::Vector2f(275, 40));

}

void System::drawing_txt(sf::RenderWindow& window)
{
    window.draw(texte);
}