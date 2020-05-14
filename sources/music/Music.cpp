/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#include <stdexcept>
#include "Core.hpp"
#include "Music.hpp"

Music::Music()
{
    _engine = irrklang::createIrrKlangDevice();
    _master = true;
    _music = true;
    _sfx = true;
    if (!_engine)
        throw std::runtime_error("irrklang can't be launched");
    defaultVolume();
}
Music::~Music()
{
    _engine->drop();
}

void Music::defaultVolume()
{
    irrklang::ISoundSource *shootSound = _engine->addSoundSourceFromFile("resources/sfx/click.mp3");

    shootSound->setDefaultVolume(0.2);
}

void Music::playMusic(const std::string &music)
{
    if (_music == true) {
        _engine->stopAllSounds();
        _engine->play2D(music.c_str(), true);
    }
}

void Music::playSound(const std::string &sound)
{
    if (_sfx == true) {
        _engine->play2D(sound.c_str(), false);
        if (!_engine)
            throw std::runtime_error("Sound asset not found");
    }
}

void Music::pause()
{
	_engine->setAllSoundsPaused(true);
}

void Music::resume()
{
	_engine->setAllSoundsPaused(false);
}