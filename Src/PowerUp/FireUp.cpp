/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-04 18:08:45
*/

#include "FireUp.hpp"

FireUp::FireUp() : APowerUp("FireUp")
{
	_cube.texture = TEXTURE("FireUp.jpg");
}

FireUp::~FireUp()
{
}

void FireUp::onPickUp(APlayer &player)
{
	player.setFire(player.getFire() + 1);
}