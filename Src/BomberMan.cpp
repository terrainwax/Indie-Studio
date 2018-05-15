/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "BomberMan.hpp"

BomberMan::BomberMan() : _action(), _device(irr::createDevice(irr::video::EDT_OPENGL,
						irr::core::dimension2d<irr::u32>(640, 480),
						16, false, false, false, &_action))
{
	if (_device == nullptr)
		throw std::runtime_error("Cannot get driver");
}

BomberMan::~BomberMan()
{
}

bool BomberMan::run()
{
	if (_device->run() == false)
		return false;
	return !_action.isKeyReleased(irr::KEY_KEY_Q);
}