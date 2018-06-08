/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IMiniAudioMgr.hpp"

#define AUDIO_MIN_VOLUME 0.0f
#define AUDIO_MAX_VOLUME 0.1f

class MiniAudioMgr final : public IMiniAudioMgr {
public:
	MiniAudioMgr();
	MiniAudioMgr(irrklang::ISoundEngine *audioDevice);
	~MiniAudioMgr() override;

	void playSound(std::string soundFile, float soundVolume) override;
	void playMusic(std::string musicFile, float musicVolume) override;

	void setMasterVolume(float masterVolume) override;
	float getMasterVolume() override;

	void play() override;
	void pause() override;
	void clear() override;

private:
	irrklang::ISoundEngine	*_audioDevice;
};
