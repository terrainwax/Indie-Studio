/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 16:56:16
*/

#include "WallPass.hpp"

WallPass::WallPass()
{
}

WallPass::~WallPass()
{
}

void WallPass::onPickUp(Player &player)
{
	player.setWallPass(true);
}