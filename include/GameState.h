#ifndef GAMESTATE_H
#define GAMESTATE_H



///Includes
#include <SFML/Graphics.hpp>
#include <iostream>

/// Class
class GameState
{//$$			 - Private -			$$
	
private:
//	Textures/Sprites/Shapes     %
	sf::Texture shade_texture;
	sf::Texture interface_texture;
	sf::Texture end_tx_win;
	sf::Texture end_tx_loose;
	sf::Texture exit_play_select;

	sf::Sprite shade_sprtie;
	sf::Sprite interface_sprite;
	sf::Sprite end_sprite;
	sf::Sprite exit;
	sf::Sprite play;

//	Varibles		            %
	float conter_counter = -8;
	float counter = 7;
	bool right;
	bool isHighlighted = false;
	sf::Clock animation_clock;

// Private Functions			%
	void initTextures();
	void initSprites();

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:

	GameState();
	~GameState();

	bool exit_bool = false;
	bool play_bool = false;

//	Program U-R                 %
	void update(sf::Vector2f screensize, bool ending);
	void render(sf::RenderTarget* target);

};//&&		 - End of Public -			&&

#endif //!GAMESTATE_H