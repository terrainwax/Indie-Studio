/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 20:48:36
*/

#include "SpeedUp.hpp"

SpeedUp::SpeedUp() : APowerUp("SpeedUp")
{
	_cube.texture = TEXTURE("SpeedUp.jpg");
}

SpeedUp::~SpeedUp()
{
}

void SpeedUp::onPickUp(Player &player)
{
	player.setSpeed(player.getSpeed() + 1);
}