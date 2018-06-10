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

	_back = MiniSprite(video->loadTexture(BACKGROUND));

	_playerWhite.sprite = MiniSprite(video->loadTexture(PLAYER_WHITE));
	_playerBlack.sprite = MiniSprite(video->loadTexture(PLAYER_BLACK));

	_playerWhite.posx = 80;
	_playerWhite.posy = 80;
	_playerBlack.posx = 20;
	_playerBlack.posy = 80;
}

void MiniSceneKonami::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneKonami::playersMovements(IMiniActionMgr *action)
{
	// PLAYER WHITE
	if (action->isKeyDown(irr::KEY_UP)) {
		_playerWhite.posy -= PLAYER_SPEED;
	} else if (action->isKeyPressed(irr::KEY_DOWN)) {
		_playerWhite.posy += PLAYER_SPEED;
	} else if (action->isKeyDown(irr::KEY_LEFT)) {
		_playerWhite.posx -= PLAYER_SPEED;
	} else if (action->isKeyDown(irr::KEY_RIGHT)) {
		_playerWhite.posx += PLAYER_SPEED;
	}

	// PLAYER BLACK
	if (action->isKeyDown(irr::KEY_KEY_Z)) {
		_playerBlack.posy -= PLAYER_SPEED;
	} else if (action->isKeyPressed(irr::KEY_KEY_S)) {
		_playerBlack.posy += PLAYER_SPEED;
	} else if (action->isKeyDown(irr::KEY_KEY_Q)) {
		_playerBlack.posx -= PLAYER_SPEED;
	} else if (action->isKeyDown(irr::KEY_KEY_D)) {
		_playerBlack.posx += PLAYER_SPEED;
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

	// PLAYER WHITE RENDERING
	_playerWhite.sprite.destination.width = (float)video->getScreenWidth() / (float)_playerWhite.sprite.getWidth() * 0.9f;
	_playerWhite.sprite.destination.height = (float)video->getScreenHeight() / (float)_playerWhite.sprite.getHeight() * 0.9f;

	_playerWhite.sprite.destination.x = (float)video->getScreenWidth() / 100.0f * _playerWhite.posx;
	_playerWhite.sprite.destination.y = (float)video->getScreenHeight() / 100.0f * _playerWhite.posy;

	// PLAYER BLACK RENDERING

	_playerBlack.sprite.destination.width = (float)video->getScreenWidth() / (float)_playerBlack.sprite.getWidth() * 0.9f;
	_playerBlack.sprite.destination.height = (float)video->getScreenHeight() / (float)_playerBlack.sprite.getHeight() * 0.9f;

	_playerBlack.sprite.destination.x = (float)video->getScreenWidth() / 100.0f * _playerBlack.posx;
	_playerBlack.sprite.destination.y = (float)video->getScreenHeight() / 100.0f * _playerBlack.posy;

	video->drawSprite(_back);
	video->drawSprite(_playerWhite.sprite);
	video->drawSprite(_playerBlack.sprite);
}

bool MiniSceneKonami::isGameEnded()
{
	return _gameEnded;
}
