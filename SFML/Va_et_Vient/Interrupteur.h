#ifndef __INTERRUPTEUR__
#define __INTERRUPTEUR__

class Interrupteur
{

public :

	Interrupteur(sf::RenderWindow& window);

	void drawing_interrupteurs(sf::RenderWindow& window);
	void verifclicking(sf::RenderWindow& window);
	void verifclicking_color(sf::RenderWindow& window);

	void verif_equal_clicking_bool();



private :
	sf::RectangleShape interrupteur_1, interrupteur_2;
	sf::RectangleShape lampe;
	
	sf::Texture buton_power_Texture1, buton_power_Texture2;
	sf::Sprite buton_power_Sprite1, buton_power_Sprite2;

	sf::Sprite lampe_Spriteoff2, lampe_Sprite_on2;
	sf::Texture lampe_Texture_on1, lampe_Texture_off1;

	bool pressed_compteur_1 = true;
	bool pressed_compteur_2 = false;

};


#endif;