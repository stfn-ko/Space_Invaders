#ifndef SOUND_H
#define SOUND_H

/// Includes
#include <iostream>

#include <SFML/Audio.hpp>

/// Class
class Sound
{//$$			 - Private -			$$
private:
//	SoundBuffers				%
	sf::SoundBuffer buffer_main_music;

	sf::SoundBuffer buffer_damage;
	sf::SoundBuffer buffer_damage_shield;
	sf::SoundBuffer buffer_damage_barricades;

	sf::SoundBuffer buffer_upgrade;
	sf::SoundBuffer buffer_upgrade_window;

	sf::SoundBuffer buffer_death_ufo;
	sf::SoundBuffer buffer_death_ds;

//	Music					    %
	sf::Music Music;

//	Sounds						%
	sf::Sound Shot;
	sf::Sound Damage;
	sf::Sound Damage_BARR;
	sf::Sound Damage_shield;
	sf::Sound Upgrade;
	sf::Sound Death;

// Private Functions			%
	void initMusic_Sound();

//&&		 - End of Private -			&&



//$$		     - Public -				$$
public:
	Sound();
	~Sound();

	void shoot();
	void damage();
	void damage_shield();
	void damage_barricade();
	void upgrade(bool stage);
	void enemy_death(int type);
	void endgame();

};//&&		 - End of Public -			&&

#endif //!SOUND_H
