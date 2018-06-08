/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneMenu.hpp"

MiniSceneMenu::MiniSceneMenu()
	: MiniScene("Menu"), _choice(0)
{

}

MiniSceneMenu::~MiniSceneMenu()
{
}

MiniScene *MiniSceneMenu::clone()
{
	return new MiniSceneMenu();
}

void MiniSceneMenu::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	MiniScene::start(core, audio, video);

	// Add code here
	_start = MiniSprite(video->loadTexture(GAME_MENU_START));
	_options = MiniSprite(video->loadTexture(GAME_MENU_OPTIONS));
	_exit = MiniSprite(video->loadTexture(GAME_MENU_EXIT));
}

void MiniSceneMenu::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneMenu::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;

	if (action->isKeyPressed(irr::KEY_RETURN))
	{
		if (_choice == 0) {
			audio->playSound(TRANSITION);
			core->push("Players");
		}
		if (_choice == 1) {
			audio->playSound(TRANSITION);
			core->push("Options");
		}
		if (_choice == 2)
			core->quit();
	}

	if (action->isKeyPressed(irr::KEY_UP)) {
		audio->playSound(NOCK);
		_choice = (3 + (-1) + _choice) % 3;
	}

	if (action->isKeyPressed(irr::KEY_DOWN)) {
		audio->playSound(NOCK);
		_choice = (3 + (+1) + _choice) % 3;
	}

	if (action->isKeyPressed(irr::KEY_ESCAPE)) {
		audio->playSound(OPENING);
		core->pop();
	}
}

void MiniSceneMenu::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;

	MiniSprite sprite = (_choice == 0) ? _start : ((_choice == 1) ? _options : _exit);
	sprite.destination.width = video->getScreenWidth();
	sprite.destination.height = video->getScreenHeight();
	video->drawSprite(sprite);
}
