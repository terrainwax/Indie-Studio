/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "ActionManager.hpp"


class KeySet final {
	KeySet(irr::EKEY_CODE up = irr::KEY_UP,
		irr::EKEY_CODE down = irr::KEY_DOWN,
		irr::EKEY_CODE left = irr::KEY_LEFT,
		irr::EKEY_CODE right = irr::KEY_RIGHT);
	~KeySet();
public:
	irr::EKEY_CODE keyUp;
	irr::EKEY_CODE keyDown;
	irr::EKEY_CODE keyLeft;
	irr::EKEY_CODE keyRight;
};