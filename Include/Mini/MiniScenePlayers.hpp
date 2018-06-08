/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"

#define PLAYER_NUMBER 4

class MiniScenePlayers final : public MiniScene {
public:
	MiniScenePlayers();
	~MiniScenePlayers() override;

	MiniScene *clone() override;

	void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;
	void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) override;

private:
	char _choice;
	bool _players[PLAYER_NUMBER];
	MiniSprite _buttons[5];
	MiniSprite _checks[2];
};