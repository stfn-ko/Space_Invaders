#include "Upgrade.h"

void Upgrade::initVariables()
{
	this->upg_counter_left = 0;
	this->upg_counter_right = 0;
}

void Upgrade::initTextures()
{
	if (!this->texture_window.loadFromFile
	("Attributes/Textures/Upgrade/upgrade_spr_v2.png"))
		std::cout << "ERROR::UPGRADE::INITTEXTURE::Failed to load texture of window!\n";

	if (!this->texture_buff.loadFromFile
	("Attributes/Textures/Upgrade/Buffs_v2.png"))
		std::cout << "ERROR::UPGRADE::INITTEXTURE::Failed to load texture of buff!\n";

	if (!this->vingnette_t.loadFromFile
	("Attributes/Textures/Upgrade/Vingnette.png"))
		std::cout << "ERROR::UPGRADE::INITTEXTURE::Failed to load texture of buff!\n";
}

void Upgrade::initSprites()
{
	sf::IntRect int_rect(0, 0, 92, 92);
	this->sprite_window.setTexture(this->texture_window);
	this->sprite_window.setTextureRect(int_rect);
	this->sprite_window.setScale(10.f, 10.f);

	sf::IntRect int_rect_arrow(0, 0, 0, 0);
	this->arrow.setTexture(this->texture_window);
	this->arrow.setTextureRect(int_rect_arrow);
	this->arrow.setScale(10.f, 10.f);

	sf::IntRect int_rect_left(0, 0, 17, 16);
	this->sprite_buff_left.setTexture(this->texture_buff);
	this->sprite_buff_left.setTextureRect(int_rect_left);
	this->sprite_buff_left.setScale(10.f, 10.f);

	sf::IntRect int_rect_right(17, 0, 17, 16);
	this->sprite_buff_right.setTexture(this->texture_buff);
	this->sprite_buff_right.setTextureRect(int_rect_right);
	this->sprite_buff_right.setScale(10.f, 10.f);

	this->vingnette_s.setTexture(this->vingnette_t);
	this->vingnette_s.setScale(4.f, 4.f);
	this->vingnette_s.setPosition(0.f, 0.f);
}

Upgrade::Upgrade()
{

}

Upgrade::Upgrade(float pos_x, float pos_y, float pos_buff_x, float pos_buff_y)
{
	this->initVariables();
	this->initTextures();
	this->initSprites();

	this->sprite_window.setPosition(pos_x, pos_y);
	this->sprite_buff_left.setPosition(pos_buff_x, pos_buff_y);
	this->sprite_buff_right.setPosition(pos_buff_x + 460.f, pos_buff_y);
}

Upgrade::~Upgrade()
{

}

void Upgrade::hide()
{
	sf::IntRect null (0, 0, 0, 0);

	this->sprite_buff_left.setTextureRect(null);
	this->sprite_buff_right.setTextureRect(null);
	this->sprite_window.setTextureRect(null);
	this->arrow.setTextureRect(null);
	this->vingnette_s.setTextureRect(null);
}

void Upgrade::update(int side, float pos_x, float pos_y)
{
	if (side == 0) //left arrow
	{
		if (upg_counter_left == 0)
		{this->counter_switch = 0; this->y_coord = 0; }
		if (this->counter_switch > 2)
		{this->counter_switch = 0; }
		this->upg_counter_right = 0;
		

		this->sprite_window.setTextureRect(sf::IntRect(0.f, 93.f, 92.f, 92.f));
		this->arrow.setPosition(pos_x, pos_y);
		sf::IntRect left(94 + (23 * this->counter_switch), this->y_coord, 21, 22);
		if (left.left == 140)
		{
			/*left.left = 94;*/
			y_coord += 23;
		}
		this->arrow.setTextureRect(left);

		this->counter_switch++;
		this->upg_counter_left++;
	}
	
	if (side == 1) //right arrow
	{
		if (upg_counter_right == 0)
		{this->counter_switch = 0; this->y_coord = 0; }
		if (this->counter_switch > 2)
		{this->counter_switch = 0; }
		this->upg_counter_left = 0;


		this->sprite_window.setTextureRect(sf::IntRect(0.f, 186.f, 92.f, 90.f));
		this->arrow.setPosition(pos_x, pos_y);
		sf::IntRect right(94 + (23 * this->counter_switch), this->y_coord, 21, 22);
		if (right.left == 140)
		{
			/*right.left = 94;*/
			y_coord += 23;
		}
		this->arrow.setTextureRect(right);

		this->counter_switch++;
		this->upg_counter_right++;
	}

	if (side == -1)
	{
		this->sprite_window.setTextureRect(sf::IntRect(0, 0, 92.f, 92.f));
		this->arrow.setTextureRect(sf::IntRect(0, 0, 0, 0));
		this->upg_counter_left = 0;
		this->upg_counter_right = 0;
	}
}

void Upgrade::render(sf::RenderTarget* target)
{
	target->draw(this->vingnette_s);
	target->draw(this->sprite_window);
	target->draw(this->sprite_buff_left);
	target->draw(this->sprite_buff_right);
	target->draw(this->arrow);
}
