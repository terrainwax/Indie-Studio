/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "BomberMan.hpp"

BomberMan::BomberMan() :
_action(),
_device(irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, &_action)),
_smgr(_device->getSceneManager()),
_driver(_device->getVideoDriver())
{
	if (_device == nullptr)
		throw std::runtime_error("Cannot get driver");
	irr::scene::ISceneNode *node = _smgr->addSphereSceneNode();
	_smgr->addCameraSceneNodeFPS();
	if (node)
	{
		node->setPosition(irr::core::vector3df(0,0,30));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}
	_driver->beginScene(true, true, irr::video::SColor(255,113,113,133));
	_smgr->drawAll();
	_driver->endScene();

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