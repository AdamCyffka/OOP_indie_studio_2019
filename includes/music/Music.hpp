/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <string>
#include <map>
#include <memory>
#include <deque>
#include <irrKlang.h>

class Music {
    public:
        Music();
        ~Music();

    void playMusic(const std::string &);
    void playSound(const std::string &);
    void pause();
    void resume();
    void defaultVolume();
    // masterVolumeUp();
    // masterVolumeDown();
    // musicVolumeUp();
    // musicVolumeDown();
    // sfxVolumeUp();
    // sfxVolumeDown();
    private:
        bool _master;
        bool _music;
        bool _sfx;
        irrklang::ISoundEngine *_engine;
};

#endif /* !MUSIC_HPP_ */