#include <SFML/Graphics.hpp>
#include <iostream>
#include "system.hpp"
#include "Morpion.hpp"

int main()
{

#pragma region def

    sf::RenderWindow window;

#pragma endregion def


    System system(window);
    Morpion morpion(window);

    morpion.printgrille();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    //morpion.setPosition_croix(window);
                    morpion.click(window);

                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
        }

        window.clear();
        morpion.drawing(window);
        window.display();
    }

    return 0;
}