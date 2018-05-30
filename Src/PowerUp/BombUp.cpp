/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 17:44:02
*/

#include "BombUp.hpp"

BombUp::BombUp()
{
}

BombUp::~BombUp()
{
}

const std::string BombUp::getName()
{
	return std::string("BombUp");
}

void BombUp::onPickUp(Player &player)
{
	player.setNbBomb(player.getNbBomb() + 1);
}