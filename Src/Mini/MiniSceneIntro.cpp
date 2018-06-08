#include "MiniSceneIntro.hpp"

MiniSceneIntro::MiniSceneIntro()
	: MiniScene("Intro")
{

}

MiniSceneIntro::~MiniSceneIntro()
{

}

MiniScene *MiniSceneIntro::clone()
{
	return new MiniSceneIntro();
}

void MiniSceneIntro::start(IMiniCore *core)
{
	MiniScene::start(core);
	// Add code here
}

void MiniSceneIntro::stop(IMiniCore *core)
{
	// Add code here
	MiniScene::stop(core);
}

void MiniSceneIntro::updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio)
{
	(void)core;
	(void)action;
	(void)audio;
}

void MiniSceneIntro::renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio)
{
	(void)core;
	(void)video;
	(void)audio;
}