/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 16:45:35
*/

#include "BombUp.hpp"

BombUp::BombUp()
{
}

BombUp::~BombUp()
{
}

void BombUp::onPickUp(Player &player)
{
	player.setNbBomb(player.getNbBomb() + 1);
}