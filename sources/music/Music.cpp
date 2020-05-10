/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#include <stdexcept>
#include "Music.hpp"

Music::Music()
{
    _engine = irrklang::createIrrKlangDevice();
    _music = true;
    _sound = true;
    if (!_engine)
        throw std::runtime_error("irrklang can't be launched");
}
Music::~Music()
{
    _engine->drop();
}

void Music::playMusic(const std::string& music)
{
    if (_music == true) {
        _engine->stopAllSounds();
        _engine->play2D(music.c_str(), true);
    }
}

void Music::playSound(const std::string& sound)
{
    if (_sound == true) {
        _engine->play2D(sound.c_str(), false);
        if (!_engine)
            throw std::runtime_error("Sound asset not found");
    }
}

void Music::setMusic(bool state)
{
    _music = state;
    if (state == false)
        _engine->stopAllSounds();
}

void Music::setSound(bool state)
{
    _sound = state;
}

void Music::setVol(float value)
{
    _engine->setSoundVolume(value);
}
