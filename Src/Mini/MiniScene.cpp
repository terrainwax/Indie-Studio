/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniScene.hpp"

MiniScene::MiniScene(const std::string &name, bool simple, bool flush)
	: _name(name), _simple(simple), _flush(flush)
{

}

MiniScene::~MiniScene()
{

}

void MiniScene::start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	(void)core;
	(void)audio;
	(void)video;
	_running = true;
}

void MiniScene::stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video)
{
	(void)core;
	(void)audio;
	(void)video;
	_running = false;
}

std::string MiniScene::getName()
{
	return _name;
}

bool MiniScene::isRunning()
{
	return _running;
}

bool MiniScene::isSimple()
{
	return _simple;
}

bool MiniScene::needFlush()
{
	return _flush;
}

