/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniAudioMgr.hpp"

MiniAudioMgr::MiniAudioMgr()
	: _audioDevice(nullptr)
{

}

MiniAudioMgr::MiniAudioMgr(irrklang::ISoundEngine *audioDevice)
	: _audioDevice(audioDevice)
{
	if (_audioDevice == nullptr)
		throw std::runtime_error("Invalid audioDevice");
	setMasterVolume(AUDIO_MAX_VOLUME);
}

MiniAudioMgr::~MiniAudioMgr()
{
	setMasterVolume(AUDIO_MIN_VOLUME);
	_audioDevice = nullptr;
}

void MiniAudioMgr::playSound(std::string soundFile)
{
	_audioDevice->play2D(soundFile.c_str());
}

void MiniAudioMgr::playMusic(std::string musicFile)
{
	_audioDevice->play2D(musicFile.c_str(), true);
}

float MiniAudioMgr::getMasterVolume()
{
	return _audioDevice->getSoundVolume();
}

void MiniAudioMgr::setMasterVolume(float masterVolume)
{
	if (masterVolume > AUDIO_MAX_VOLUME || masterVolume < AUDIO_MIN_VOLUME)
		throw std::runtime_error("Invalid masterVolume");
	_audioDevice->setSoundVolume(masterVolume);
}

void MiniAudioMgr::play()
{
	_audioDevice->setAllSoundsPaused(false);
}

void MiniAudioMgr::pause()
{
	_audioDevice->setAllSoundsPaused(true);
}

void MiniAudioMgr::clear()
{
	_audioDevice->stopAllSounds();
}
