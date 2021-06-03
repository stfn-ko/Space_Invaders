#include "SCRAP.h"



//$$	  - Private Funcs & Vars -	    $$
void SCRAP::initTexture()
{
//@ Initializing texture for GUI
	if (!this->GUI_texture.loadFromFile("Attributes/Textures/GUI/GUI.png"))
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Failed to load GUI texture!\n";
	}
//@ Initializing texture for point gain index
	if (!this->points_texture.loadFromFile("Attributes/Textures/GUI/POINTS_APPENDIX.png"))
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Failed to load Points texture!\n";
	}
//@ Initializing texture for level up
	if (!this->lvl_up_texture.loadFromFile("Attributes/Textures/GUI/LVL_UP.png"))
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Failed to load LVL texture!\n";
	}

}
//
void SCRAP::initSprite()
{
//@ Initializing sprites for GUI, point gain appendix and level up

//#GUI
	sf::IntRect rectSourceSprite_gui(0, 0, 76, 26);

	this->GUI_sprite.setTexture(this->GUI_texture);

	this->GUI_sprite.setTextureRect(rectSourceSprite_gui);

	this->GUI_sprite.setScale(5.f, 5.f);

//# Point gain appendix
	sf::IntRect rectSourceSprite_points(0, 0, 0, 0);

	this->points_sprite.setTexture(this->points_texture);
		 
	this->points_sprite.setTextureRect(rectSourceSprite_points);
		 
	this->points_sprite.setScale(4.f, 4.f);

//# Level up
	sf::IntRect rectSourceSprite_lvl(0, 0, 0, 0);

	this->lvl_up_sprite.setTexture(this->lvl_up_texture);

	this->lvl_up_sprite.setTextureRect(rectSourceSprite_lvl);

	this->lvl_up_sprite.setScale(4.f, 4.f);
}
//
void SCRAP::initFonts()
{
//@ Initializing font for a poin count etc
	if (!this->font.loadFromFile("Attributes/Fonts/pixelfont.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!\n";
	}
}
//
void SCRAP::initText()
{
//@ HP text
	this->HP_text.setFont(this->font);
	this->HP_text.setCharacterSize(36);
	this->HP_text.setFillColor(sf::Color::Green);
	this->HP_text.setString("5");

//@ Rocket text
	this->SHIELD_text.setFont(this->font);
	this->SHIELD_text.setCharacterSize(36);
	this->SHIELD_text.setFillColor(sf::Color::Green);
	this->SHIELD_text.setString("3");

//@ Points text
	this->POINTS_text.setFont(this->font);
	this->POINTS_text.setCharacterSize(34);
	this->POINTS_text.setFillColor(sf::Color::Green);
	this->POINTS_text.setString("00000000");
}
//



//$$	- Constructor/Deconstructor -	$$
SCRAP::SCRAP(float pos_x, float pos_y, float HP_pos_x, float HP_pos_y, float R_pos_x, float R_pos_y, float P_pos_x, float P_pos_y, float PA_pos_x, float PA_pos_y)
{
//@ Constructing GUI together with the point count and point gain appendix
	this->initTexture();
	this->initSprite();
	this->initFonts();
	this->initText();

	this->GUI_sprite.setPosition(pos_x, pos_y);
	this->lvl_up_sprite.setPosition(PA_pos_x, PA_pos_y + 40.f); 
	this->points_sprite.setPosition(PA_pos_x, PA_pos_y);
	this->HP_text.setPosition(HP_pos_x, HP_pos_y);
	this->SHIELD_text.setPosition(R_pos_x, R_pos_y);
	this->POINTS_text.setPosition(P_pos_x, P_pos_y);
}
//
SCRAP::~SCRAP()
{

}
//



int SCRAP::getCounter(int type)
{
	if (type == 1)
		return pa_counter_type_1;
	if (type == 2)
		return pa_counter_type_2;
	if (type == 3)
		return pa_counter_type_3;
}
//




//##			 - UPDATE - 		# */
void SCRAP::update_text(int type, int count)
{
//@ Updating HP index in GUI
	if(type == 1 && count >= 0)
		this->HP_text.setString(this->hp[count]);

//@ Updating Sheild index
	if (type == 2)
		this->SHIELD_text.setString(this->shield[count]);
}
//
void SCRAP::update_points_text(bool const add_points, int amt_points)
{
//@ Point gain indexation depending on enemy type killed
	if (add_points == true)
	{
		this->score_counter += amt_points;
		this->u_points += amt_points;
		
		if (amt_points == 5)
		{
			sf::IntRect rectSourceSprite_points(0, 0, 21, 9);
			this->points_sprite.setTextureRect(rectSourceSprite_points);	
			this->update(0);
		}
		if (amt_points == 50)
		{
			sf::IntRect rectSourceSprite_points(25, 0, 21, 9);
			this->points_sprite.setTextureRect(rectSourceSprite_points);
			this->update(1);
		}
		if (amt_points == 100)
		{
			sf::IntRect rectSourceSprite_points(52, 0, 22, 9);
			this->points_sprite.setTextureRect(rectSourceSprite_points);
			this->update(2);
		}
	}
//@ Handling point count
	if (GUI_clock_points_counter.getElapsedTime().asSeconds() > 0.15f)
	{
		this->score_counter++;
		this->u_points++;

		this->s_points = "0000000";
		this->s_points += std::to_string(u_points);
		if (std::to_string(u_points).size() == 2)
			s_points.erase(0, 1);
		else if (std::to_string(u_points).size() == 3)
			s_points.erase(0, 1);
		else if (std::to_string(u_points).size() == 4)
			s_points.erase(0, 1);
		else if (std::to_string(u_points).size() == 5)
			s_points.erase(0, 1);
		else if (std::to_string(u_points).size() == 6)
			s_points.erase(0, 1);
		else if (std::to_string(u_points).size() == 7)
			s_points.erase(0, 1);
		else if (std::to_string(u_points).size() == 8)
			s_points.erase(0, 1);

		this->POINTS_text.setString(s_points);

		GUI_clock_points_counter.restart();
	}
}
//
void SCRAP::update_LVL(int num)
{
	if (lvl_counter < 4)
	{
		sf::IntRect rectSourceSprite_lvl(9, 0, 39, 9);
		this->lvl_up_sprite.setTextureRect(rectSourceSprite_lvl);
	}

	sf::IntRect rectSourceSprite_lvl(9, 9 * (lvl_counter - 4), 39, 9);
	this->lvl_up_sprite.setTextureRect(rectSourceSprite_lvl);

	this->lvl_counter++;
	
	if (lvl_counter > 15)
	{
		this->counter_of_game_completion++;

		if (this->counter_of_game_completion == 2)
		{
			if (num % 2 == 0)
			{
				sf::IntRect rectSourceSprite_gui(0, (num/2) * 25, 76, 26);
				this->GUI_sprite.setTextureRect(rectSourceSprite_gui);
			}

			this->counter_of_game_completion = 0;
		}
		

		lvl_counter = 0;
	}
}
//
void SCRAP::update(int type)
{
//@ Updating point gain index depending on enemy type killed
	if (type == 1)
	{
		this->pa_counter_type_1 ++; this->pa_counter_type_2 = 0; this->pa_counter_type_3 = 0;

		sf::IntRect rectSourceSprite_points(0, 9 * (this->pa_counter_type_1 - 1), 21, 9);
		this->points_sprite.setTextureRect(rectSourceSprite_points);

		if (pa_counter_type_1 > 11)
			pa_counter_type_1 = 0;
	}
	if (type == 2)
	{
		this->pa_counter_type_2++; this->pa_counter_type_1 = 0; this->pa_counter_type_3 = 0;

		sf::IntRect rectSourceSprite_points(25, 9 * (this->pa_counter_type_2 - 1), 21, 9);
		this->points_sprite.setTextureRect(rectSourceSprite_points);

		if (pa_counter_type_2 > 11)
			pa_counter_type_2 = 0;
	}
	if (type == 3)
	{
		this->pa_counter_type_3++; this->pa_counter_type_1 = 0; this->pa_counter_type_2 = 0;

		sf::IntRect rectSourceSprite_points(52, 9 * (this->pa_counter_type_3 - 1), 21, 9);
		this->points_sprite.setTextureRect(rectSourceSprite_points);

		if (pa_counter_type_3 > 11)
			pa_counter_type_3 = 0;
	}
}
//



//##			 - RENDER - 		# */
void SCRAP::render(sf::RenderTarget * target)
{
	target->draw(this->GUI_sprite);
	target->draw(this->points_sprite);
	target->draw(this->lvl_up_sprite);
	target->draw(this->HP_text);
	target->draw(this->SHIELD_text);
	target->draw(this->POINTS_text);
}
//