/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"

#define OPTIONS_MENU_AUDIO MENU_PATH "OptionsMenuAudio.jpg"
#define OPTIONS_MENU_BACK MENU_PATH "OptionsMenuBack.jpg"

class MiniSceneOptions final : public MiniScene {
public:
	MiniSceneOptions();
	~MiniSceneOptions() override;

	MiniScene *clone() override;

	void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;
	void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) override;

private:
	char _choice;
	MiniSprite _audio;
	MiniSprite _back;
	MiniSprite _ko;
	MiniSprite _ok;
};
