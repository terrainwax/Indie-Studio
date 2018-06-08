/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneOptions.hpp"

MiniSceneOptions::MiniSceneOptions()
	: MiniScene("Options"), _choice(0)
{

}

MiniSceneOptions::~MiniSceneOptions()
{
}

MiniScene *MiniSceneOptions::clone()
{
	return new MiniSceneOptions();
}

void MiniSceneOptions::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	MiniScene::start(core, audio, video);

	// Add code here
	_audio = MiniSprite(video->loadTexture("Assets/Menus/OptionsMenuAudio.jpg"));
	_back = MiniSprite(video->loadTexture("Assets/Menus/OptionsMenuBack.jpg"));
	_ok = MiniSprite(video->loadTexture("Assets/Menus/OK.jpg"));
	_ko = MiniSprite(video->loadTexture("Assets/Menus/KO.jpg"));
}

void MiniSceneOptions::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneOptions::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;

	if (action->isKeyPressed(irr::KEY_RETURN))
	{
		if (_choice == 0)
		{
			if (audio->getMasterVolume() > 0.0f)
				audio->setMasterVolume(0.0f);
			else
				audio->setMasterVolume(1.0f);

		}
		if (_choice == 1)
			core->pop();
	}

	if (action->isKeyPressed(irr::KEY_UP))
		_choice = (2 + (-1) + _choice) % 2;

	if (action->isKeyPressed(irr::KEY_DOWN))
		_choice = (2 + (+1) + _choice) % 2;

	if (action->isKeyPressed(irr::KEY_ESCAPE))
		core->pop();
}

void MiniSceneOptions::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;

	MiniSprite sprite = (_choice == 0) ? _audio : _back;
	sprite.destination.width = video->getScreenWidth();
	sprite.destination.height = video->getScreenHeight();
	video->drawSprite(sprite);

	MiniSprite check = (audio->getMasterVolume() > 0.0f) ? _ok : _ko;
	check.destination.x = video->getScreenWidth() * 0.535f;
	check.destination.y = video->getScreenHeight() * 0.21f;
	check.destination.width = video->getScreenWidth() * 0.029f;
	check.destination.height = video->getScreenHeight() * 0.04f;
	video->drawSprite(check);
}