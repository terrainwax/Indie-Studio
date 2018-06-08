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

void MiniAudioMgr::playSound(std::string soundFile, float soundVolume)
{
	if (soundVolume > AUDIO_MAX_VOLUME || soundVolume < AUDIO_MIN_VOLUME)
		throw std::runtime_error("Invalid soundVolume");
	irrklang::ISound *sound = _audioDevice->play2D(soundFile.c_str());
	sound->setVolume(soundVolume);
}

void MiniAudioMgr::playMusic(std::string musicFile, float musicVolume)
{
	if (musicVolume > AUDIO_MAX_VOLUME || musicVolume < AUDIO_MIN_VOLUME)
		throw std::runtime_error("Invalid musicVolume");
	irrklang::ISound *music = _audioDevice->play2D(musicFile.c_str(), true);
	music->setVolume(musicVolume);
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
