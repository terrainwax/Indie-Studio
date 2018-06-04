/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-04 18:08:39
*/

#include "BombUp.hpp"

BombUp::BombUp() : APowerUp("BombUp")
{
	_cube.texture = TEXTURE("BombUp.jpg");
}

BombUp::~BombUp()
{
}

void BombUp::onPickUp(APlayer &player)
{
	player.setNbBomb(player.getNbBomb() + 1);
}