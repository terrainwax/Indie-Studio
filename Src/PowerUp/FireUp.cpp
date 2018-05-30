/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 17:44:05
*/

#include "FireUp.hpp"

FireUp::FireUp()
{
}

FireUp::~FireUp()
{
}

const std::string FireUp::getName()
{
	return std::string("FireUp");
}

void FireUp::onPickUp(Player &player)
{
	player.setFire(player.getFire() + 1);
}