/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 20:48:49
*/

#include "WallPass.hpp"

WallPass::WallPass() : APowerUp("WallPass")
{
	_cube.texture = TEXTURE("WallPass.jpg");
}

WallPass::~WallPass()
{
}

void WallPass::onPickUp(Player &player)
{
	player.setWallPass(true);
}