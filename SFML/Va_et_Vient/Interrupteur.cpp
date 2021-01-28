#include <SFML/Graphics.hpp>
#include <iostream>
#include "Interrupteur.h"

Interrupteur::Interrupteur(sf::RenderWindow& window)
{
	interrupteur_1.setSize(sf::Vector2f(150, 150));
	interrupteur_1.setPosition(sf::Vector2f(150, 300));

	interrupteur_2.setSize(sf::Vector2f(150, 150));
	interrupteur_2.setPosition(sf::Vector2f(700, 307));

    lampe.setSize(sf::Vector2f(260, 200));
    lampe.setPosition(sf::Vector2f(360, 150));

    if (!buton_power_Texture2.loadFromFile("Ressources/off.png"))
    {
        std::cout << "player_buton.png was not found" << std::endl;
    }
    if (!buton_power_Texture1.loadFromFile("Ressources/on.png"))
    {
        std::cout << "player_buton.png was not found" << std::endl;
    }
    if (!lampe_Texture_off1.loadFromFile("Ressources/ampoule_off.png"))
    {
        std::cout << "ampoule_off.png was not found" << std::endl;
    }
    if (!lampe_Texture_on1.loadFromFile("Ressources/ampoule_on.png"))
    {
        std::cout << "ampoule_on.png was not found" << std::endl;
    }

    buton_power_Texture1.setSmooth(true);
    buton_power_Texture2.setSmooth(true);
    lampe_Texture_off1.setSmooth(true);
    lampe_Texture_on1.setSmooth(true);

    interrupteur_1.setTexture(&buton_power_Texture1);
    interrupteur_2.setTexture(&buton_power_Texture2);
    lampe.setTexture(&lampe_Texture_off1);
}


void Interrupteur::drawing_interrupteurs(sf::RenderWindow& window)
{
	window.draw(interrupteur_1);
	window.draw(interrupteur_2);
    window.draw(lampe);
}

void Interrupteur::verifclicking(sf::RenderWindow& window)
{

        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        sf::FloatRect Interrupteur_pressed_1 = interrupteur_1.getGlobalBounds();
        sf::FloatRect Interrupteur_pressed_2 = interrupteur_2.getGlobalBounds();
       
        if (pressed_compteur_1 == false)
        {
            if (Interrupteur_pressed_1.contains(mouse))
            {
                pressed_compteur_1 = true;
                verif_equal_clicking_bool();
            }
        }
        else if (pressed_compteur_1 == true)
        {
            if (Interrupteur_pressed_1.contains(mouse))
            {
                pressed_compteur_1 = false;
                verif_equal_clicking_bool();
            }
        }


        if (pressed_compteur_2 == false)
        {
            if (Interrupteur_pressed_2.contains(mouse))
            {
                pressed_compteur_2 = true;
                verif_equal_clicking_bool();
            }
        }
        else if (pressed_compteur_2 == true)
        {
            if (Interrupteur_pressed_2.contains(mouse))
            {
                pressed_compteur_2 = false;
                verif_equal_clicking_bool();
            }
        }
}

void Interrupteur::verif_equal_clicking_bool()
{
    if (pressed_compteur_1 == true && pressed_compteur_2 == true)
    {
        std::cout << "ALLUMER" << std::endl;
        lampe.setTexture(&lampe_Texture_on1);
    }

    if (pressed_compteur_1 == false && pressed_compteur_2 == false)
    {
        std::cout << "ALLUMER" << std::endl;
        lampe.setTexture(&lampe_Texture_on1);
    }

    if (pressed_compteur_1 == false && pressed_compteur_2 == true)
    {
        std::cout << "ETEINT" << std::endl;
        lampe.setTexture(&lampe_Texture_off1);
    }

    if (pressed_compteur_1 == true && pressed_compteur_2 == false)
    {
        std::cout << "ETEINT" << std::endl;
        lampe.setTexture(&lampe_Texture_off1);
    }
}

void Interrupteur::verifclicking_color(sf::RenderWindow& window)
{
    if (pressed_compteur_1 == true)  { interrupteur_1.setTexture(&buton_power_Texture1); }
    if (pressed_compteur_1 == false) { interrupteur_1.setTexture(&buton_power_Texture2); }

    if (pressed_compteur_2 == true)  { interrupteur_2.setTexture(&buton_power_Texture1); }
    if (pressed_compteur_2 == false) { interrupteur_2.setTexture(&buton_power_Texture2); }
}