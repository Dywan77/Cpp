#include <SFML/Graphics/Image.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

#pragma region def

sf::RenderWindow window(sf::VideoMode(993, 600), "Dywan's Code", sf::Style::Close);
sf::Image icon;
sf::Texture start_background;
sf::Sprite start_Sprite;
int speed_cube = 30;
int size_border = 2;
int compteur_menue = 0;
int compteur_round = 0;

sf::SoundBuffer buffer;
sf::Sound sound;

sf::RectangleShape compteurshape;
sf::RectangleShape line;
sf::RectangleShape line1;
sf::RectangleShape line2;
sf::RectangleShape line3;
sf::RectangleShape line4;
sf::RectangleShape rect_buton;

sf::Event event;
sf::RectangleShape pacman;
sf::Sprite pac_man;
sf::Texture texture;
sf::RectangleShape food;
sf::Texture texture2;
sf::Texture textureButon;


#pragma endregion def


int main()
{
    icon.loadFromFile("Ressources/pi.jpg");

    window.setIcon(256,256,icon.getPixelsPtr());
    window.setFramerateLimit(60);
    Game game;

    game.start(window, start_background, start_Sprite, rect_buton, textureButon);

    game.initialise(window, compteurshape, line, line1, line2, line3, size_border, line4, pacman, food, texture, texture2);


        if (!buffer.loadFromFile("Ressources/12.wav"))
        {
            std::cout << "Ressources/songM.mp4 : NON CHARGER" << std::endl;
            //window.close();
            //EXIT_FAILURE;
        }


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

            if (event.type == sf::Event::KeyPressed)
            {
                game.eventf(window, pacman, event, food, speed_cube, texture);
                        
                sf::FloatRect boundingBoxfood = food.getGlobalBounds();
                
                game.loose_by_walls(window, compteurshape, line, line1, line2, line3, pacman, line4);

                if (boundingBoxfood.intersects(pacman.getGlobalBounds()) && compteur_round == 0)
                {
                    std::cout << "LVL 1" << std::endl;
                    food.setPosition(sf::Vector2f(420, 240));
                    pacman.setPosition(sf::Vector2f(60, 90));
                    compteur_round++;
                }
                if (boundingBoxfood.intersects(pacman.getGlobalBounds()) && compteur_round == 1)
                {
                    std::cout << "LVL 2" << std::endl;
                    food.setPosition(sf::Vector2f(540, 180));
                    pacman.setPosition(sf::Vector2f(60, 90));
                    compteur_round++;
                }
                if (boundingBoxfood.intersects(pacman.getGlobalBounds()) && compteur_round == 2)
                {
                    std::cout << "LVL 3" << std::endl;
                    food.setPosition(sf::Vector2f(660, 570));
                    pacman.setPosition(sf::Vector2f(60, 90));
                    compteur_round++;
                }
                if (boundingBoxfood.intersects(pacman.getGlobalBounds()) && compteur_round == 3)
                {
                    std::cout << "LVL 4" << std::endl;
                    food.setPosition(sf::Vector2f(900, 510));
                    pacman.setPosition(sf::Vector2f(60, 90));
                    compteur_round++;
                }
                if (boundingBoxfood.intersects(pacman.getGlobalBounds()) && compteur_round == 4)
                {
                    std::cout << "LVL 5" << std::endl;
                    food.setPosition(sf::Vector2f(540, 180));
                    pacman.setPosition(sf::Vector2f(60, 90));
                    compteur_round++;
                }

            }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            sf::FloatRect bounds = rect_buton.getGlobalBounds();

            // hit test
            if (bounds.contains(mouse))
            {
                std::cout << "START" << std::endl;
                compteur_menue++;
            }

     
        }
    }  

        }

        window.clear();

        sound.setBuffer(buffer);
        sound.play();

        if(compteur_menue == 0)
        {
        window.draw(start_Sprite);
        window.draw(rect_buton); 
        }
        if(compteur_menue != 0)
        {
            game.draw_border(window, compteurshape, line, line1, line2, line3, line4);
            window.draw(food);
            window.draw(pacman);
        }
        window.display();
    }
    return 0;
}