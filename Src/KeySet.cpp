//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// KeySet class implementation
//

#include "KeySet.hpp"

KeySet::KeySet(irr::EKEY_CODE up, irr::EKEY_CODE down, irr::EKEY_CODE left, irr::EKEY_CODE right, irr::EKEY_CODE bomb) :
upKey(up),
downKey(down),
leftKey(left),
rightKey(right),
bombKey(bomb)
{
}

KeySet::~KeySet()
{
}

KeySet KeySetUtils::dflKeySet1 = {
	.upKey = irr::KEY_UP,
	.downKey = irr::KEY_DOWN,
	.leftKey = irr::KEY_LEFT,
	.rightKey = irr::KEY_RIGHT,
	.bombKey = irr::KEY_SPACE,
};

KeySet KeySetUtils::dflKeySet2 = {
	.upKey = irr::KEY_KEY_Z,
	.downKey = irr::KEY_KEY_S,
	.leftKey = irr::KEY_KEY_Q,
	.rightKey = irr::KEY_KEY_D,
	.bombKey = irr::KEY_KEY_E,
};