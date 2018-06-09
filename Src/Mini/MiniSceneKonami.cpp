/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneKonami.hpp"

MiniSceneKonami::MiniSceneKonami()
	: MiniScene("Konami")
{
}

MiniSceneKonami::~MiniSceneKonami()
{
}

MiniScene *MiniSceneKonami::clone()
{
	return new MiniSceneKonami();
}

void MiniSceneKonami::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	MiniScene::start(core, audio, video);

	_back = MiniSprite(video->loadTexture("Assets/Sprites/MiniGameBackground.jpg"));
	_back.destination.width = video->getScreenWidth();
	_back.destination.height = video->getScreenHeight();
}

void MiniSceneKonami::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneKonami::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;
	(void)clock;

	if (action->isKeyPressed(irr::KEY_ESCAPE))
		core->pop();
}

void MiniSceneKonami::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
	(void)clock;

	video->drawSprite(_back);
}
