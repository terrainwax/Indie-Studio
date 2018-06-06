/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-06 14:40:03
*/

#include "FullFire.hpp"

FullFire::FullFire() : APowerUp("FullFire")
{
	_cube.texture = TEXTURE("FullFire.jpg");
}

FullFire::~FullFire()
{
}

void FullFire::onPickUp(APlayer &player)
{
	player.setFire(player.getFire() + 20);
}