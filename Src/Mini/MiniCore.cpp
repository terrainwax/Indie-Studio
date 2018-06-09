/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniCore.hpp"
#include "MiniActionMgr.hpp"
#include "MiniVideoMgr.hpp"
#include "MiniAudioMgr.hpp"

MiniCore::MiniCore()
	: _running(false)
{
	srand(time(NULL));

	_action = MiniActionMgr();

	_videoDevice = irr::createDevice(CORE_WINDOW_DRIVER,
	irr::core::dimension2d<irr::u32>(CORE_WINDOW_WIDTH, CORE_WINDOW_HEIGHT), CORE_WINDOW_BITS, false, false, false, &_action);

	_audioDevice = irrklang::createIrrKlangDevice();

	_video = MiniVideoMgr(_videoDevice);

	_audio = MiniAudioMgr(_audioDevice);
}

MiniCore::~MiniCore()
{
}

void MiniCore::push(const std::string &sceneName)
{
	MiniScene *scene = _knownScenes[sceneName]->clone();

	scene->start(this, &_audio, &_video);

	_currentScenes.push(scene);
}

void MiniCore::pop()
{
	MiniScene *scene = _currentScenes.top();

	scene->stop(this, &_audio, &_video);

	_currentScenes.pop();
}

void MiniCore::enter()
{
	Clock timeClock;

	while (_currentScenes.size() > 0)
	{
		if (_video.available())
		{
			MiniScene *scene = _currentScenes.top();

			timeClock.tick();

			_video.clear();

			scene->updateFrame(this, &_action, &_audio, timeClock);
			scene->renderFrame(this, &_video, &_audio, timeClock);

			_video.present();

			_action.flush();
		}
		else
			quit();
	}
}

void MiniCore::quit()
{
	while (_currentScenes.size() > 0)
	{
		pop();
	}
}

void MiniCore::add(MiniScene *scene)
{
	if (scene == nullptr)
		throw std::runtime_error("Invalid scene");
	_knownScenes[scene->getName()] = scene;
}

irr::IrrlichtDevice *MiniCore::getVideoDevice()
{
	return _videoDevice;
}

irrklang::ISoundEngine *MiniCore::getAudioDevice()
{
	return _audioDevice;
}

void MiniCore::setPlayers(bool players[PLAYER_NUMBER])
{
	for (std::size_t x = 0; x < PLAYER_NUMBER; x++)
		_players[x] = players[x];
}

bool *MiniCore::getPlayers()
{
	return _players;
}