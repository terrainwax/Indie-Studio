/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSprite.hpp"

#pragma once

class MiniBomb final {
public:
	MiniBomb() = default;
	~MiniBomb() = default;

	MiniSprite sprite;
	float dstx;
	float dsty;
	float posx;
	float posy;
	float srcx;
	float srcy;
	bool explode;
};
