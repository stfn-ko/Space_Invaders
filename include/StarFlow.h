#ifndef STARFLOW_H
#define STARFLOW_H

/// Includes
#include <iostream>

#include <SFML/Graphics.hpp>

/// Class
class StarFlow
{//$$			 - Private -			$$
private:

//	Textures/Sprites/Shapes     %
	sf::CircleShape particle;

//	Varibles		            %
	sf::Vector2f direction;
	float movementSpeed;
	unsigned int type;
	float particleGenTimer;
	float particleGenTimerMax;
	int maxParticles;
	
// Private Functions			%
	void initVariables();

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:

	StarFlow();
	StarFlow(unsigned int type, float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed, float pointCount, float rad, sf::Color color);
	~StarFlow();

// Public Functions				%
	const bool canGenerate();
	void updateGenerator();

//	Accessors					%
	const sf::FloatRect getBounds() const;

//	Program U-R                 %
	void update();
	void render(sf::RenderTarget* target);

};//&&		 - End of Public -			&&

#endif //!STARFLOW