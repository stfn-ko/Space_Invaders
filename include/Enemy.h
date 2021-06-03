#ifndef ENEMY_H
#define ENEMY_H

///Includes
#include <iostream>

#include <SFML/Graphics.hpp>

/// Class
class Enemy

{//$$			 - Private -			$$
private:

//	Textures/Sprites/Shapes     %
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Texture HP_texture;
	sf::Sprite HP_sprite;

//	Varibles		            %
	int hp;
	sf::Vector2f movement;
	int hpMax;
	int type;

	float attackCoolDownMax;
	float attackCoolDown = this->attackCoolDownMax;

// Private Functions			%
	void initTexture(int type);
	void initSprite(int type);
	void initVariables(int type);
	
//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:
	Enemy(float hp_x, float hp_y, float pos_x, float pos_y, unsigned type);
	~Enemy();

// Public Functions				%
	void loose_hp(int damage);
	void change_dir(sf::Vector2f direction);

//	Accessors					%
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getDir() const;
	const bool canAttack();
	const int getHp() const;
	const int getHpMax() const;
	int get_points(int type);
	sf::Vector2f getDefaultDir(int type);

//	Program U-R                 %
	void update_hp_bar(int type, int hp);
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};//&&		 - End of Public -			&&




#endif //!ENEMY_H