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

irr::video::ITexture *MiniVideoMgr::loadTexture(const std::string &textureFile)
{
	irr::video::ITexture *texture = _videoDevice->getVideoDriver()->getTexture(textureFile.c_str());
	if (texture == nullptr || texture == 0)
		throw new std::runtime_error("Cannot find sprite.");
	return texture;
}

void MiniVideoMgr::drawSprite(MiniSprite &sprite)
{
	irr::video::SColor color[4];
	color[0] = sprite.color;
	color[1] = sprite.color;
	color[2] = sprite.color;
	color[3] = sprite.color;

	MiniRectangle source = sprite.source;
	MiniRectangle destination = sprite.destination;

	_videoDevice->getVideoDriver()->draw2DImage(sprite.getTexture(),
			irr::core::rect<irr::s32> (destination.x, destination.y, destination.x + destination.width, destination.y + destination.height),
			irr::core::rect<irr::s32> (source.x, source.y, source.x + source.width, source.y + source.height), 0, color, true);
}

bool MiniVideoMgr::available()
{
	return _videoDevice->run();
}

void MiniVideoMgr::clear()
{
	_videoDevice->getVideoDriver()->beginScene(true, true, irr::video::SColor (0,120,120,120));
}

void MiniVideoMgr::present()
{
	_videoDevice->getVideoDriver()->endScene();
}