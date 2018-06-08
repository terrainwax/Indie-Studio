/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IMiniCore.hpp"
#include "MiniScene.hpp"
#include "MiniActionMgr.hpp"
#include "MiniVideoMgr.hpp"
#include "MiniAudioMgr.hpp"

#define CORE_WINDOW_DRIVER irr::video::EDT_OPENGL
#define CORE_WINDOW_WIDTH 1280
#define CORE_WINDOW_HEIGHT 720
#define CORE_WINDOW_BITS 32

class MiniCore final : public IMiniCore {
public:
	MiniCore();
	~MiniCore() override;

	void enter(const std::string &sceneName) override;
	void quit() override;

	void add(MiniScene *scene);

private:
	MiniActionMgr _action;
	irr::IrrlichtDevice *_videoDevice;
	irrklang::ISoundEngine *_audioDevice;
	MiniVideoMgr _video;
	MiniAudioMgr _audio;

	std::stack<MiniScene *> _currentScenes;
	std::map<std::string, MiniScene *> _knownScenes;
	bool _running;
};
