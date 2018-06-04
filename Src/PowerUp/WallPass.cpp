/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-04 18:08:48
*/

#include "WallPass.hpp"

WallPass::WallPass() : APowerUp("WallPass")
{
	_cube.texture = TEXTURE("WallPass.jpg");
}

WallPass::~WallPass()
{
}

void WallPass::onPickUp(APlayer &player)
{
	player.setWallPass(true);
}