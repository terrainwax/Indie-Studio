/*
* @Author: Reimua
* @Date:   2018-06-06 10:25:30
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-06 12:58:44
*/

#include "SoundManager.hpp"

SoundManager::SoundManager() :
_engine(irrklang::createIrrKlangDevice()),
_bgm(nullptr)
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
	
	_engine->play2D(s.c_str(), false);
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