#include "Game.h"


//-//-//-//-//		$$		- Private Functions -		$$ //TODO: ADD LASERS TO THE ENEMIES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//@	Initializig Window
void Game::initWindow()
{
//# Create a new window using options from a window.ini file

	std::ifstream ifs("Config/window.ini.txt");

	std::string title = "None";
	sf::VideoMode window_bounds(1600, 1300);
	unsigned framerate_limit = 144;
	bool veritical_sync_enabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> veritical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds,
	title, sf::Style::Titlebar
	| sf::Style::Close);

//# Set the FPS limit
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(veritical_sync_enabled);

}

//@ Initializing bullets
void Game::initTextures()
{
//# Set textures for Bullets
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Attributes/Textures/PLAYER/SHOT_Player_bullet.png");
	
	this->textures["ENEMY_UFO_BULLET"] = new sf::Texture();
	this->textures["ENEMY_UFO_BULLET"]->loadFromFile("Attributes/Textures/ENEMY/bullet_ufo.png");

	this->textures["ENEMY_DS_BULLET"] = new sf::Texture();
	this->textures["ENEMY_DS_BULLET"]->loadFromFile("Attributes/Textures/ENEMY/bullet_ds.png");
}

//@ Initializing default background
void Game::initBackground()
{
//# Using texture map to assign key values for a background change
	this->m_backgrounds[0] = new sf::Texture();
	this->m_backgrounds[0]->loadFromFile("Attributes/Textures/BG/BG_frame_0.png");
	this->m_backgrounds[1] = new sf::Texture();
	this->m_backgrounds[1]->loadFromFile("Attributes/Textures/BG/BG_frame_1.png");
	this->m_backgrounds[2] = new sf::Texture();
	this->m_backgrounds[2]->loadFromFile("Attributes/Textures/BG/BG_frame_2.png");
	this->m_backgrounds[3] = new sf::Texture();
	this->m_backgrounds[3]->loadFromFile("Attributes/Textures/BG/BG_frame_3.png");
	this->m_backgrounds[4] = new sf::Texture();
	this->m_backgrounds[4]->loadFromFile("Attributes/Textures/BG/BG_frame_4.png");
	this->m_backgrounds[5] = new sf::Texture();
	this->m_backgrounds[5]->loadFromFile("Attributes/Textures/BG/BG_frame_5.png");
	this->m_backgrounds[6] = new sf::Texture();
	this->m_backgrounds[6]->loadFromFile("Attributes/Textures/BG/BG_frame_6.png");
	this->m_backgrounds[7] = new sf::Texture();
	this->m_backgrounds[7]->loadFromFile("Attributes/Textures/BG/BG_frame_7.png");
	this->m_backgrounds[8] = new sf::Texture();
	this->m_backgrounds[8]->loadFromFile("Attributes/Textures/BG/BG_frame_8.png");
	this->m_backgrounds[9] = new sf::Texture();
	this->m_backgrounds[9]->loadFromFile("Attributes/Textures/BG/BG_frame_9.png");
	this->m_backgrounds[10] = new sf::Texture();
	this->m_backgrounds[10]->loadFromFile("Attributes/Textures/BG/BG_frame_10.png");
	this->m_backgrounds[11] = new sf::Texture();
	this->m_backgrounds[11]->loadFromFile("Attributes/Textures/BG/BG_frame_11.png");
	this->m_backgrounds[12] = new sf::Texture();
	this->m_backgrounds[12]->loadFromFile("Attributes/Textures/BG/BG_frame_12.png");
	this->m_backgrounds[13] = new sf::Texture();
	this->m_backgrounds[13]->loadFromFile("Attributes/Textures/BG/BG_frame_13.png");
	this->m_backgrounds[14] = new sf::Texture();
	this->m_backgrounds[14]->loadFromFile("Attributes/Textures/BG/BG_frame_14.png");
	this->m_backgrounds[15] = new sf::Texture();
	this->m_backgrounds[15]->loadFromFile("Attributes/Textures/BG/BG_frame_15.png");
	this->m_backgrounds[16] = new sf::Texture();
	this->m_backgrounds[16]->loadFromFile("Attributes/Textures/BG/BG_frame_16.png");
	this->m_backgrounds[17] = new sf::Texture();
	this->m_backgrounds[17]->loadFromFile("Attributes/Textures/BG/BG_frame_17.png");
	
//# Default starting bg texture
	this->v_backgrounds.push_back(new Background(this->m_backgrounds[0], this->window->getSize().x / 600.f, this->window->getSize().y / 600.f));
}

//@ Initializing star flow model
void Game::initStarFlow()
{
//# Creating a new default star particle
	this->star = new StarFlow;
	this->stars.push_back(new StarFlow(10, rand() % this->window->getSize().x, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, sf::Color::White));
}

//@ Initializng GUI & Level
void Game::initGUI()
{
//# Creating a new default GUI
	this->GUI = new SCRAP(2.f, 2.f, 190.f, 28.f, 320.f, 28.f, 105.f, 120.f, 270.f, 150.f);

	this->newLVL_MAX = 500;
}

//@ Initializing new barricade
void Game::initBarricade()
{
	for (size_t i = 25; i < 1076; i += 525)
		this->v_barricades.push_back(new Barricade(i, this->window->getSize().y - 360, i - 1, this->window->getSize().y - 338));
}

//@ Initializing music and sounds
void Game::initSounds()
{
	this->sound = new Sound();
}

// Initializing upgrade (buffs)
void Game::initUPG()
{
	this->UPG = new Upgrade();
}

//@ Initializing game state
void Game::initState()
{
	this->state = new GameState();
}

//@ Initializing new player  
void Game::initPlayer()
{
	this->player = new Player();
//# Set default starting position
	this->player->setPos(this->window->getSize().x - (this->window->getSize().x) / 2 - player->getSize(), 
	this->window->getSize().y - (player->getSize()) * 2);
}

//@ Initializing enemies (Spawn times)
void Game::initEnemies()
{
//# Spawn timers

//## Spawn timer for a bug
	this->spawnTimerBugMAX = 220.f;
	this->spawnTimerBug = spawnTimerBugMAX;
//## Spawn timer for an ufo
	this->spawnTimerUfoMAX = 2000.f;
	this->spawnTimerUfo = 0;
//## Spawn timer for a Dragon ship
	this->spawnTimerDsMAX = 5000.f;
	this->spawnTimerDs = 0;
}



//-//-//-//-/*		# - Constructor/Deconstructor - # */

//@ Constructing all the initializers
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initBackground();
	this->initStarFlow();
	this->initGUI();
	this->initUPG();
	this->initState();
	this->initBarricade();
	this->initSounds();
	this->initPlayer();
	this->initEnemies();
}

//@ Deconstructing all the initializers
Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->GUI;
	delete this->sound;
	delete this->UPG;
	delete this->state;
	
//# Delete textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}
//# Delete dynamic bg textures
	for (auto &i : this->m_backgrounds)
	{
		delete i.second;
	}
//# Delete bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}

	for (auto *i : this->v_backgrounds)
	{
		delete i;
	}
//# Delete particles
	for (auto *i : this->stars)
	{
		delete i;
	}
//# Delete enemies
	for (auto *i : this->enemies)
	{
		delete i;
	}
//# Delete barricades
	for (auto *i : this->v_barricades)
	{
		delete i;
	}
}



//-//-//-//-//$$		- Public Functions -		$$

//@ Game run process
void Game::run() 
{
	while (this->window->isOpen())
	{
		this->updateDT();
		this->update();
		this->render();
	}
}

//@ Get size of the screen
void Game::getSize()
{
	this->window->getSize();
}




//-//-//-//-//*		 #		  - UPDATE - 		 # */

//@ Update poll events
void Game::updatePollEvents()
{
	sf::Event Session;
	while (this->window->pollEvent(Session))
	{
		if (Session.Event::type == sf::Event::Closed || Session.key.code == sf::Keyboard::Escape || this->state->exit_bool)
				this->window->close();
		
		if (this->state->play_bool) {
			this->window->close();
			this->sound->endgame();
			this->state->play_bool = false;
			Game game;
			game.run();
		}
	}
}

//@ Checking conditions for the endgame
void Game::checkEnding()
{
	// Close window if player is dead
	if (this->player->get_HP() <= 0)
	{
		this->endgame = true;
		this->winState = false;
	}

	// Close window if player win (Lvl. 10)
	if (this->lvl_num >= 10)
	{
		this->endgame = true;
		this->winState = true;
	}
}

//@ Updating delta time 
void Game::updateDT()
//# Gives you the amount of time spent on update + render
{
	dt = this->DT_CLOCK.restart().asSeconds();

//	std::cout << this->dt << "\n";
}

void Game::updateEndState()
{
	if (winState)
	{
		this->state->update(sf::Vector2f(this->window->getSize().x, this->window->getSize().y), this->winState);
		this->sound->endgame();
	}
	else
	{
		this->state->update(sf::Vector2f(this->window->getSize().x, this->window->getSize().y), this->winState);
		this->sound->endgame();
	}
}

//@ Update if any input (fex: creating bullets & player movement)
void Game::updateInput() 
{

//# Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (this->player->getBounds().left < 0)
		{
			this->player->setPos(this->window->getSize().x, this->player->getPos().y);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->player->move(-0.72f, 0.f);
		
		else
		this->player->move(-1.f, 0.f);
	}
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (this->player->getBounds().left > this->window->getSize().x)
		{
			this->player->setPos(- this->player->getBounds().width, this->player->getPos().y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			this->player->move(0.72f, 0.f);

		else
			this->player->move(1.f, 0.f);
	}

//# Shoot a bullet
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
	{
		this->amount_count_bullet;

		if ((this->amount_count_bullet + 1) % 2)
			this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 45.f, this->player->getPos().y - 15.f, 0.f, -1.f, 3.7f));

		else
			this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 69.f, this->player->getPos().y - 15.f, 0.f, -1.f, 3.7f));

		this->amount_count_bullet++;

		if (this->amount_count_bullet == 10)
			this->amount_count_bullet = 0;

		this->sound->shoot();
	}
}

//@ Udpate GUI
void Game::updateGUI()
{
//# Set the point count text to 0000000
	this->GUI->update_points_text(false, 0); //Default value

//# Display the "level up" sign whenever player reaches a new level (watch line ___ @ upgrade)
	if (this->GUI_clock_LVLUP_counter.getElapsedTime().asMilliseconds() > 70.f && level_up)
	{
		this->GUI->update_LVL(this->lvl_num);
		this->GUI_clock_LVLUP_counter.restart();
		this->time_count_GUI_LVL_UP++;
	}

	if (this->time_count_GUI_LVL_UP > this->GUI->lvl_counter)
	{
		this->time_count_GUI_LVL_UP = 0;
		this->level_up = false;
	}

//# Display the point gain index when killing enemy
	if (this->GUI_clock_appendix_counter.getElapsedTime().asMilliseconds() > 60.f && enemy_hit)
	{
		this->GUI->update(this->points_appendix_index);
		this->GUI_clock_appendix_counter.restart();
		this->time_count_GUI_PA++;
	
	}
//## Dont display the point gain if enemy not hit
	if (this->time_count_GUI_PA > this->GUI->getCounter(this->points_appendix_index))
	{
		this->time_count_GUI_PA = 0;
		this->enemy_hit = false;
	}
}

//@ Update bullets
void Game::updateBullets()
{
	unsigned counter = 0;

	for (auto *bullet : this->bullets)
	{
		bullet->update();

//# Bullet culling (top of screen)
		if(bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{ 
//# Delete bullet
			delete this->bullets.at(counter);

//## Erase bullet from vector
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}

	unsigned counter_1 = 0;

	for (auto *bullet : this->enemy_bullets)
	{
		bullet->update();
		
//# Bullet culling (top of screen)
		for (size_t i = 0; i < 3; i++)
		{
			if (bullet->getBounds(i).top + bullet->getBounds().height > this->window->getSize().y)
			{
				//# Delete bullet
				delete this->enemy_bullets.at(counter_1);

				//## Erase bullet from vector
				this->enemy_bullets.erase(this->enemy_bullets.begin() + counter_1);
				--counter_1;
			}
		}
		++counter_1;
	}
}

//@ Update dynamic background
void Game::updateBackground()
{

//# Proceed background change until reach riching the last texture 
//##(this is done to sync bg and beginning of star flow /(void updateStars)/))

//## Stop the fucntion if dark_screen == true
	if (BG_clock.getElapsedTime().asSeconds() >= 0.6f && !dark_screen)
	{

		this->v_backgrounds.push_back(new Background(this->m_backgrounds[this->time_count_BG], this->window->getSize().x / 600.f, this->window->getSize().y / 600.f));
		this->time_count_BG++;

		BG_clock.restart();
		
		if (this->time_count_BG == 17)
			dark_screen = true;
	}

}

//@ Generate dynamic background elements
void Game::genStars()
{
	int type = rand() % 6;

	this->star->updateGenerator();

	if (this->star->canGenerate())
	{
//# Generating a random particle(star)
		this->stars.push_back(new StarFlow(type, rand() % this->window->getSize().x, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, sf::Color::White));
	}
}

//@ Update dynamic background & its elements and delete them when out of screen
void Game::updateStars()
{
	unsigned counter = 0;

	for (auto *particle : this->stars)
	{
		particle->update();

//# Particle culling (top of screen)
		if (particle->getBounds().top > static_cast<float>(window->getSize().y))
		{

//## Delete particle
			delete this->stars.at(counter);

//## Erase star from vector
			this->stars.erase(this->stars.begin() + counter);
			--counter;
		}
		++counter;
	}
}

//@ Update and kill enemies + (BARRICADES)
void Game::updateEnemies_and_Combat()
{
	bool enemy_bullet_removed = false;

//# Updating spawn timers
	this->spawnTimerBug += 1.f;
	this->spawnTimerUfo += 1.f;
	this->spawnTimerDs += 1.f;

	if (this->spawnTimerBug >= spawnTimerBugMAX)
	{
		this->enemies.push_back(new Enemy(16.f, 0, rand() % (this->window->getSize().x - 320) + 160.f, -200.f, 1));
		this->spawnTimerBug = 0;
		this->enemy_type.push_back(1);
	}

	if (this->spawnTimerUfo >= spawnTimerUfoMAX)
	{
		this->enemies.push_back(new Enemy(57.5f, 0, rand() % (this->window->getSize().x - 420) + 210.f, -250.f, 2));
		this->spawnTimerUfo = 0;
		this->enemy_type.push_back(2);
	}

	if (this->spawnTimerDs >= spawnTimerDsMAX)
	{
		this->enemies.push_back(new Enemy(80.5f, 0, rand() % (this->window->getSize().x - 359) + 1.f, -400.f, 3));
		this->spawnTimerDs = 0;
		this->enemy_type.push_back(3);
	}

//# Delete enemies
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_removed = false;
		this->enemies[i]->update();

//# Update enemy movement
		if (this->enemies[i]->getPos().y > 200.f && this->enemy_type[i] != 1 && this->enemies[i]->getDir().x == 0)
		{
			this->enemies[i]->change_dir(sf::Vector2f(this->enemies[i]->getDefaultDir(this->enemy_type[i]).y, 0.f));
		}

		if (this->enemies[i]->getPos().x < 0.f)
		{
			this->enemies[i]->change_dir(sf::Vector2f(this->enemies[i]->getDefaultDir(this->enemy_type[i]).y, 0.f));
		}

		if (this->enemies[i]->getPos().x > this->window->getSize().x - this->enemies[i]->getBounds().width)
		{
			this->enemies[i]->change_dir(sf::Vector2f(this->enemies[i]->getDefaultDir(this->enemy_type[i]).y * -1, 0.f));
		}

//# Create enemy bullets
		if (this->enemies[i]->canAttack())
		{
			if (enemy_type[i] == 2)
			{
 				this->enemy_bullets.push_back(new Bullet(this->textures["ENEMY_UFO_BULLET"], sf::Vector2f(this->enemies[i]->getPos().x + this->enemies[i]->getBounds().width / 2, this->enemies[i]->getPos().y + this->enemies[i]->getBounds().height / 2), sf::Vector2f(0.f, 1.f), sf::Vector2f(3.f, 3.f), 2.f, false));
			}
			
			if (enemy_type[i] == 3)
			{
				this->enemy_bullets.push_back(new Bullet(this->textures["ENEMY_DS_BULLET"], sf::Vector2f(this->enemies[i]->getPos().x + this->enemies[i]->getBounds().width / 2, this->enemies[i]->getPos().y + this->enemies[i]->getBounds().height / 2), sf::Vector2f(0.f, 1.f), sf::Vector2f(5.f, 5.f), 1.5f, true));
			}
		}

//## Delete enemy if hit and dead
		for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				if (damage_check == 0)
				{
					this->enemies[i]->loose_hp(this->player->getDMG());
					this->enemies[i]->update_hp_bar(this->enemy_type[i], this->enemies[i]->getHp());
					this->sound->damage();
					this->bullets.erase(this->bullets.begin() + k);

//					std::cout << this->enemies[i]->getHp() << "\n";		//Check
				}
				
				damage_check++;

				if (this->enemies[i]->getHp() >= this->enemies[i]->getHpMax())
				{
//### Play death sound
					this->sound->enemy_death(this->enemy_type[i]);
//### Update points count if enemy is killed
					this->GUI->update_points_text(true, this->enemy->get_points(this->enemy_type[i]));
//#### Display points appendix defining how many points player gained (look up func at line ___ /(void updateGUI)/)
					this->enemy_hit = true;
					this->points_appendix_index = this->enemy_type[i];
//### Remove enemies when hit with a bullet
					this->enemies.erase(this->enemies.begin() + i);  
//### Update enemy type vector
					this->enemy_type.erase(this->enemy_type.begin() + i);

					enemy_removed = true;
				}
					damage_check = 0;
			}
		}

//## Remove enemies at the bottom of the screen
		if (!enemy_removed)
		{
			if (this->enemies[i]->getBounds().top > window->getSize().y)
			{
				this->enemies.erase(this->enemies.begin() + i);

//### Update enemy type vector
				this->enemy_type.erase(this->enemy_type.begin() + i);
//### Update health in the SCRAP
				this->updatePollEvents();
				this->GUI->update_text(1, this->player->minus_HP());
				enemy_removed = true;
			}
		}

//## Delte if enemy hits the player
		for (size_t k = 0; k < this->enemies.size() && !enemy_removed; k++)
		{
			if (this->enemies[k]->getBounds().intersects(this->player->getBounds()))
			{
				this->enemies.erase(this->enemies.begin() + i);
				this->sound->damage();

//### Update enemy type vector
				this->enemy_type.erase(this->enemy_type.begin() + i);
//### Update health in the SCRAP
				this->updatePollEvents();
				this->GUI->update_text(1, this->player->minus_HP());
				enemy_removed = true;
			}
		}

//## Delte if enemy hits the barricade

		for (size_t j = 0; j < this->v_barricades.size() && !enemy_removed; j++)
		{
			if (this->enemies[i]->getBounds().intersects(this->v_barricades[j]->getBounds()))
			{
//### Update Barrier
				this->v_barricades[j]->update();

//### Play death sound
				this->sound->damage_barricade();
//### Deleting enemy from vector
				this->enemies.erase(this->enemies.begin() + i);
//### Update enemy type vector
				this->enemy_type.erase(this->enemy_type.begin() + i);
				enemy_removed = true;
			}
				
		}
	}


	for (size_t k = 0; k < this->enemy_bullets.size(); k++)
	{
//## Remove enemy bullet if it collides with player's bullet 
	
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < this->bullets.size() && !enemy_bullet_removed; j++)
			{
				if (this->bullets[j]->getBounds().intersects(this->enemy_bullets[k]->getBounds(i)))
				{
					this->bullets.erase(this->bullets.begin() + j);
					this->enemy_bullets.erase(this->enemy_bullets.begin() + k);
					enemy_bullet_removed = true;
				}
			}
		}
	
//# Damage player with bullets
		for (size_t i = 0; i < 3; i++)
		{
			if (!enemy_bullet_removed)
			{
					if (this->enemy_bullets[k]->getBounds(i).intersects(this->player->getBounds()))
					{
					this->updatePollEvents();
					this->sound->damage();

					if (this->player->get_Shield() > 0)
					{
						this->GUI->update_text(2, this->player->minus_Shield());
						this->sound->damage_shield();
					}
					else
						this->GUI->update_text(1, this->player->minus_HP());

					this->enemy_bullets.erase(this->enemy_bullets.begin() + k);
					enemy_bullet_removed = true;
					}
			}
		}
	}
}

//@ Update and destroy barricades
void Game::updateBarricades()
{
	for (int i = 0; i < v_barricades.size(); i++)	
	{
		//# Displaying barier's collapsion  
		if (this->collapse_clock.getElapsedTime().asSeconds() > 0.2f && this->v_barricades[i]->get_hp() >= 3 && !this->v_barricades[i]->check_destroyed())
		{
			this->v_barricades[i]->barrier_collapse();
			this->collapse_clock.restart();
		}
	
//# Making barricades gradually descened towards bottom of the screen when HP = 0
		if (this->v_barricades[i]->GET_time_count_barr_destruction() >= 7 && remove_barr_clock.getElapsedTime().asSeconds() > 0.15f)
		{
//##	Remove barrier at the bottom of the screen 
			if (this->v_barricades[i]->getBounds().top > window->getSize().y)
				this->v_barricades.erase(this->v_barricades.begin() + i);

			else
				this->v_barricades[i]->barr_movement();
		}
	}
}

//@ Upgrade player when lvl_up^
void Game::upgrade()
{
	if (!this->upgrade_time)
	{
		if (!this->endgame)
		{
			this->updateInput();
			this->updateBullets();
			this->player->update();
			this->updateEnemies_and_Combat();
			this->updateGUI();
		}

		this->updateBackground();
		this->genStars();
		this->updateBarricades();
		this->updateStars();
	}

//# Get Buff log while game paused
	if (this->upgrade_time)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (this->Upgrade_CLOCK.getElapsedTime().asMilliseconds() > 40.f)
			{
				this->UPG->update(1, this->window->getSize().x / 2 + 120.f, this->window->getSize().y / 2 + 140.f);
				this->Upgrade_CLOCK.restart();
			}

			if (this->UPG->upg_counter_right >= 35) //
			{
				this->time_count_upgrade = 0;
				this->UPG->upg_counter_right = 0;
				this->player->upgradeSpeed();
				this->UPG->hide();
				this->upgrade_time = false;
				this->sound->upgrade(this->upgrade_time);
			}
		} 

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{	
			if (this->Upgrade_CLOCK.getElapsedTime().asMilliseconds() > 40.f)
			{
				this->UPG->update(0, this->window->getSize().x / 2 - 330.f, this->window->getSize().y / 2 + 140.f);
				this->Upgrade_CLOCK.restart();
			}

			if (this->UPG->upg_counter_left >= 35) //
			{
				this->time_count_upgrade = 0;
				this->UPG->upg_counter_left = 0;
				this->player->upgradeShootingSpeed();
				this->UPG->hide();
				this->upgrade_time = false;
				this->sound->upgrade(this->upgrade_time);
			}
		}

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->UPG->update(-1, 0, 0);
		}
	}

//# Increase difficulty (spawn more  enemies per second)
	if (this->GUI->score_counter >= this->newLVL_MAX)
	{
		this->lvl_num++;

		this->spawnTimerBugMAX -= 8.f;
		this->spawnTimerUfoMAX -= 70.f;
		this->spawnTimerDsMAX -= 195.f;

		this->level_up = true;
		this->updateGUI();

		this->GUI->score_counter = this->GUI->score_counter - this->newLVL_MAX;
		
		
		this->UPG = new Upgrade(this->window->getSize().x / 2 - 460.f, this->window->getSize().y / 2 - 460.f, this->window->getSize().x / 2 - 310.f, this->window->getSize().y / 2 - 260.f);
		this->upgrade_time = true;
		this->sound->upgrade(this->upgrade_time);
	}
}

//@ UPDATE
void Game::update()
{
	this->updatePollEvents();
	this->upgrade();
	this->checkEnding();

	if (this->endgame)
	{
		this->updateEndState();
	}
}

//-//-//-//-//*		#		 - RENDER - 		# */

//@ RENDER
void Game::render()
{
	this->window->clear();

//# Set background
	for (auto *bg : this->v_backgrounds)
		{bg->render(this->window);}

//# Draw all the stuff
	
	for (auto *particle : this->stars)
		{particle->render(this->window);}

	for (auto *barricade : this->v_barricades)
		{barricade->render(*this->window);}

	for (auto *bullet : this->enemy_bullets)
		{bullet->render(this->window);}
	
	for (auto *enemy : this->enemies)
		{enemy->render(*this->window);}
	
	this->GUI->render(this->window);

	this->player->render(*this->window);

	for (auto *bullet : this->bullets)
		{bullet->render(this->window);}

	this->UPG->render(this->window);

	this->state->render(this->window);
	
	this->window->display();
}
//