/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"

#define GAME_MENU_START BASE_PATH "GameMenuStart.jpg"
#define GAME_MENU_OPTIONS BASE_PATH "GameMenuOptions.jpg"
#define GAME_MENU_EXIT BASE_PATH "GameMenuExit.jpg"

class MiniSceneMenu final : public MiniScene {
public:
	MiniSceneMenu();
	~MiniSceneMenu() override;

	MiniScene *clone() override;

	void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;
	void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) override;

private:
	char _choice;
	MiniSprite _start;
	MiniSprite _options;
	MiniSprite _exit;
};
