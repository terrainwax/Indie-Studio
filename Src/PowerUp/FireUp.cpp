/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 20:48:57
*/

#include "FireUp.hpp"

FireUp::FireUp() : APowerUp("FireUp")
{
	_cube.texture = TEXTURE("FireUp.jpg");
}

FireUp::~FireUp()
{
}

void FireUp::onPickUp(Player &player)
{
	player.setFire(player.getFire() + 1);
}