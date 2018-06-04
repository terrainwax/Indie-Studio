/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-04 21:34:26
*/

#include "SpeedUp.hpp"

SpeedUp::SpeedUp() : APowerUp("SpeedUp")
{
	_cube.texture = TEXTURE("SpeedUp.jpg");
}

SpeedUp::~SpeedUp()
{
}

void SpeedUp::onPickUp(APlayer &player)
{
	player.setSpeed(player.getSpeed() + 0.25);
}