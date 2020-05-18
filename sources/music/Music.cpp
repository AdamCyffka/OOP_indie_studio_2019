/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Music
*/

#include <iostream>
#include "MusicException.hpp"
#include "Music.hpp"

Music::Music()
{
	_engine = irrklang::createIrrKlangDevice();
	_engine->setSoundVolume(0.3);
}

Music::~Music()
{
	destroySounds();
	_engine->drop();
}

void Music::add2D(const std::string &filename, bool loop, bool startPaused, bool track, irrklang::E_STREAM_MODE mode, bool enableSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (startPaused && !track)
		track = true;
	if (enableSFX) {
		_sfx[filename] = _engine->play2D(filename.c_str(), loop, startPaused, track, mode, enableSFX);
		if ((track || startPaused || enableSFX) && _sfx[filename] == nullptr)
			throw MusicException("sfx object doesn't exist");
	} else {
		_musics[filename] = _engine->play2D(filename.c_str(), loop, startPaused, track, mode, enableSFX);
		if ((track || startPaused || enableSFX) && _musics[filename] == nullptr)
			throw MusicException("music object doesn't exist");
	}
}

void Music::add3D(const std::string &filename, const irrklang::vec3df &vec, bool loop, bool startPaused, bool track, irrklang::E_STREAM_MODE mode, bool enableSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (startPaused && !track)
		track = true;
	if (enableSFX) {
		_sfx[filename] = _engine->play3D(filename.c_str(), vec, loop, startPaused, track, mode, enableSFX);
		if ((track || startPaused || enableSFX) && _sfx[filename] == nullptr)
			throw MusicException("sfx object doesn't exist");
	} else {
		_musics[filename] = _engine->play3D(filename.c_str(), vec, loop, startPaused, track, mode, enableSFX);
		if ((track || startPaused || enableSFX) && _musics[filename] == nullptr)
			throw MusicException("music object doesn't exist");
	}
}

bool Music::isFinished(const std::string &filename, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (isSFX) {
		if (_sfx[filename])
			_sfx[filename]->isFinished();
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			_musics[filename]->isFinished();
		else
			throw MusicException("music object doesn't exist");
	}
	return true;
}

bool Music::getPause(const std::string &filename, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (isSFX) {
		if (_sfx[filename])
			_sfx[filename]->getIsPaused();
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			_musics[filename]->getIsPaused();
		else
			throw MusicException("music object doesn't exist");
	}
	return true;
}

void Music::setPause(const std::string &filename, bool state, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (isSFX) {
		if (_sfx[filename])
			_sfx[filename]->setIsPaused(state);
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			_musics[filename]->setIsPaused(state);
		else
			throw MusicException("music object doesn't exist");
	}
}

void Music::stop(const std::string &filename, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (isSFX) {
		if (_sfx[filename])
			_sfx[filename]->stop();
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			_musics[filename]->stop();
		else
			throw MusicException("music object doesn't exist");
	}
}

void Music::set3DRadiusMin(const std::string &filename, irrklang::ik_f32 dist, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (isSFX) {
		if (_sfx[filename])
			_sfx[filename]->setMinDistance(dist);
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			_musics[filename]->setMinDistance(dist);
		else
			throw MusicException("music object doesn't exist");
	}
}

void Music::set3DRadiusMax(const std::string &filename, irrklang::ik_f32 dist, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (isSFX) {
		if (_sfx[filename])
			_sfx[filename]->setMaxDistance(dist);
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			_musics[filename]->setMaxDistance(dist);
		else
			throw MusicException("music object doesn't exist");
	}
}

void Music::setListenerPosition(irrklang::vec3df pos, irrklang::vec3df target)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	_engine->setListenerPosition(pos, target);
}

void Music::enableSoundEffect(const std::string &filename, musicNs::effect effect, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	irrklang::ISoundEffectControl *fx = nullptr;
	if (isSFX) {
		if (_sfx[filename])
			fx = _sfx[filename]->getSoundEffectControl();
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			fx = _musics[filename]->getSoundEffectControl();
		else
			throw MusicException("music object doesn't exist");
	}
	if (!fx)
		throw MusicException("music object cannot have special effects");
	switch (effect) {
	case musicNs::chorus:
		fx->enableChorusSoundEffect();
		break;
	case musicNs::compressor:
		fx->enableCompressorSoundEffect();
		break;
	case musicNs::distortion:
		fx->enableDistortionSoundEffect();
		break;
	case musicNs::echo:
		fx->enableEchoSoundEffect();
		break;
	case musicNs::flanger:
		fx->enableFlangerSoundEffect();
		break;
	case musicNs::gargle:
		fx->enableGargleSoundEffect();
		break;
	case musicNs::thirdDimensionReverb:
		fx->enableI3DL2ReverbSoundEffect();
		break;
	case musicNs::paramEq:
		fx->enableParamEqSoundEffect();
		break;
	case musicNs::wavesReverb:
		fx->enableWavesReverbSoundEffect();
		break;
	}
}

void Music::disableSoundEffect(const std::string &filename, musicNs::effect effect, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	irrklang::ISoundEffectControl *fx = nullptr;
	if (isSFX) {
		if (_sfx[filename])
			fx = _sfx[filename]->getSoundEffectControl();
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			fx = _musics[filename]->getSoundEffectControl();
		else
			throw MusicException("music object doesn't exist");
	}
	if (!fx)
		return; // TODO THROW
	switch (effect) {
	case musicNs::chorus:
		fx->disableChorusSoundEffect();
		break;
	case musicNs::compressor:
		fx->disableCompressorSoundEffect();
		break;
	case musicNs::distortion:
		fx->disableDistortionSoundEffect();
		break;
	case musicNs::echo:
		fx->disableEchoSoundEffect();
		break;
	case musicNs::flanger:
		fx->disableFlangerSoundEffect();
		break;
	case musicNs::gargle:
		fx->disableGargleSoundEffect();
		break;
	case musicNs::thirdDimensionReverb:
		fx->disableI3DL2ReverbSoundEffect();
		break;
	case musicNs::paramEq:
		fx->disableParamEqSoundEffect();
		break;
	case musicNs::wavesReverb:
		fx->disableWavesReverbSoundEffect();
		break;
	}
}

void Music::masterUp()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	_engine->setSoundVolume(_engine->getSoundVolume() + VOLUME_DIFF);
	if (_engine->getSoundVolume() > 1.0f)
		_engine->setSoundVolume(1.0f);
	setSoundVolume();
}

void Music::musicUp()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	_musicVolume += VOLUME_DIFF;
	if (_musicVolume > 1.0f)
		_musicVolume = 1.0f;
	setSoundVolume();
}

void Music::sfxUp()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	_sfxVolume += VOLUME_DIFF;
	if (_sfxVolume > 1.0f)
		_sfxVolume = 1.0f;
	setSoundVolume();
}

void Music::masterDown()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	_engine->setSoundVolume(_engine->getSoundVolume() - VOLUME_DIFF);
	if (_engine->getSoundVolume() < 0.0f)
		_engine->setSoundVolume(0.0f);
	setSoundVolume();
}

void Music::musicDown()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	_musicVolume -= VOLUME_DIFF;
	if (_musicVolume < 0.0f)
		_musicVolume = 0.0f;
	setSoundVolume();
}

void Music::sfxDown()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	_sfxVolume -= VOLUME_DIFF;
	if (_sfxVolume < 0.0f)
		_sfxVolume = 0.0f;
	setSoundVolume();
}

void Music::setSoundVolume()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	for (auto &it : _musics) {
		it.second->setVolume(_musicVolume);
	}
	for (auto &it : _sfx) {
		it.second->setVolume(_sfxVolume);
	}
}

irrklang::ISound *Music::getSound(const std::string &filename, bool isSFX)
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	if (isSFX) {
		if (_sfx[filename])
			return _sfx[filename];
		else
			throw MusicException("sfx object doesn't exist");
	} else {
		if (_musics[filename])
			return _musics[filename];
		else
			throw MusicException("music object doesn't exist");
	}
}

void Music::destroySounds()
{
	if (!_engine) {
		throw MusicException("Irkklang device doesn't exist");
	}
	for (auto &it : _musics) {
		if (it.second) {
			it.second->drop();
		}
	}
	for (auto &it : _sfx) {
		if (it.second) {
			it.second->drop();
		}
	}
}
