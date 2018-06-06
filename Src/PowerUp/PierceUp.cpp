/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-06 13:23:15
*/

#include "PierceUp.hpp"

PierceUp::PierceUp() : APowerUp("PierceUp")
{
	_cube.texture = TEXTURE("PierceUp.jpg");
}

PierceUp::~PierceUp()
{
}

void PierceUp::onPickUp(APlayer &player)
{
	if (player.getPierce() == false)
		player.setPierce(true);
	else
		player.setNbBomb(player.getNbBomb() + 1);
}