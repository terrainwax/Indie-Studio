/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneIntro.hpp"

MiniSceneIntro::MiniSceneIntro()
	: MiniScene("Intro")
{
}

MiniSceneIntro::~MiniSceneIntro()
{
}

MiniScene *MiniSceneIntro::clone()
{
	return new MiniSceneIntro();
}

void MiniSceneIntro::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	MiniScene::start(core, audio, video);

	// Add code here
	audio->playSound(OPENING);
	audio->playMusic(MENU_MUSIC);
	audio->setMasterVolume(AUDIO_MAX_VOLUME);
	_blue = MiniSprite(video->loadTexture(INTRO_BLUE));
	_red  = MiniSprite(video->loadTexture(INTRO_RED));
}

void MiniSceneIntro::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneIntro::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;
	(void)clock;

	if (action->isKeyPressed(irr::KEY_RETURN)) {
		audio->playSound(TRANSITION);
		core->push("Menu");
	}

	if (action->isKeyPressed(irr::KEY_ESCAPE))
		core->pop();
}

void MiniSceneIntro::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
	(void)clock;

	MiniSprite sprite = (clock.elapsedMilliseconds() % 1000 > 500) ? _blue : _red;
	sprite.destination.width = video->getScreenWidth();
	sprite.destination.height = video->getScreenHeight();
	video->drawSprite(sprite);
}
