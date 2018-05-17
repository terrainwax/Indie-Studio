/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "GraphicManager.hpp"

GraphicManager::GraphicManager(ActionManager &action):
_device(irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, &action)),
_smgr(_device->getSceneManager()),
_driver(_device->getVideoDriver())
{
	if (_device == nullptr)
		throw std::runtime_error("Cannot get driver");
	_smgr->addCameraSceneNodeFPS();
}

GraphicManager::~GraphicManager()
{
}

irr::scene::ISceneNode *GraphicManager::drawCube(const Cube &cube)
{
	irr::scene::ISceneNode *node = _smgr->addCubeSceneNode();
	if (node == nullptr)
		return nullptr;
	node->setPosition(cube.pos);
	node->setRotation(cube.rotation);
	node->setMaterialTexture(0, _driver->getTexture(&cube.texture[0]));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_smgr->addToDeletionQueue(node);
	return node;
}

void GraphicManager::render()
{
	_driver->beginScene(true, true, irr::video::SColor(255,113,113,133));
	_smgr->drawAll();
	_driver->endScene();
}

bool GraphicManager::isActive()
{
	return _device->run();
}