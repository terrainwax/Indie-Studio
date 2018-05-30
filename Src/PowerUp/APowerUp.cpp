/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-05-30 20:47:47
*/

#include "APowerUp.hpp"

APowerUp::APowerUp(const std::string &name) : _name(name), _cube()
{
	_cube.pos = irr::core::vector3df(10, 0, 10);
	_cube.scale = irr::core::vector3df(0.5, 0.5, 0.5);
	_cube.rotation = irr::core::vector3df(45, 45, 45);
}

const std::string APowerUp::getName()
{
	return _name;
}

void APowerUp::renderPowerUp(GraphicManager &graphicManager)
{
	graphicManager.drawCube(_cube);
	_cube.rotation.Z += 2;
	_cube.rotation.Y += 2;
}