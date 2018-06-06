/*
* @Author: Reimua
* @Date:   2018-06-06 10:25:30
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-06 10:50:16
*/

#include "SoundManager.hpp"

SoundManager::SoundManager() :
_engine(irrklang::createIrrKlangDevice())
{
	if (_engine == nullptr)
		throw std::runtime_error("Cannot get sound engine");
}

SoundManager::~SoundManager()
{
}

void SoundManager::playSound(std::string s)
{
	_engine->play2D(s.c_str());
}

void SoundManager::playBgm(std::string s)
{
	_engine->play2D(s.c_str(), true);
}