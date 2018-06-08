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

void MiniCore::enter(const std::string &sceneName)
{
	MiniScene *scene = _knownScenes[sceneName];

	_currentScenes.push(scene);

	scene->start(this);

	while (scene->isRunning())
	{
		scene->updateFrame(this, &_action, &_audio);
		scene->renderFrame(this, &_video, &_audio);
	}
}

void MiniCore::quit()
{
	while (_currentScenes.size() > 0)
	{
		MiniScene *scene = _currentScenes.top();
		_currentScenes.pop();

		scene->stop(this);
	}
}

void MiniCore::add(MiniScene *scene)
{
	if (scene == nullptr)
		throw std::runtime_error("Invalid scene");
	_knownScenes[scene->getName()] = scene;
}