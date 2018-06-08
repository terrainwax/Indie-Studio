/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniBase.hpp"
#include "MiniRectangle.hpp"

class MiniSprite final {
public:
	MiniSprite();
	MiniSprite(irr::video::ITexture *_texture);
	~MiniSprite();

	irr::video::ITexture *getTexture();
	std::size_t getWidth();
	std::size_t getHeight();

	irr::video::SColor color;
	MiniRectangle source;
	MiniRectangle destination;
private:
	irr::video::ITexture *_texture;
};