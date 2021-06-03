#ifndef PLAYER_H
#define PLAYER_H

/// Includes
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

/// Class
class Player
{//$$			 - Private -			$$
private:

//	Textures/Sprites/Shapes     %
	sf::Sprite player_sprite;
	sf::Sprite shield_sprite;
	sf::Texture player_texture;
	sf::Texture shield_texture;

// Clocks and counters			%
	sf::Clock animationClock;
	int counter = 0;

// Varibles		                %
	float attackCoolDown;
	float attackCoolDownMax;

	int damage;
	int HP;
	int Shield;

	float movementSpeed;
	float movementSpeedBase;

private:
// Private Functions			%
	void initVariables();
	void initTexture();
	void initSprite();

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:
	Player();
	virtual ~Player();

// Public Functions				%
	void move(const float dirX, const float dirY);
	void setPos(float pos_x, float pos_y);

	void upgradeSpeed();
	void upgradeShootingSpeed();

//	Accessor					%
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	
	const bool canAttack();
	const int getDMG() const;

	float getSize();
	int get_HP();
	int get_Shield();
	int minus_HP();
	int minus_Shield();
	
// Program U-R                  %
	void animation();
	void deleteShield();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& Target);

};//&&		 - End of Public -			&&

#endif //!PLAYER_H
