/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniBase.hpp"

class IMiniAudioMgr {
public:
	IMiniAudioMgr() = default;
	virtual ~IMiniAudioMgr() = default;

	virtual void playSound(std::string soundFile, float soundVolume) = 0;
	virtual void playMusic(std::string musicFile, float musicVolume) = 0;

	virtual void setMasterVolume(float masterVolume) = 0;
	virtual float getMasterVolume() = 0;

	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void clear() = 0;
};
