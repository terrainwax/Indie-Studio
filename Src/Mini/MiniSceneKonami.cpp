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

	_playerWhite.sprite = MiniSprite(video->loadTexture("Assets/Sprites/Bomberman.png"));

	_playerWhite.posx = 0;
	_playerWhite.posy = 0;
}

void MiniSceneKonami::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneKonami::playersMovements(IMiniActionMgr *action)
{
	if (action->isKeyDown(irr::KEY_UP)) {
		_playerWhite.posy -= 10;
	}
	else if (action->isKeyPressed(irr::KEY_DOWN)) {
		_playerWhite.posy += 10;
	}
	else if (action->isKeyDown(irr::KEY_LEFT)) {
		_playerWhite.posx -= 10;
	}
	else if (action->isKeyDown(irr::KEY_RIGHT)) {
		_playerWhite.posx += 10;
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

	_playerWhite.sprite.destination.width = (float)video->getScreenWidth() / (float)_playerWhite.sprite.getWidth() * 1.0f;
	_playerWhite.sprite.destination.height = (float)video->getScreenHeight() / (float)_playerWhite.sprite.getHeight() * 1.0f;

	_playerWhite.sprite.destination.x = (float)video->getScreenWidth() / 100.0f * _playerWhite.posx;
	_playerWhite.sprite.destination.y = (float)video->getScreenHeight() / 100.0f * _playerWhite.posy;

	video->drawSprite(_back);
	video->drawSprite(_playerWhite.sprite);
}

bool MiniSceneKonami::isGameEnded()
{
	return _gameEnded;
}
