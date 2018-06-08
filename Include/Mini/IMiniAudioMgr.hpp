/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniBase.hpp"

#define AUDIO_MIN_VOLUME 0.0f
#define AUDIO_MAX_VOLUME 1.0f

class IMiniAudioMgr {
public:
	IMiniAudioMgr() = default;
	virtual ~IMiniAudioMgr() = default;

	virtual void playSound(std::string soundFile) = 0;
	virtual void playMusic(std::string musicFile) = 0;

	virtual void setMasterVolume(float masterVolume) = 0;
	virtual float getMasterVolume() = 0;

	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void clear() = 0;
};
