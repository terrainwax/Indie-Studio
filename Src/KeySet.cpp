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
	irr::KEY_UP,
	irr::KEY_DOWN,
	irr::KEY_LEFT,
	irr::KEY_RIGHT,
	irr::KEY_SPACE
};

KeySet KeySetUtils::dflKeySet2 = {
	irr::KEY_KEY_Z,
	irr::KEY_KEY_S,
	irr::KEY_KEY_Q,
	irr::KEY_KEY_D,
	irr::KEY_KEY_E
};

KeySet KeySetUtils::dflKeySet3 = {
	irr::KEY_KEY_O,
	irr::KEY_KEY_L,
	irr::KEY_KEY_K,
	irr::KEY_KEY_M,
	irr::KEY_KEY_P
};

KeySet KeySetUtils::dflKeySet4 = {
	irr::KEY_KEY_Y,
	irr::KEY_KEY_H,
	irr::KEY_KEY_G,
	irr::KEY_KEY_J,
	irr::KEY_KEY_U
};
