/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniScenePlayers.hpp"

MiniScenePlayers::MiniScenePlayers()
	: MiniScene("Players"), _choice(0)
{

}

MiniScenePlayers::~MiniScenePlayers()
{
}

MiniScene *MiniScenePlayers::clone()
{
	return new MiniScenePlayers();
}

void MiniScenePlayers::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	MiniScene::start(core, audio, video);

	for (std::size_t x = 0; x < PLAYER_NUMBER; x++)
		_players[x] = false;

	// Add code here
	_buttons[0] = MiniSprite(video->loadTexture(START_MENU_P1));
	_buttons[1] = MiniSprite(video->loadTexture(START_MENU_P2));
	_buttons[2] = MiniSprite(video->loadTexture(START_MENU_P3));
	_buttons[3] = MiniSprite(video->loadTexture(START_MENU_P4));
	_buttons[4] = MiniSprite(video->loadTexture(START_MENU_START));

	_checks[0] = MiniSprite(video->loadTexture(OK));
	_checks[1] = MiniSprite(video->loadTexture(KO));
}

void MiniScenePlayers::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniScenePlayers::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;
	(void)clock;

	if (action->isKeyPressed(irr::KEY_RETURN))
	{
		if (_choice == 4) {
			audio->clear();
			audio->playMusic(GAME_MUSIC);
			core->setPlayers(_players);
			core->push("Bomber");
		} else {
			audio->playSound(TOGGLE_PLAYER);
			_players[_choice] = !_players[_choice];
		}
	}

	if (action->isKeyPressed(irr::KEY_UP)) {
		audio->playSound(NOCK);
		_choice = (5 + (-1) + _choice) % 5;
	}

	if (action->isKeyPressed(irr::KEY_DOWN)) {
		audio->playSound(NOCK);
		_choice = (5 + (+1) + _choice) % 5;
	}

	if (action->isKeyPressed(irr::KEY_ESCAPE)) {
		audio->playSound(TRANSITION);
		core->pop();
	}
}

void MiniScenePlayers::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
	(void)clock;

	MiniSprite sprite = _buttons[_choice];
	sprite.destination.width = video->getScreenWidth();
	sprite.destination.height = video->getScreenHeight();
	video->drawSprite(sprite);

	for (size_t x = 0; x < PLAYER_NUMBER; x++)
	{
		MiniSprite check = (_players[x]) ? _checks[0] : _checks[1];
		check.destination.x = video->getScreenWidth() * (0.828f + (0.001f * (float)x));
		check.destination.y = video->getScreenHeight() * (0.085f + 0.2f * (float)x);
		check.destination.width = video->getScreenWidth() * 0.029f;
		check.destination.height = video->getScreenHeight() * 0.04f;
		video->drawSprite(check);
	}
}
