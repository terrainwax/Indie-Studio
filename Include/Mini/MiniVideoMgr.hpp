/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IMiniVideoMgr.hpp"

#define VIDEO_WINDOW_TITLE L"Super Ultra Mega Bomberman"

class MiniVideoMgr final : public IMiniVideoMgr {
public:
	MiniVideoMgr();
	MiniVideoMgr(irr::IrrlichtDevice *videoDevice);
	~MiniVideoMgr() override;

	std::size_t getScreenHeight() override;
	std::size_t getScreenWidth() override;
	void drawSprite(MiniSprite &sprite) override;
private:
	irr::IrrlichtDevice *_videoDevice;
};