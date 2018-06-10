/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"
#include "MiniPlayer.hpp"

#define PLAYER_SPEED 1.5f
#define BOMB_SPEED 1.0f

class MiniSceneKonami final : public MiniScene {
public:
	MiniSceneKonami();
	~MiniSceneKonami() override;

	MiniScene *clone() override;

	void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;
	void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) override;

	void playersMovements(IMiniActionMgr *action);
	bool isGameEnded();

private:
	MiniSprite	_back;
	MiniPlayer	_playerWhite;
	MiniPlayer	_playerBlack;
	bool		_gameEnded;
};
