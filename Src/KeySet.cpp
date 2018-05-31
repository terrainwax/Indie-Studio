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
