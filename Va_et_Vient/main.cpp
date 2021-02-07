#include <SFML/Graphics.hpp>
#include "Interrupteur.h"
#include "System.h"
#include <SFML/System/Clock.hpp>
#include <iostream>


int main()
{
#pragma region def

    sf::RenderWindow window;
    sf::Event event;
    sf::Clock clock;

    System system(window);
    Interrupteur interrupteur(window);

    unsigned int cooldown_click = 200;

#pragma endregion def

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Time the_clock = clock.getElapsedTime();
                sf::Time t2 = sf::milliseconds(cooldown_click);

                if (the_clock > t2)
                {
                    interrupteur.verifclicking(window);
                    interrupteur.verifclicking_color(window);
                    clock.restart();
                }
                else if (the_clock < t2)
                {
                    break;
                }

            }

        }
        window.clear();
        interrupteur.drawing_interrupteurs(window);
        system.drawing_txt(window);
        window.display();
    }
    return 0;
}