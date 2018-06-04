/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "ActionManager.hpp"


class KeySet final {
public:
	KeySet(irr::EKEY_CODE up = irr::KEY_UP,
		irr::EKEY_CODE down = irr::KEY_DOWN,
		irr::EKEY_CODE left = irr::KEY_LEFT,
		irr::EKEY_CODE right = irr::KEY_RIGHT,
		irr::EKEY_CODE bomb = irr::KEY_SPACE);
	~KeySet();
	irr::EKEY_CODE upKey;
	irr::EKEY_CODE downKey;
	irr::EKEY_CODE leftKey;
	irr::EKEY_CODE rightKey;
	irr::EKEY_CODE bombKey;
};

class KeySetUtils final {
public:
static KeySet dflKeySet1;
static KeySet dflKeySet2;
};
