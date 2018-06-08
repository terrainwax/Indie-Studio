/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IMiniCore.hpp"
#include "MiniSprite.hpp"

class IMiniVideoMgr {
public:
	IMiniVideoMgr() = default;
	virtual ~IMiniVideoMgr() = default;

	virtual std::size_t getScreenHeight() = 0;
	virtual std::size_t getScreenWidth() = 0;
	virtual irr::video::ITexture *loadTexture(const std::string &textureFile) = 0;
	virtual void drawSprite(MiniSprite &sprite) = 0;
};