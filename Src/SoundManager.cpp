/*
* @Author: Reimua
* @Date:   2018-06-06 10:25:30
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-06 12:58:44
*/

#include "SoundManager.hpp"

SoundManager::SoundManager() :
_engine(irrklang::createIrrKlangDevice()),
_bgm(nullptr),
_audio(true)
{
	if (_engine == nullptr)
		throw std::runtime_error("Cannot get sound engine");
}

SoundManager::~SoundManager()
{
	_engine->drop();
}

void SoundManager::playSound(std::string s)
{
	irrklang::ISound *sound = _engine->play2D(s.c_str(), false);
	(_audio) ? sound->setVolume(1) : sound->setVolume(0);
}

void SoundManager::stopBgm()
{
	if (_bgm == nullptr)
		return;
	_bgm->stop();
	_bgm->drop();
	_bgm = nullptr;
}

void SoundManager::playBgm(std::string s)
{
	if (_bgm != nullptr)
		this->stopBgm();
	_bgm = _engine->play2D(s.c_str(), true, false, true);
	(_audio) ? _bgm->setVolume(1) : _bgm->setVolume(0);
}

void SoundManager::toggleAudio()
{
	_audio = !_audio;
	if (!(_bgm == nullptr)) {
		(_audio) ? _bgm->setVolume(1) : _bgm->setVolume(0);
	} else {
		// do nothing
	}
}

bool SoundManager::getAudioStatus()
{
	return _audio;
}
