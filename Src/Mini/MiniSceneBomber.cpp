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

	Game game;
	game.addPlayer(new Player(1, 1, "0112.x", "test", graphics.getSceneManager(), KeySetUtils::dflKeySet1));
	game.addPlayer(new Player(1, 1, "0112.x", "test", graphics.getSceneManager(), KeySetUtils::dflKeySet2));
	game.addPlayer(new Player(1, 2, "0112.x", "test", graphics.getSceneManager(), KeySetUtils::dflKeySet2));

	//sounds.playBgm(SOUND("GroSonSaRace.ogg"));
	while (graphics.isActive() && game.isOnGoing() && !action->isKeyPressed(irr::KEY_ESCAPE)) {
		game.display(graphics);
		game.update(*action, graphics, sounds);
		graphics.render();
	}

	core->pop();
}

void MiniSceneBomber::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock)
{
	(void)core;
	(void)video;
	(void)audio;
}