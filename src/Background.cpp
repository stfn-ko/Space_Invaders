#include "Background.h"




//$$	- Constructor/Deconstructor -	$$
Background::Background(sf::Texture * texture, float x, float y)
{
//@ Constructing a background
	this->sprite.setTexture(*texture);
	this->sprite.setScale(x, y);
	this->sprite.setPosition(0, 0);
}
//
Background::~Background()
{

}
//



//##			 - UPDATE - 		# */
void Background::update()
{
	
}
//



//##			 - RENDER - 		# */
void Background::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}
//
