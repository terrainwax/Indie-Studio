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
	MiniScene(const std::string &name, bool simple = true, bool flush = true);
	virtual ~MiniScene();

	virtual MiniScene *clone() = 0;

	virtual void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video);
	virtual void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video);

	virtual void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) = 0;
	virtual void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) = 0;

	virtual std::string getName();
	virtual bool isRunning();
	virtual bool isSimple();
	virtual bool needFlush();

protected:
	std::string _name;
	bool _running;
	bool _simple;
	bool _flush;
};