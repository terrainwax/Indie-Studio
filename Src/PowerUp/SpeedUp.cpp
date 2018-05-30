/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 16:53:16
*/

#include "SpeedUp.hpp"

SpeedUp::SpeedUp()
{
}

SpeedUp::~SpeedUp()
{
}

void SpeedUp::onPickUp(Player &player)
{
	player.setSpeed(player.getSpeed() + 1);
}