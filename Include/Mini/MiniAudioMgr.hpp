/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IMiniAudioMgr.hpp"

class MiniAudioMgr final : public IMiniAudioMgr {
public:
	MiniAudioMgr();
	MiniAudioMgr(irrklang::ISoundEngine *audioDevice);
	~MiniAudioMgr() override;

	void playSound(std::string soundFile) override;
	void playMusic(std::string musicFile) override;

	void setMasterVolume(float masterVolume) override;
	float getMasterVolume() override;

	void play() override;
	void pause() override;
	void clear() override;

private:
	irrklang::ISoundEngine	*_audioDevice;
};
