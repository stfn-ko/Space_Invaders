#ifndef BULLET_H
#define BULLET_H

///Includes
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/// Class
class Bullet

{//$$			 - Private -			$$
private:

//	Textures/Sprites/Shapes     %
	sf::Sprite sprite;
	sf::Sprite sprite_add_1;
	sf::Sprite sprite_add_2;

//	Varibles		            %
	sf::Vector2f direction;
	float movementSpeed;
	bool triBall = false;

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:
	Bullet();
	Bullet(sf::Texture * texture, float pos_x, float pos_y,
		float dir_X, float dir_Y, float movement_speed);
	Bullet(sf::Texture * texture, sf::Vector2f pos, 
		sf::Vector2f dir, sf::Vector2f scale, float movement_speed, bool triBall);

	~Bullet();

//	Accessors					%
	const sf::FloatRect getBounds() const;
	const sf::FloatRect getBounds(int triball) const;

//	Program U-R                 %
	void update();
	void render(sf::RenderTarget* target);

};//&&		 - End of Public -			&&

#endif //!BULLET_H