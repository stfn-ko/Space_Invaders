#ifndef BARRICADE_H
#define BARRICADE_H

/// Include
#include <iostream>

#include <SFML/Graphics.hpp>

/// Class
class Barricade
{//$$			 - Private -			$$
private:

//	Textures/Sprites/Shapes     %
	sf::Texture engine_texture;
	sf::Texture barrier_texture;

	sf::Sprite engine_sprite;
	sf::Sprite barrier_sprite;

//	Varibles		            %
	float movement_speed;
	float levitation_speed;
	bool destroyed;

// Clocks and counters			%
	int HP;
	int movement_counter;
	int counter;

// Private Functions			%
	void initTexture();
	void initSprite();
	void initVariables();
	void barrier_condition(int count);

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:

// Public Functions				%
	Barricade();
	Barricade(float pos_x_ENG, float pos_y_ENG, float pos_x_BAR, float pos_y_BAR);
	~Barricade();

//	Accessors					%
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPos() const;
	
	int get_hp();
	int get_barr(int type);

	int GET_time_count_barr_destruction();
	bool check_destroyed();

//	Program U-R                 %
	void update();
	void barr_movement(); 
	void barrier_collapse();
	
	void render(sf::RenderTarget& target);

};//&&		 - End of Public -			&&
#endif //!BARRICADE_H
