/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniVideoMgr.hpp"

MiniVideoMgr::MiniVideoMgr()
	: _videoDevice(nullptr)
{

}

MiniVideoMgr::MiniVideoMgr(irr::IrrlichtDevice *videoDevice)
	: _videoDevice(videoDevice)
{
	videoDevice->setWindowCaption(VIDEO_WINDOW_TITLE);
}

MiniVideoMgr::~MiniVideoMgr()
{

}

std::size_t MiniVideoMgr::getScreenWidth()
{
	return _videoDevice->getVideoDriver()->getScreenSize().Width;
}

std::size_t MiniVideoMgr::getScreenHeight()
{
	return _videoDevice->getVideoDriver()->getScreenSize().Height;
}

void MiniVideoMgr::drawSprite(MiniSprite &sprite)
{
	(void)sprite;
}