/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSprite.hpp"

MiniSprite::MiniSprite()
	: _texture(nullptr), color(255, 255, 255, 255), source(0, 0, 0, 0), destination(0, 0, 0, 0)
{

}

MiniSprite::MiniSprite(irr::video::ITexture *texture)
	: _texture(texture), color(255, 255, 255, 255),
	source(0, 0, texture->getOriginalSize().Width, texture->getOriginalSize().Height),
	destination(0, 0, texture->getOriginalSize().Width, texture->getOriginalSize().Height)
{

}

MiniSprite::~MiniSprite()
{

}

std::size_t MiniSprite::getWidth()
{
	return _texture->getOriginalSize().Width;
}

std::size_t MiniSprite::getHeight()
{
	return _texture->getOriginalSize().Height;
}

irr::video::ITexture *MiniSprite::getTexture()
{
	return _texture;
}
