/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSprite.hpp"

#pragma once

class MiniPlayer final {
public:
	MiniPlayer() = default;
	~MiniPlayer() = default;

	MiniSprite sprite;
	float posx;
	float posy;
};
