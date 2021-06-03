#include "Barricade.h"



//$$	  - Private Funcs & Vars -	    $$
void Barricade::initTexture()
{
if (!this->engine_texture.loadFromFile("Attributes/Textures/BARRICADE/Engine_status.png"))
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Failed to load Engine texture!\n";
	}

if (!this->barrier_texture.loadFromFile("Attributes/Textures/BARRICADE/Barrier_status.png"))
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Failed to load Barrier texture!\n";
	}	
}
//
void Barricade::initSprite()
{
//@ Initializing sprite for barricade's condition
	sf::IntRect rectSourceSprite_engine(0, 0, 248, 72);
	sf::IntRect rectSourceSprite_barrier(0, 11, 248, 52);

//@ Engine
	this->engine_sprite.setTexture(this->engine_texture);
	this->engine_sprite.setTextureRect(rectSourceSprite_engine);
	this->engine_sprite.setScale(2.f, 2.f);

//@ Barrier
	this->barrier_sprite.setTexture(this->barrier_texture);
	this->barrier_sprite.setTextureRect(rectSourceSprite_barrier);
	this->barrier_sprite.setScale(2.f, 2.f);
}
//
void Barricade::initVariables()
{
	this->HP = 0;
	
	this->destroyed = false;

	this->counter = 0;
}
//
void Barricade::barrier_condition(int count)
{
	if (count == 1)
	{
		sf::IntRect minus_hp(0, 70, 248, 36);
		this->barrier_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setPosition(this->barrier_sprite.getPosition().x, this->barrier_sprite.getPosition().y + 32);
	}

	if (count == 2)
	{
		sf::IntRect minus_hp(0, 113, 248, 20);
		this->barrier_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setPosition(this->barrier_sprite.getPosition().x, this->barrier_sprite.getPosition().y + 32);
	}
}
//@ Animation
void Barricade::barrier_collapse()
{
	if (counter == 0)
	{
		sf::IntRect minus_hp(0, 138, 248, 23);
		this->barrier_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setPosition(this->barrier_sprite.getPosition().x, this->barrier_sprite.getPosition().y - 4.f);
	}

	if (counter == 1)
	{
		sf::IntRect minus_hp(0, 78, 248, 72);
		sf::IntRect minus_hp_1(0, 165, 248, 23);

		this->engine_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setTextureRect(minus_hp_1);
	}   

	if (counter == 2)
	{
		sf::IntRect minus_hp(0, 138, 248, 23);
		sf::IntRect minus_hp_1(	0, 0, 248, 72);

		this->barrier_sprite.setTextureRect(minus_hp);
		this->engine_sprite.setTextureRect(minus_hp_1);
	}

	if (counter == 3)
	{
		sf::IntRect minus_hp(0, 78, 248, 72);
		sf::IntRect minus_hp_1(0, 165, 248, 23);

		this->engine_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setTextureRect(minus_hp_1);
	}
	
	if (counter == 4)
	{
		sf::IntRect minus_hp(0, 138, 248, 23);
		sf::IntRect minus_hp_1(0, 0, 248, 72);

		this->barrier_sprite.setTextureRect(minus_hp);
		this->engine_sprite.setTextureRect(minus_hp_1);
	}
		
	if (counter == 5)
	{
		sf::IntRect minus_hp(0, 78, 248, 72);
		sf::IntRect minus_hp_1(0, 165, 248, 23);

		this->engine_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setTextureRect(minus_hp_1);
	}

	if ( counter == 6)
	{
		sf::IntRect minus_hp(0, 154, 248, 72);
		sf::IntRect minus_hp_1(0, 165, 248, 23);

		this->engine_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setTextureRect(minus_hp_1);

	}

	if(counter == 7)
	{
		sf::IntRect minus_hp(0, 154, 248, 72);
		sf::IntRect minus_hp_1(0, 0, 0, 0);

		this->engine_sprite.setTextureRect(minus_hp);
		this->barrier_sprite.setTextureRect(minus_hp_1);
	}
	
	this->counter++;
}   
//




//$$	- Constructor/Deconstructor -	$$
Barricade::Barricade()
{

}
//
Barricade::Barricade(float pos_x_ENG, float pos_y_ENG, float pos_x_BAR, float pos_y_BAR)
{
//@ Constructing barricade
	this->initTexture();
	this->initSprite();
	this->initVariables();

	this->engine_sprite.setPosition(pos_x_ENG, pos_y_ENG);
	this->barrier_sprite.setPosition(pos_x_BAR, pos_y_BAR);
}
//
Barricade::~Barricade()
{

}
//



//$$			- Accessors -			$$
int Barricade::get_hp()
{
	return HP;
}
//
int Barricade::get_barr(int type)
{
	return type;
}
//
int Barricade::GET_time_count_barr_destruction()
{
	return counter;
}
bool Barricade::check_destroyed()
{
	if (counter <= 7)
		return false;

	else
		return true;
}
//
const sf::FloatRect Barricade::getBounds() const
{						   
	return this->barrier_sprite.getGlobalBounds();
}
//
const sf::Vector2f & Barricade::getPos() const
{
	return this->barrier_sprite.getPosition();
}
//



//##			 - UPDATE - 		# */
void Barricade::update()
{
	this->HP++;
	barrier_condition(HP);	
}
//
void Barricade::barr_movement()
{
	this->barrier_sprite.move(0.f, 2.f);
	this->engine_sprite.move(0.f, 2.f);
}
//



//##			 - RENDER - 		# */
void Barricade::render(sf::RenderTarget& target)
{
	target.draw(this->barrier_sprite);
	target.draw(this->engine_sprite);
}
//
