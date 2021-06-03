#include "Sound.h"



void Sound::initMusic_Sound()
{
//---------------------------------------------------------------------------------------------------------------MUSIC

//@ Initializing Music
	if(!this->Music.openFromFile("Attributes/Sounds/music/bg_music.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load music_sound!\n";
	
//---------------------------------------------------------------------------------------------------------------BULLET

//@ Initializing Soundbuffer for player bullet
	if (!this->buffer_main_music.loadFromFile("Attributes/Sounds/player/player_bullet_shot_v2.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load bullet_sound!\n";

//---------------------------------------------------------------------------------------------------------------DAMAGE

//@ Initializing Soundbuffer for damage
	if (!this->buffer_damage.loadFromFile("Attributes/Sounds/damage/damage_v1.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load damage_v1!\n";

	//@ Initializing Soundbuffer for shield damage
	if (!this->buffer_damage_shield.loadFromFile("Attributes/Sounds/damage/shield_damage.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load barricade_damage!\n";

//@ Initializing Soundbuffer for barricade damage
	if (!this->buffer_damage_barricades.loadFromFile("Attributes/Sounds/damage/barricade_damage.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load barricade_damage!\n";

//---------------------------------------------------------------------------------------------------------------DEATH

//@ Initializing Soundbuffer for ufo death
	if (!this->buffer_death_ufo.loadFromFile("Attributes/Sounds/mobs/ufo_death.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load ufo_death!\n";

//@ Initializing Soundbuffer for ds death
	if (!this->buffer_death_ds.loadFromFile("Attributes/Sounds/mobs/ds_death.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load ds_death!\n";

//---------------------------------------------------------------------------------------------------------------UPGRADE
	
//@ Initializing Soundbuffer for upgrade
	if (!this->buffer_upgrade.loadFromFile("Attributes/Sounds/upgrade/upgrade_sound.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load upgrade_sound!\n";

//@ Initializing Soundbuffer for upgrade window
	if (!this->buffer_upgrade_window.loadFromFile("Attributes/Sounds/upgrade/upgrade_initWindow.wav"))
		std::cout << "ERROR::SOUND::INITMUSIC::Failed to load upgrade_initWindow!\n";

//---------------------------------------------------------------------------------------------------------------SETTING UP VOLUME

//@Setting volume
	this->Shot.setVolume(35);

	this->Death.setVolume(20);

	this->Damage.setVolume(10);
	this->Damage_shield.setVolume(55);
	this->Damage_BARR.setVolume(10);

	this->Music.setVolume(90);
}

Sound::Sound()
{
	this->initMusic_Sound();
	this->Music.setLoop(true);
	this->Music.play();
}

Sound::~Sound()
{
}

void Sound::shoot()
{
	Shot.setBuffer(buffer_main_music);
	this->Shot.play();
}

void Sound::damage()
{
	this->Damage.setBuffer(this->buffer_damage);
	this->Damage.play();
}

void Sound::damage_shield()
{
	this->Damage_shield.setBuffer(this->buffer_damage_shield);
	this->Damage_shield.play();
}

void Sound::damage_barricade()
{
	this->Damage_BARR.setBuffer(this->buffer_damage_barricades);
	this->Damage_BARR.play();
}

void Sound::upgrade(bool stage)
{
	if (stage)
	{
		this->Upgrade.setBuffer(this->buffer_upgrade_window);
		this->Upgrade.setVolume(35);

		this->Upgrade.play();
	}

	if (!stage)
	{
		this->Upgrade.setBuffer(this->buffer_upgrade);
		this->Upgrade.setVolume(35);
		this->Upgrade.play();
	}
}

void Sound::enemy_death(int type)
{
	if (type == 2)
	{
		this->Death.setBuffer(this->buffer_death_ufo);
		this->Death.play();
	}

	if (type == 3)
	{
		this->Death.setBuffer(this->buffer_death_ds);
		this->Death.play();
	}
}

void Sound::endgame()
{
	this->Music.stop();
}


