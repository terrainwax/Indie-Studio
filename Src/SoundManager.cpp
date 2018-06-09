/*
* @Author: Reimua
* @Date:   2018-06-06 10:25:30
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-07 20:28:11
*/

#include "SoundManager.hpp"

SoundManager::SoundManager() :
_engine(nullptr),
_bgm(nullptr),
_audio(false)
{
}

SoundManager::SoundManager(irrklang::ISoundEngine *engine, bool audio) :
_engine(engine),
_bgm(nullptr),
_audio(audio)
{
}

SoundManager::~SoundManager()
{
	_engine->drop();
}

void SoundManager::playSound(std::string s)
{
	irrklang::ISound *sound = _engine->play2D(s.c_str(), false);
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
}