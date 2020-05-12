/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <map>
#include <memory>
#include <deque>
#include <irrKlang.h>
#include "Enum.hpp"

class Music {
    public:
        Music();
        ~Music();

    void setMusic(bool);
    void setSound(bool);
    void playMusic(const std::string &);
    void playSound(const std::string &);
    void setVol(float);
        // void playSound(Sounds whatSound);
        // void playMusic(Musics whatMusic);
        // void setGeneralVolume(int vol);
        // void setSoundVolume(int vol);
        // void setMusicVolume(int vol);
    private:
        //int _generalVolume;
        bool _music;
        bool _sound;
        irrklang::ISoundEngine *_engine;
};

#endif /* !MUSIC_HPP_ */