#include "Game.hpp"

void Game::start(sf::RenderWindow &window, sf::Texture &start_background, sf::Sprite &start_Sprite, sf::RectangleShape &rect_buton, sf::Texture &textureButon)
{
    if (!start_background.loadFromFile("Ressources/start.png"))
    {
        std::cout << "FATTAL ERROR WAS OCCURED" << std::endl;
    }
    start_Sprite.setTexture(start_background);
    start_Sprite.setPosition(sf::Vector2f(0, -200));

    rect_buton.setPosition(sf::Vector2f(310, 300));
    rect_buton.setSize(sf::Vector2f(350, 150));

    if(!textureButon.loadFromFile("Ressources/buton.png"))
    {
        std::cout << "Ressources/buton.png : NON CHARGER" << std::endl;
    }
    textureButon.setSmooth(true);
    rect_buton.setTexture(&textureButon);


}

void Game::initialise(sf::RenderWindow &window, sf::RectangleShape &compteurshape, sf::RectangleShape &line, sf::RectangleShape &line1, sf::RectangleShape &line2, sf::RectangleShape &line3, int &size_border, sf::RectangleShape &line4, sf::RectangleShape &pacman, sf::RectangleShape &food, sf::Texture &texture, sf::Texture &texture2)
{
    compteurshape.setPosition(sf::Vector2f(450, 0));
    compteurshape.setFillColor(sf::Color(255, 0, 0));
    compteurshape.setSize(sf::Vector2f(100, 50));

    line.setPosition(sf::Vector2f(-3, -3));
    line.setSize(sf::Vector2f(size_border, 600));
    line.setFillColor(sf::Color(255, 0, 0));

    line1.setPosition(sf::Vector2f(-3, -3));
    line1.rotate(-90);
    line1.setSize(sf::Vector2f(size_border, 1000));
    line1.setFillColor(sf::Color(255, 0, 0));

    line2.setPosition(sf::Vector2f(1003, 603));
    line2.rotate(90);
    line2.setSize(sf::Vector2f(size_border, 1000));
    line2.setFillColor(sf::Color(255, 0, 0));

    line3.setPosition(sf::Vector2f(1003, 603));
    line3.rotate(-180);
    line3.setSize(sf::Vector2f(size_border, 600));
    line3.setFillColor(sf::Color(255, 0, 0));

    line4.setPosition(sf::Vector2f(0, 59));
    line4.rotate(-90);
    line4.setSize(sf::Vector2f(59, 1000));
    line4.setFillColor(sf::Color(255, 0, 0));


    pacman.setSize(sf::Vector2f(30, 30));
    pacman.setPosition(sf::Vector2f(60, 90));

    if(!texture.loadFromFile("Ressources/all.png", sf::IntRect(16, 0, 16, 16)))
    {
        std::cout << "FATALL ERROR WAS OCCURED" << std::endl;
    }
    texture.setSmooth(false);
    pacman.setTexture(&texture);


    food.setSize(sf::Vector2f(30, 30));
    food.setPosition(sf::Vector2f(540, 360));

    if(!texture2.loadFromFile("Ressources/all.png", sf::IntRect(0, 176, 16, 16)))
    {
        std::cout << "FATALL ERROR WAS OCCURED" << std::endl;
    }
    food.setTexture(&texture2);
}

void Game::draw_border(sf::RenderWindow &window, sf::RectangleShape &compteurshape, sf::RectangleShape &line, sf::RectangleShape &line1, sf::RectangleShape &line2, sf::RectangleShape &line3, sf::RectangleShape &line4)
{
        window.draw(line);
        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
        window.draw(compteurshape);
}

void Game::eventf(sf::RenderWindow &window, sf::RectangleShape &pacman, sf::Event &event, sf::RectangleShape &food, int &speed_cube, sf::Texture &texture)
{
    if (event.key.code == sf::Keyboard::Right)
		{
			pacman.move(speed_cube, 0);

            if(!texture.loadFromFile("Ressources/all.png", sf::IntRect(16, 0, 16, 16)))
            {
                std::cout << "FATALL ERROR WAS OCCURED" << std::endl;
            }

            texture.setSmooth(false);
            pacman.setTexture(&texture);

		}
		else if (event.key.code == sf::Keyboard::Left)
		{
			pacman.move(-speed_cube, 0);

            if(!texture.loadFromFile("Ressources/all.png", sf::IntRect(16, 16, 16, 16)))
            {
                std::cout << "FATALL ERROR WAS OCCURED" << std::endl;
            }

            texture.setSmooth(false);
            pacman.setTexture(&texture);

		}
		else if (event.key.code == sf::Keyboard::Up)
		{
			pacman.move(0, -speed_cube);

            if(!texture.loadFromFile("Ressources/all.png", sf::IntRect(16, 32, 16, 16)))
            {
                std::cout << "FATALL ERROR WAS OCCURED" << std::endl;
            }

            texture.setSmooth(false);
            pacman.setTexture(&texture);
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			pacman.move(0, speed_cube);

            if(!texture.loadFromFile("Ressources/all.png", sf::IntRect(16, 48, 16, 16)))
            {
                std::cout << "FATALL ERROR WAS OCCURED" << std::endl;
            }

            texture.setSmooth(false);
            pacman.setTexture(&texture);
		}

}




void Game::loose_by_walls(sf::RenderWindow &window, sf::RectangleShape &compteurshape, sf::RectangleShape &line, sf::RectangleShape &line1, sf::RectangleShape &line2, sf::RectangleShape &line3, sf::RectangleShape &pacman, sf::RectangleShape &line4)
{
    sf::FloatRect boundingBoxcompteurshape = compteurshape.getGlobalBounds();
    sf::FloatRect boundingBoxline = line.getGlobalBounds();
    sf::FloatRect boundingBoxline1 = line1.getGlobalBounds();
    sf::FloatRect boundingBoxline2 = line2.getGlobalBounds();
    sf::FloatRect boundingBoxline3 = line3.getGlobalBounds();
    sf::FloatRect boundingBoxline4 = line4.getGlobalBounds();

    if (boundingBoxcompteurshape.intersects(pacman.getGlobalBounds()) || boundingBoxline.intersects(pacman.getGlobalBounds()) || boundingBoxline1.intersects(pacman.getGlobalBounds()) || boundingBoxline2.intersects(pacman.getGlobalBounds()) || boundingBoxline3.intersects(pacman.getGlobalBounds()) || boundingBoxline4.intersects(pacman.getGlobalBounds()))
    {
        std::cout << "ERROR" << std::endl;
    }




}
