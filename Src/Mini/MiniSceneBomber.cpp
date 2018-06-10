/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneBomber.hpp"
#include "Player.hpp"
#include "AI.hpp"

MiniSceneBomber::MiniSceneBomber()
	: MiniScene("Bomber", false, false)
{
}

MiniSceneBomber::~MiniSceneBomber()
{
}

MiniScene *MiniSceneBomber::clone()
{
	return new MiniSceneBomber();
}

void MiniSceneBomber::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	MiniScene::start(core, audio, video);

	_graphics = GraphicManager(core->getVideoDevice());
	_sounds = SoundManager(core->getAudioDevice(), audio->getMasterVolume() > 0.0f);

	_graphics.createSkybox("Assets/Textures/skyfield.jpg");

	int mapSize = 15;
	int playerNb = 0;

	this->addPlayer(core, mapSize);
	for (int i = 0; i < PLAYER_NUMBER; i++)
		playerNb = core->getPlayers()[i] ? playerNb + 1 : playerNb;
	if (playerNb <= 1)
		_game.setSkyView(false);
}

void MiniSceneBomber::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	// Add code here

	MiniScene::stop(core, audio, video);
}

void MiniSceneBomber::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)action;
	(void)audio;
	(void)clock;

	if (action->isKeyPressed(irr::KEY_ESCAPE) || !_game.isOnGoing())
	{
		_graphics.clear();
		core->setWinner(_game.winnerNbr());
		core->pop();
		core->push("Victory");
	}
	else
		_game.update(*(ActionManager *)action, _graphics, _sounds);
}

void MiniSceneBomber::addPlayer(IMiniCore *core, int mapSize)
{
	int spawnX[PLAYER_NUMBER] = {
		1,
		1,
		mapSize - 2,
		mapSize - 2
	};
	int spawnY[PLAYER_NUMBER] = {
		1,
		mapSize - 2,
		mapSize - 2,
		1
	};
	std::vector<std::string> models = {
		"0112.x",
		"0114.x",
		"0115.x",
		"0116.x"
	};
	KeySet keyMap[PLAYER_NUMBER] = {
		KeySetUtils::dflKeySet1,
		KeySetUtils::dflKeySet2,
		KeySetUtils::dflKeySet3,
		KeySetUtils::dflKeySet4
	};
	for (int i = 0; i < PLAYER_NUMBER; i++) {
		if (core->getPlayers()[i] == true)
			_game.addPlayer(new Player(spawnX[i], spawnY[i], models[i], "Player", _graphics.getSceneManager(), keyMap[i]));

	}
	for (int i = 0; i < PLAYER_NUMBER; i++) {
		if (core->getPlayers()[i] == false)
			_game.addPlayer(new AI(spawnX[i], spawnY[i], "AI", _graphics.getSceneManager()));
	}
}

void MiniSceneBomber::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
	(void)clock;

	_game.display(_graphics);
	_graphics.render();
}
