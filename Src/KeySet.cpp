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
