/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"

#define INTRO_BLUE BASE_PATH "StartGameBlue.jpg"
#define INTRO_RED BASE_PATH "StartGameRed.jpg"

class MiniSceneIntro final : public MiniScene {
public:
	MiniSceneIntro();
	~MiniSceneIntro() override;

	MiniScene *clone() override;

	void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;
	void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) override;

private:
	MiniSprite _blue;
	MiniSprite _red;
};
