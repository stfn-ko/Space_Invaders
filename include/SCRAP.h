#ifndef SCRAP_H
#define SCRAP_H
//Screen appendix

/// Includes
#include <iostream>

#include <SFML/Graphics.hpp>

/// Class
class SCRAP
{//$$			 - Private -			$$
private:

	//	Textures/Sprites/Shapes     %
	sf::Texture GUI_texture;
	sf::Texture points_texture;
	sf::Texture lvl_up_texture;

	sf::Sprite GUI_sprite;
	sf::Sprite points_sprite;
	sf::Sprite lvl_up_sprite;

	//	Fonts and Text		        %
	sf::Font font;
	sf::Text HP_text;
	sf::Text SHIELD_text;
	sf::Text POINTS_text;

	// Clocks and counters			%
	sf::Clock GUI_clock_points_counter;
	int counter_of_game_completion = 0;

	//	Varibles		            %
	unsigned u_points = 0;
	std::string s_points;

	int pa_counter_type_1 = 1;
	int pa_counter_type_2 = 1;
	int pa_counter_type_3 = 1;
	
	std::vector<std::string> hp = { "0", "1", "2", "3", "4", "5"};
	std::vector<std::string> shield = {"0","1","2","3"};

// Private Functions			%
	void initTexture();
	void initSprite();
	void initFonts();
	void initText();

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:
	SCRAP(float pos_x, float pos_y, float HP_pos_x, float HP_pos_y, float R_pos_x, float R_pos_y, float P_pos_x, float P_pos_y, float PA_pos_x, float PA_pos_y);
	~SCRAP();

// Clocks and counters			%
	int lvl_counter = 1;
	float score_counter = 0;
	
// Accessors					%
	int getCounter(int type);

//	Program U-R                 %
	void update_text(int type, int count);
	void update_points_text(bool const add_points, int amt_points);
	void update_LVL(int num);
	void update(int type);
	void render(sf::RenderTarget* target);
	
};//&&		 - End of Public -			&&

#endif //!SCRAP_H
