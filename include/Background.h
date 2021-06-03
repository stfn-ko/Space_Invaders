#ifndef  BACKGROUND_H
#define  BACKGROUND_H

/// Includes
#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>

/// Class
class Background
{//$$			 - Private -			$$
private:

//	Textures/Sprites/Shapes     %
	sf::Texture Texture;
	sf::Sprite sprite;

//	Varibles		            %
	std::map<int, sf::Texture*> m_backgrounds;



//&&		 - End of Private -			&&



//$$		     - Public -				$$

public:
	Background(sf::Texture * texture, float x, float y);
	~Background();


	
//	Program U-R                 %
	void update();
	void render(sf::RenderTarget * target);
};

#endif // !BACKGROUND_H 


