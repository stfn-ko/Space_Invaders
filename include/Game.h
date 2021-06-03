#ifndef GAME_H
#define GAME_H

/// Includes
#include <fstream>
#include <sstream>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Barricade.h"
#include "Background.h"
#include "StarFlow.h"
#include "SCRAP.h"
#include "Sound.h"
#include "Upgrade.h"
#include "GameState.h"

/// Class
class Game

{//$$			 - Private -			$$			@
private:

//	Window -R								@
	sf::RenderWindow* window;

//	Resourses								@
	std::map<std::string, sf::Texture*> textures; //Bullet textures map
	std::vector<Bullet*> bullets; //Vector storing bullets
	std::vector<Bullet*> enemy_bullets; //Vector storing enemy bullets
	sf::Clock DT_CLOCK; // Delta clock
	float dt; // Delta Time





//-----------------------------------------------
//$$		- Private Packets -		    $$		%

//	Player						%
	Player* player;

// Enemies						%
	Enemy* enemy;

	std::vector<Enemy*>enemies;
	std::vector<int>enemy_type;

	float spawnTimerBug; //Spawn timers \/
	float spawnTimerBugMAX;
	float spawnTimerUfo;
	float spawnTimerUfoMAX;
	float spawnTimerDs;		
	float spawnTimerDsMAX; 
	
// GUI						    %
	SCRAP* GUI;

	float newLVL_MAX; 

	sf::Clock GUI_clock_appendix_counter; 
	sf::Clock GUI_clock_LVLUP_counter;

// Background					%
	Background* BG;

	sf::Clock BG_clock; 
	std::map<int, sf::Texture*> m_backgrounds;
	std::vector<Background*> v_backgrounds;

// Dynamic Background			%
	StarFlow* star;

	std::vector<StarFlow*> stars;

// Sounds and Music
	Sound* sound;

// Barricade					%
	Barricade* barricade;

	std::vector<Barricade*> v_barricades;

	sf::Clock collapse_clock;
	sf::Clock remove_barr_clock;
								  
// Upgrade						 %
	Upgrade* UPG;
	sf::Clock Upgrade_CLOCK;

// Game state					 %
	GameState* state;

//$$	  - End of Private Packets -	 $$	   %
//-----------------------------------------------





// Private Functions					 @
	void initWindow();
	void initTextures();
	void initBackground();
	void initStarFlow();
	void initGUI();
	void initBarricade();
	void initSounds();
	void initUPG();
	void initState();

	void initPlayer();
	void initEnemies();

//&&		 - End of Private -			&&			@





//$$		     - Public -				$$			@
public:

// Constructor & Deconstructor			  @
	Game();
	virtual ~Game();

// Variables and counters				  @
	int amount_count_bullet = 0;
	int damage_check = 0;

	int barr_num = 0;						
	int lvl_num = 0;

	int time_count_BG = 0;
	int time_count_GUI_PA = 0;
	int time_count_GUI_LVL_UP = 0;
	int time_count_upgrade = 0;
	
	int points_appendix_index = 0;

	bool dark_screen = false;
	bool enemy_hit = false;
	bool level_up = false;
	bool upgrade_time = false;
	bool endgame = false;
	bool winState = false;

//	Functions							  @
	void run();
	void getSize();

//	Program U-R							  @
	void checkEnding();

// -U  %
	void updatePollEvents();
	void updateDT();
	void updateEndState();
	void updateInput();
	void updateGUI();
	void updateBackground();
	void genStars();
	void updateBullets();
	void updateStars();
	void updateEnemies_and_Combat();
	void updateBarricades();
	void upgrade();
	void update();

// -R  %
	void render();

};//&&	- End of Public Functions -		&&			@

#endif //!GAME_H