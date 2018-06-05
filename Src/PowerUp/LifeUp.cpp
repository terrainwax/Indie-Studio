/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-05 17:14:23
*/

#include "LifeUp.hpp"

LifeUp::LifeUp() : APowerUp("LifeUp")
{
	_cube.texture = TEXTURE("LifeUp.jpg");
}

LifeUp::~LifeUp()
{
}

void LifeUp::onPickUp(APlayer &player)
{
	player.setNbLife(player.getNbLife() + 1);
}