/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneKonami.hpp"

MiniSceneKonami::MiniSceneKonami()
	: MiniScene("Konami", true, false)
{
	_gameEnded = false;
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
	audio->playMusic(GAME_MUSIC);

	_back = MiniSprite(video->loadTexture("Assets/Sprites/MiniGameBackground.jpg"));
	_back.destination.width = video->getScreenWidth();
	_back.destination.height = video->getScreenHeight();

	_playerWhite = MiniSprite(video->loadTexture("Assets/Sprites/Bomberman.png"));

	_playerWhite.destination.x = video->getScreenWidth() / 2;
	_playerWhite.destination.y = video->getScreenHeight() / 2;
	_playerWhite.destination.width *= 4;
	_playerWhite.destination.height *= 4;
}

void MiniSceneKonami::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneKonami::playersMovements(IMiniActionMgr *action)
{
	if (action->isKeyDown(irr::KEY_UP)) {
		_playerWhite.destination.y -= 10;
	}
	else if (action->isKeyPressed(irr::KEY_DOWN)) {
		_playerWhite.destination.y += 10;
	}
	else if (action->isKeyDown(irr::KEY_LEFT)) {
		_playerWhite.destination.x -= 10;
	}
	else if (action->isKeyDown(irr::KEY_RIGHT)) {
		_playerWhite.destination.x += 10;
	}
}

void MiniSceneKonami::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;
	(void)clock;

	if (action->isKeyPressed(irr::KEY_ESCAPE) || isGameEnded()) {
		audio->clear();
		audio->playMusic(MENU_MUSIC);
		core->pop();
	}
	playersMovements(action);
}

void MiniSceneKonami::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
	(void)clock;

	_back.destination.width = video->getScreenWidth();
	_back.destination.height = video->getScreenHeight();

	video->drawSprite(_back);
	video->drawSprite(_playerWhite);
}

bool MiniSceneKonami::isGameEnded()
{
	return _gameEnded;
}
