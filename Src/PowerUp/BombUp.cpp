/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 20:48:14
*/

#include "BombUp.hpp"

BombUp::BombUp() : APowerUp("BombUp")
{
	_cube.texture = TEXTURE("BombUp.jpg");
}

BombUp::~BombUp()
{
}

void BombUp::onPickUp(Player &player)
{
	player.setNbBomb(player.getNbBomb() + 1);
}