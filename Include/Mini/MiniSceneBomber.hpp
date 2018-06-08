/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"

class MiniSceneBomber final : public MiniScene {
public:
	MiniSceneBomber();
	~MiniSceneBomber() override;

	MiniScene *clone() override;

	void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;
	void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) override;
};
