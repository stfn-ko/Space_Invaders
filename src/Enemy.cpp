#include "Enemy.h"




//$$	  - Private Funcs & Vars -	    $$ 
void Enemy::initTexture(int type)
{
//@ Initializing enemy hp
	if (!this->HP_texture.loadFromFile
	("Attributes/Textures/ENEMY/Enemy_hp.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load hp texture!\n";

//@ Initializing enemy texture depending on its type
	if (type == 1) //Bug
	{
		if (!this->texture.loadFromFile
		("Attributes/Textures/ENEMY/TEXTURE_Enemy_bug.png"))
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load texture!\n";
	}
	if (type == 2) //Ufo
	{
		if (!this->texture.loadFromFile
		("Attributes/Textures/ENEMY/TEXTURE_Enemy_ufo.png"))
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load texture!\n";
	}
	if (type == 3) //Dragon ship
	{
		if (!this->texture.loadFromFile
		("Attributes/Textures/ENEMY/TEXTURE_Enemy_dragonShip.png"))
			std::cout << "ERROR::PLAYER::INITTEXTURE::Failed to load texture!\n";
	}
}
//
void Enemy::initSprite(int type)
{
//@ Setting texture to the sprite
	this->sprite.setTexture(this->texture);
	this->HP_sprite.setTexture(this->HP_texture);

	if (type == 1)
	{
// Set hp texture for Bug
		sf::IntRect hp_txt(0, 0, 35, 5);
		this->HP_sprite.setTextureRect(hp_txt);
		this->HP_sprite.scale(2.f, 2.f);
	}
	if (type == 2)
	{
//@ Resize sprite & set hp texture for UFO
		sf::IntRect hp_txt(0, 31, 34, 5);
		this->HP_sprite.setTextureRect(hp_txt);
		this->HP_sprite.scale(2.5f, 2.5f);

		this->sprite.scale(2.f, 2.f);
	}
	if (type == 3)
	{
//@ Resize sprite & set hp texture for DragonShip
		sf::IntRect hp_txt(0, 61, 56, 5);
		this->HP_sprite.setTextureRect(hp_txt);
		this->HP_sprite.scale(3.5f, 3.5f);

		this->sprite.scale(3.f, 3.f);
	}
}
//
void Enemy::initVariables(int type)
{
//@ Initializing enemy characteristics
	if (type == 1)
	{
		this->hpMax = 5;
		this->movement = sf::Vector2f(0.f, 2.8f);
		this->hp = 0;
	}
	if (type == 2)
	{
		this->hpMax = 15;
		this->movement = sf::Vector2f(0.f, 1.4f);
		this->hp = 0;

		this->attackCoolDownMax = 200.f;
		this->attackCoolDown = this->attackCoolDownMax;
	}
	if (type == 3)
	{
		this->hpMax = 25;
		this->movement = sf::Vector2f(0.f, 0.7f);
		this->hp = 0;

		this->attackCoolDownMax = 290.f;
		this->attackCoolDown = this->attackCoolDownMax;
	}
}
//



//$$	- Constructor/Deconstructor -	$$
Enemy::Enemy(float hp_x, float hp_y, float pos_x, float pos_y, unsigned type)
{
//@ Constructing enemy
	this->initVariables(type);
	this->initTexture(type);
	this->initSprite(type);

	this->sprite.setPosition(pos_x, pos_y);
	this->HP_sprite.setPosition(pos_x + hp_x, pos_y + hp_y);

}
//
Enemy::~Enemy()
{

}
//



//$$		- Public Functions -		$$
void Enemy::loose_hp(int damage)
{
	hp += damage;
}
//
void Enemy::change_dir(sf::Vector2f direction)
{
	this->movement = direction;
}
//



//$$			- Accessors -			$$
const sf::FloatRect Enemy::getBounds() const
{
// Get bounds of an enemy to detect intersections with bullets or when it reaches the bottom of the screen
	return this->sprite.getGlobalBounds();
}
//
const sf::Vector2f& Enemy::getPos() const
{
	return this->sprite.getPosition();
}
const sf::Vector2f& Enemy::getDir() const
{
	return this->movement;
}
//
const bool Enemy::canAttack() 
{
	if (this->attackCoolDown >= this->attackCoolDownMax)
	{
		this->attackCoolDown = 1.f;
		return true;
	}

	return false;
}
//
const int Enemy::getHp() const
{
	return this->hp;
}
//
const int Enemy::getHpMax() const
{
	return this->hpMax;
}
//
int Enemy::get_points(int type)
{
//@ Getting points for killing enemies
	if(type == 1)
				return 5; //points for bug
	if (type == 2)
				return 50; //points for ufo
	if (type == 3)
				return 100; //points for dragon ship
}
//
sf::Vector2f Enemy::getDefaultDir(int type)
{
	if (type == 2)
	{
		return sf::Vector2f(0.f, 1.4f);
	}
	
	if (type == 3)
	{
		return sf::Vector2f(0.f, 0.7f);
	}
}
//



//##			 - UPDATE - 		# */
void Enemy::update_hp_bar(int type, int hp)
{
	if (type == 2)
	{
		sf::IntRect update_hp_bar(0, 31 + (hp / 5) * 7, 34, 5);
		this->HP_sprite.setTextureRect(update_hp_bar);
	}
	
	if (type == 3)
	{
		sf::IntRect update_hp_bar(0, 61 + (hp / 5) * 7, 56, 5);
		this->HP_sprite.setTextureRect(update_hp_bar);
	}

}
//
void Enemy::updateAttack()
{
	if (this->attackCoolDown < this->attackCoolDownMax)
		this->attackCoolDown += 1.f;
}
//
void Enemy::update()
{
	//@ Updating enemy speed
	this->sprite.move(movement);
	this->HP_sprite.move(movement);

	this->updateAttack();
}
//



//# #			 - RENDER - 		# */
void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->HP_sprite);
}
//