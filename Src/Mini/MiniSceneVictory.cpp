/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneVictory.hpp"

MiniSceneVictory::MiniSceneVictory()
	: MiniScene("Victory")
{
}

MiniSceneVictory::~MiniSceneVictory()
{
}

MiniScene *MiniSceneVictory::clone()
{
	return new MiniSceneVictory();
}

void MiniSceneVictory::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	MiniScene::start(core, audio, video);

	audio->clear();
	// audio->playSound(VICTORY);

	_images[0] = MiniSprite(video->loadTexture("Assets/Menus/VictoryNoobs.jpg"));
	_images[1] = MiniSprite(video->loadTexture("Assets/Menus/VictoryPlayerOne.jpg"));
	_images[2] = MiniSprite(video->loadTexture("Assets/Menus/VictoryPlayerTwo.jpg"));
	_images[3] = MiniSprite(video->loadTexture("Assets/Menus/VictoryPlayerThree.jpg"));
	_images[4] = MiniSprite(video->loadTexture("Assets/Menus/VictoryPlayerFour.jpg"));
}

void MiniSceneVictory::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneVictory::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;
	(void)clock;

	if (action->isKeyPressed(irr::KEY_RETURN)) {
		audio->playMusic(MENU_MUSIC);
		core->pop();
	}

	if (action->isKeyPressed(irr::KEY_ESCAPE)) {
		audio->playMusic(MENU_MUSIC);
		core->pop();
	}
}

void MiniSceneVictory::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
	(void)clock;

	MiniSprite sprite = _images[core->getWinner()];
	sprite.destination.width = video->getScreenWidth();
	sprite.destination.height = video->getScreenHeight();
	video->drawSprite(sprite);
}
