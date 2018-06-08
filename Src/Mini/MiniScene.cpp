#include "MiniScene.hpp"

MiniScene::MiniScene(const std::string &name)
	: _name(name)
{

}

MiniScene::~MiniScene()
{

}

void MiniScene::start(IMiniCore *core)
{
	(void)core;
	_running = true;
}

void MiniScene::stop(IMiniCore *core)
{
	(void)core;
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