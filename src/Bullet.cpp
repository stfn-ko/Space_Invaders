#include "Bullet.h"




//$$	- Constructor/Deconstructor -	$$
Bullet::Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed) //player bullet
{
//@ Constructing a bullet 
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos_x, pos_y);
	this->sprite.scale(2.f, 2.f);
	this->direction = sf::Vector2f(dir_X, dir_Y);
	
	this->movementSpeed = movement_speed;
}
//
Bullet::Bullet(sf::Texture * texture, sf::Vector2f pos, sf::Vector2f dir, sf::Vector2f scale, float movement_speed, bool triBall) //enemy bullet
{
	if (triBall)
	{
		this->sprite.setTexture(*texture);
		this->sprite_add_1.setTexture(*texture);
		this->sprite_add_2.setTexture(*texture);

		this->sprite.setPosition(pos);
		this->sprite_add_1.setPosition(pos.x - 30.f, pos.y);
		this->sprite_add_2.setPosition(pos.x + 30.f, pos.y);

		this->sprite.scale(scale);
		this->sprite_add_1.scale(scale);
		this->sprite_add_2.scale(scale);

		this->direction = sf::Vector2f(dir.x, dir.y);

		this->triBall = triBall;
	}

	if (!triBall)
	{
		//@ Constructing an enemy bullet 
		this->sprite.setTexture(*texture);
		this->sprite.setPosition(pos);
		this->sprite.scale(scale);
		this->direction = sf::Vector2f(dir.x, dir.y);
	}

	this->movementSpeed = movement_speed;
}
//
Bullet::Bullet()
{

}
//
Bullet::~Bullet()
{

}
//



//$$			- Accessors -			$$
const sf::FloatRect Bullet::getBounds() const
{
//@ Get bounds of a bullet to detect intersection with enemy or to delete it if reaches the top of the screen
	return this->sprite.getGlobalBounds();
}
//
const sf::FloatRect Bullet::getBounds(int i) const
{
//@ Get bounds of enemy's bullet to detect intersection with palyerand to delete it if reaches the top of the screen

	if (i == 0) 
		return this->sprite.getGlobalBounds();
	if (i == 1) 
		return this->sprite_add_1.getGlobalBounds();
	if (i == 2) 
		return this->sprite_add_2.getGlobalBounds();
}
//



//##			 - UPDATE - 		# */
void Bullet::update()
{
//@ Updating direction and movement speed
	this->sprite.move(movementSpeed * direction);
	this->sprite_add_1.move(movementSpeed * sf::Vector2f(0.5f, 1.f));
	this->sprite_add_2.move(movementSpeed * sf::Vector2f(-0.5f, 1.f));
	
}
//



//##			 - RENDER - 		# */
void Bullet::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
	target->draw(this->sprite_add_1);
	target->draw(this->sprite_add_2);
}
//
