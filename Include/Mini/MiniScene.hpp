/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IMiniCore.hpp"
#include "IMiniActionMgr.hpp"
#include "IMiniAudioMgr.hpp"
#include "IMiniVideoMgr.hpp"

class MiniScene {
public:
	MiniScene(const std::string &name);
	virtual ~MiniScene();

	virtual MiniScene *clone() = 0;

	virtual void start(IMiniCore *core);
	virtual void stop(IMiniCore *core);

	virtual void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio) = 0;
	virtual void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio) = 0;

	virtual std::string getName();
	virtual bool isRunning();

protected:
	std::string _name;
	bool _running;
};