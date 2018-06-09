/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSceneBomber.hpp"
#include "GraphicManager.hpp"
#include "Game.hpp"
#include "SoundManager.hpp"
#include "Player.hpp"
#include "AI.hpp"

MiniSceneBomber::MiniSceneBomber()
	: MiniScene("Bomber")
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

	// Add code here
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

	GraphicManager graphics(core->getVideoDevice());
	SoundManager sounds(core->getAudioDevice());

	graphics.createSkybox("Assets/Textures/skyfield.jpg");

	int mapSize = 15;
	int playerNb = 0;

	Game game(mapSize);

	this->addPlayer(core, game, graphics, mapSize);
	for (int i = 0; i < PLAYER_NUMBER; i++)
		playerNb = core->getPlayers()[i] ? playerNb + 1 : playerNb;
	if (playerNb <= 1)
		game.setSkyView(false);

	//sounds.playBgm(SOUND("GroSonSaRace.ogg"));
	while (graphics.isActive() && game.isOnGoing() && !action->isKeyPressed(irr::KEY_ESCAPE)) {
		game.display(graphics);
		game.update(*action, graphics, sounds);
		graphics.render();
		action->flush();
	}
	//launchVictory(game.winnerNbr());

	core->pop();
}

void MiniSceneBomber::addPlayer(IMiniCore *core, Game &game, GraphicManager &graphics, int mapSize)
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
	KeySet keyMap[PLAYER_NUMBER] = {
		KeySetUtils::dflKeySet1,
		KeySetUtils::dflKeySet2,
		KeySetUtils::dflKeySet3,
		KeySetUtils::dflKeySet4
	};
	for (int i = 0; i < PLAYER_NUMBER; i++) {
		if (core->getPlayers()[i] == true)
			game.addPlayer(new Player(spawnX[i], spawnY[i], "0112.x", "Player", graphics.getSceneManager(), keyMap[i]));
	}
	for (int i = 0; i < PLAYER_NUMBER; i++) {
		if (core->getPlayers()[i] == false)
			game.addPlayer(new AI(spawnX[i], spawnY[i], "AI", graphics.getSceneManager()));
	}
}

void MiniSceneBomber::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
}