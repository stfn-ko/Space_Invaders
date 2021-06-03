#ifndef UPGRADE_H
#define UPGRADE_H



///Includes
#include "Player.h"
#include "Barricade.h"

#include <iostream>

#include <SFML/Graphics.hpp>

/// Class
class Upgrade : public Player, public Barricade
{//$$			 - Private -			$$
private:
	
//	Textures/Sprites/Shapes     %
	sf::Texture texture_window;
	sf::Texture texture_buff;
	sf::Texture vingnette_t;
	
	sf::Sprite sprite_window;
	sf::Sprite arrow;
	sf::Sprite sprite_buff_left;
	sf::Sprite sprite_buff_right;
	sf::Sprite vingnette_s;

//	Varibles		            %
	int counter_switch = 0;
	int y_coord = 0;

// Private Functions			%
	void initVariables();
	void initTextures();
	void initSprites();

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:
	Upgrade();
	Upgrade(float pos_x, float pos_y, float pos_buff_x, float pos_buff_y);
	~Upgrade();

// Public Functions				%
	void hide();

//	Counters					%
	int upg_counter_left;
	int upg_counter_right;

//	Program U-R                 %
	void update(int side, float pos_x, float pos_y);
	void render(sf::RenderTarget* target);
};//&&		 - End of Public -			&&

#endif //!UPGRADE_H
