#include "GameState.h"




//$$	  - Private Funcs & Vars -	    $$
void GameState::initTextures()
{
	if (!this->shade_texture.loadFromFile
	("Attributes/Textures/EndState/shade.png"))
		std::cout << "ERROR::GAMESTATE::INITTEXTURE::Failed to load shade texture!\n";

	if (!this->end_tx_win.loadFromFile
	("Attributes/Textures/EndState/You-Win.png"))
		std::cout << "ERROR::GAMESTATE::INITTEXTURE::Failed to load loose texture!\n";

	if (!this->end_tx_loose.loadFromFile
	("Attributes/Textures/EndState/Game-Over.png"))
		std::cout << "ERROR::GAMESTATE::INITTEXTURE::Failed to load win texture!\n";

	if (!this->exit_play_select.loadFromFile
	("Attributes/Textures/EndState/exit_play-again.png"))
		std::cout << "ERROR::GAMESTATE::INITTEXTURE::Failed to load select texture!\n";

	if (!this->interface_texture.loadFromFile
	("Attributes/Textures/EndState/Background.png"))
		std::cout << "ERROR::GAMESTATE::INITTEXTURE::Failed to load background texture!\n";
}
//
void GameState::initSprites()
{
	this->shade_sprtie.setTexture(this->shade_texture);
	this->shade_sprtie.setTextureRect(sf::IntRect(0.f, 0.f, 0.f, 0.f));
	this->shade_sprtie.setScale(20.f, 20.f);

	this->interface_sprite.setTexture(this->interface_texture);
	this->interface_sprite.setScale(0.f, 0.f);

	this->exit.setTexture(this->exit_play_select);
	this->exit.setTextureRect(sf::IntRect(0.f, 0.f, 0.f, 0.f));
	this->exit.setScale(7.f, 7.f);

	this->play.setTexture(this->exit_play_select);
	this->play.setTextureRect(sf::IntRect(0.f, 0.f, 0.f, 0.f));
	this->play.setScale(7.f, 7.f);

	this->end_sprite.setScale(4.f, 4.f);
}
//



//$$	- Constructor/Deconstructor -	$$
GameState::GameState()
{
	this->initTextures();
	this->initSprites();
}
//
GameState::~GameState()
{
}
//



//## 			- U-R -				# */
void GameState::update(sf::Vector2f screensize, bool ending)
{

	if (this->conter_counter == 7)
	{
		this->interface_sprite.setScale(4.f, 4.f);

		if (ending)
		{
			this->end_sprite.setTexture(end_tx_win);
			this->end_sprite.setPosition(4.f, 7.f);
		}
		else
		{
			this->end_sprite.setTexture(end_tx_loose);
			this->end_sprite.setPosition(4.f, 7.f);
		}

		if (! this->isHighlighted)
		{
			this->exit.setTextureRect(sf::IntRect(0.f, 0.f, 44.f, 22.f));
			this->exit.setPosition(808.f,984.f);


			this->play.setTextureRect(sf::IntRect(45.f, 0.f, 44.f, 22.f));
			this->play.setPosition(458.f, 984.f);
		}

		
	
//-----------------------------------------------------------------------------------------------------------------//PRESS RIGHT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->right = true;
			this->isHighlighted = true;
			this->play.setTextureRect(sf::IntRect(45.f, 0.f, 44.f, 22.f));
			this->exit.setTextureRect(sf::IntRect(0.f, 23.f, 44.f, 22.f)); // choose exit sign to the right
		}


//-----------------------------------------------------------------------------------------------------------------//PRESS LEFT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			right = false;
			this->isHighlighted = true;
			this->exit.setTextureRect(sf::IntRect(0.f, 0.f, 44.f, 22.f));
			this->play.setTextureRect(sf::IntRect(45.f, 23.f, 44.f, 22.f)); // choose play sign to the left
		}


//-----------------------------------------------------------------------------------------------------------------//PRESS ENTER
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && right)
		{
			this->exit.setTextureRect(sf::IntRect(0.f, 46.f, 44.f, 22.f)); // press exit sign to the right
			this->exit_bool = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !right)
		{
			this->play.setTextureRect(sf::IntRect(45.f, 46.f, 44.f, 22.f)); //  press play sign to the left
			this->play_bool = true;
		}
	}

	if (this->animation_clock.getElapsedTime().asSeconds() > 0.10f && this->conter_counter < 7)
	{
		this->conter_counter ++;
	
		if(this->conter_counter >= 0)
			this->shade_sprtie.setTextureRect(sf::IntRect(0.f, 65.f * this->conter_counter, 80.f, 65.f));
			
		this->animation_clock.restart();
	}
	
}
//
void GameState::render(sf::RenderTarget * target)
{
	target->draw(this->shade_sprtie);
	target->draw(this->interface_sprite);
	target->draw(this->end_sprite);
	target->draw(this->exit);
	target->draw(this->play);

}
//