#include "StarFlow.h"



//$$	  - Private Funcs & Vars -	    $$
void StarFlow::initVariables()
{
//@ Initializing star generator timer
	this->particleGenTimerMax = 10.f;
	this->particleGenTimer = this->particleGenTimerMax;
}
//



//$$	- Constructor/Deconstructor -	$$
StarFlow::StarFlow(unsigned int type, float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed, float pointCount, float rad, sf::Color color)
{
//@ Defining a random star (speed,size)
	if (type == 0 || type == 1)
	{
		this->type = type;
		this->particle.setPosition(pos_x, pos_y);
		this->direction.x = 0.f;
		this->direction.y = 1.f;
		this->movementSpeed = 0.6f;
		this->particle.setPointCount(100.f);
		this->particle.setRadius(1.f);
		this->particle.setFillColor(sf::Color::White);
	}
	if (type == 3 || type == 4 || type == 5)
	{
		this->type = type;
		this->particle.setPosition(pos_x, pos_y);
		this->direction.x = 0.f;
		this->direction.y = 1.f;
		this->movementSpeed = 0.7f;
		this->particle.setPointCount(100.f);
		this->particle.setRadius(2.f);
		this->particle.setFillColor(sf::Color::White);
	}
	if (type == 5)
	{
		this->type = type;
		this->particle.setPosition(pos_x, pos_y);
		this->direction.x = 0.f;
		this->direction.y = 1.f;
		this->movementSpeed = 0.8f;
		this->particle.setPointCount(100.f);
		this->particle.setRadius(3.f);
		this->particle.setFillColor(sf::Color::White);
	}

	if (type == 10)
	{
		this->type = type;
		this->particle.setPosition(pos_x, pos_y);
		this->direction.x = dir_X;
		this->direction.y = dir_Y;
		this->movementSpeed = movement_speed;
		this->particle.setPointCount(pointCount);
		this->particle.setRadius(rad);
		this->particle.setFillColor(sf::Color::White);
	}
//@ P.S 
// In order to make stars look better i made smaller stars move slower than the bigger ones
// to create an illusion that the smaller stars are very far away

}
//
StarFlow::StarFlow()
{
	this->initVariables();
}
//
StarFlow::~StarFlow()
{

}
//



//$$			- Accessors -			$$
const sf::FloatRect StarFlow::getBounds() const
{
//@ Getting bounds of star to delete it as it reaches the bottom 
	return this->particle.getGlobalBounds();
}
//
const bool StarFlow::canGenerate() 
{
//@ Can - Generate bool for generator
	if (this->particleGenTimer >=this->particleGenTimerMax)
	{
		this->particleGenTimer = 1.f;
		return true;
	}

	return false;
}
//



//##			 - UPDATE - 		# */
void StarFlow::updateGenerator()
{
//@ Updating the generator timer permissions
	if (this->particleGenTimer < this->particleGenTimerMax)
		this->particleGenTimer += 1.f;
}
//
void StarFlow::update()
{
//@ Updating star's movement
	this->particle.move(movementSpeed * direction);
}
//



//##			 - RENDER - 		# */
void StarFlow::render(sf::RenderTarget * target)
{
	target->draw(this->particle);
}
//
