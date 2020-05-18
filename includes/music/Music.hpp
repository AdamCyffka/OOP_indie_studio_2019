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
#include <irrKlang.h>

#define VOLUME_DIFF 0.05f

namespace musicNs {
	enum effect {
		chorus,
		compressor,
		distortion,
		echo,
		flanger,
		gargle,
		thirdDimensionReverb,
		paramEq,
		wavesReverb
	};
}

class Music {
public:
	Music();
    ~Music();

    void add2D(const std::string &, bool loop = false, bool startPaused = false, bool track = true, irrklang::E_STREAM_MODE = irrklang::ESM_AUTO_DETECT, bool enableSFX = false);
	void add3D(const std::string &, const irrklang::vec3df& vec, bool loop = false, bool startPaused = false, bool track = true, irrklang::E_STREAM_MODE = irrklang::ESM_AUTO_DETECT, bool enableSFX = false);

	bool isFinished(const std::string &, bool isSFX);
	bool getPause(const std::string &, bool isSFX);
	void setPause(const std::string &, bool state, bool isSFX);
	void stop(const std::string &, bool isSFX);

	void set3DRadiusMin(const std::string &, irrklang::ik_f32, bool isSFX);
	void set3DRadiusMax(const std::string &, irrklang::ik_f32, bool isSFX);

	void setListenerPosition(irrklang::vec3df pos, irrklang::vec3df target);

	void enableSoundEffect(const std::string &, musicNs::effect effect, bool isSFX);
	void disableSoundEffect(const std::string &, musicNs::effect effect, bool isSFX);

	void masterUp();
	void musicUp();
	void sfxUp();
	void masterDown();
	void musicDown();
	void sfxDown();

	void setSoundVolume();

	irrklang::ISound *getSound(const std::string &, bool isSFX);

   	private:
		void destroySounds();
		irrklang::ik_f32 _musicVolume = 0.5f;
		irrklang::ik_f32 _sfxVolume = 0.5f;
		std::map<std::string, irrklang::ISound *> _musics;
    	std::map<std::string, irrklang::ISound *> _sfx;
    	irrklang::ISoundEngine *_engine;
};

#endif /* !MUSIC_HPP_ */