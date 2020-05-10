/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <map>
#include <deque>
#include "Enum.hpp"

class Music {
    public:
        Music();
        ~Music() = default;

        void playSound(Sounds whatSound);
        void playMusic(Musics whatMusic);
        void setGeneralVolume(int vol);
        void setSoundVolume(int vol);
        void setMusicVolume(int vol);
    private:
        int _generalVolume;
        int _soundVolume;
        int _musicVolume;
        // std::deque<sf::SoundBuffer> _buffers;
        // std::map<Sounds, std::deque<std::unique_ptr<sf::Sound>>> _sounds;
        // std::map<Musics, std::unique_ptr<sf::Music>> _musics;
};

#endif /* !MUSIC_HPP_ */