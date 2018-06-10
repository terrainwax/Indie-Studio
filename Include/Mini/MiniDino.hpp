/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniSprite.hpp"

#pragma once

class MiniDino final {
public:
	MiniDino() = default;
	~MiniDino() = default;

	MiniSprite sprite;
	float posx;
	float posy;
};
