/*
* @Author: Reimua
* @Date:   2018-05-30 16:39:21
* @Last Modified by:   Reimua
* @Last Modified time: 2018-06-04 18:01:16
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

void APowerUp::setPosition(irr::core::vector3df pos)
{
	_cube.pos = pos;
}

irr::core::vector3df APowerUp::getPosition() const
{
	return _cube.pos;
}
