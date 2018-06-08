/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"

class MiniSceneIntro final : public MiniScene {
public:
	MiniSceneIntro();
	~MiniSceneIntro() override;

	MiniScene *clone() override;

	void start(IMiniCore *core) override;
	void stop(IMiniCore *core) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio) override;
};