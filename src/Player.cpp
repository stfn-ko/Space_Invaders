#include "Player.h"




//$$	  - Private Funcs & Vars -	    $$
void Player::initTexture()
{
	if (!this->player_texture.loadFromFile
	("Attributes/Textures/PLAYER/TEXTURE_Player_spritesheet.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load texture!\n";

	if (!this->shield_texture.loadFromFile
	("Attributes/Textures/PLAYER/Shield/Shield_v2.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load shield texture!\n";
}
//
void Player::initVariables()
{
	this->HP = 5;
	this->Shield = 3;
	this->damage = 5;
	this->movementSpeedBase = 7.f;
	this->movementSpeed = this->movementSpeedBase;

	this->attackCoolDownMax = 40.f;
	this->attackCoolDown = this->attackCoolDownMax;
}
//
void Player::initSprite()
{
//Setting texture to the sprite	    %
	this->player_sprite.setTexture(this->player_texture);
	this->shield_sprite.setTexture(this->shield_texture);

// Set Texture rectangle
	this->player_sprite.setTextureRect(sf::IntRect( 140.f, 0.f, 71.f, 81.f));
	this->player_sprite.setTextureRect(sf::IntRect(4.f, 0.f, 75.f, 81.f));

//Resize the sprite					%
	this->player_sprite.scale(2.f, 2.f);
	this->shield_sprite.scale(2.f, 2.f);
}
//



//$$	- Constructor/Deconstructor -	$$
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}
//
Player::~Player()
{

}
//



//$$			- Accessors -			$$
const sf::Vector2f & Player::getPos() const
{
	return this->player_sprite.getPosition();
}
//
float Player::getSize()
{
	return this->player_sprite.getLocalBounds().width, this->player_sprite.getLocalBounds().height;
}
//
int Player::get_HP()
{
	return this->HP;
}
//
int Player::get_Shield()
{
	return this->Shield;
}
//
int Player::minus_HP()
{
	this->HP--;
	return this->HP;
}
//
int Player::minus_Shield()
{
	this->Shield--;
	return this->Shield;
}
//
const sf::FloatRect Player::getBounds() const
{
	return this->player_sprite.getGlobalBounds();
}
//
const int Player::getDMG() const
{
	return this->damage;
}
//



//$$		- Public Functions -		$$
void Player::move(const float dirX, const float dirY)
{
	this->player_sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	this->shield_sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}
//
void Player::setPos(float pos_x, float pos_y)
{
	this->player_sprite.setPosition(pos_x, pos_y);
	this->shield_sprite.setPosition(pos_x - 32.f, pos_y - 32.f);
}
//
void Player::upgradeSpeed()
{
	int var = this->movementSpeedBase;

	this->movementSpeed += (var / 10);
}
//
void Player::upgradeShootingSpeed()
{
	int var = this->attackCoolDownMax;

	this->attackCoolDownMax -= ((var / 100) * 8);
}
//
const bool Player::canAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax)
	{
		this->attackCoolDown = 1.f;
		return true;
	}
	
	return false;
}
//



//##			 - UPDATE - 		# */
void Player::animation()
{
	if (this->counter > 2)
		this->counter = 0;

	if (this->animationClock.getElapsedTime().asMilliseconds() > 50.f)
	{
		this->player_sprite.setTextureRect
		(sf::IntRect(70 * this->counter, 0.f, 71.f, 81.f));
		this->animationClock.restart();
	}

	this->counter++;
}
//
void Player::deleteShield()
{
	if(this->Shield <= 0)
	this->shield_sprite.setTextureRect(sf::IntRect(0,0,0,0));
}
//
void Player::updateAttack()
{
	if (this->attackCoolDown < this->attackCoolDownMax)
		this->attackCoolDown += 1.f;
}
//
void Player::update()
{
	this->deleteShield();
	this->animation();
	this->updateAttack();
}
//



//##			 - RENDER - 		# */
void Player::render(sf::RenderTarget& Target)
{
	Target.draw(this->shield_sprite);
	Target.draw(this->player_sprite);
}
//