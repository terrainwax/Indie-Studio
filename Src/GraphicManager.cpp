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
_driver(_device->getVideoDriver()),
_camera(_smgr->addCameraSceneNode()) //FPS for debug
{
	if (_device == nullptr)
		throw std::runtime_error("Cannot get driver");
}

GraphicManager::~GraphicManager()
{
	_device->drop();
}

void GraphicManager::drawCube(const Cube &cube)
{
	irr::scene::ISceneNode *node = _smgr->addCubeSceneNode();
	if (node == nullptr)
		return;
	node->setScale(cube.scale);
	node->setPosition(cube.pos);
	node->setRotation(cube.rotation);
	node->setMaterialTexture(0, _driver->getTexture(&cube.texture[0]));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setMaterialFlag(irr::video::EMF_BILINEAR_FILTER, false);
	//node->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, false);
	//node->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
	_smgr->addToDeletionQueue(node);
}

irr::scene::ISceneNode *GraphicManager::makeCubeNode(const Cube &cube)
{
	irr::scene::ISceneNode *node = _smgr->addCubeSceneNode();
	if (node == nullptr)
		return nullptr;
	node->setScale(cube.scale);
	node->setPosition(cube.pos);
	node->setRotation(cube.rotation);
	node->setMaterialTexture(0, _driver->getTexture(&cube.texture[0]));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	return node;
}

void GraphicManager::drawSphere(const Sphere &sphere)
{
	irr::scene::ISceneNode *node = _smgr->addSphereSceneNode();
	if (node == nullptr)
		return;
	node->setScale(sphere.scale);
	node->setPosition(sphere.pos);
	node->setRotation(sphere.rotation);
	node->setMaterialTexture(0, _driver->getTexture(&sphere.texture[0]));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_smgr->addToDeletionQueue(node);
}

irr::scene::ISceneManager *GraphicManager::getSceneManager()
{
	return _smgr;
}

void GraphicManager::setCameraPosition(const irr::core::vector3df &pos)
{
	_camera->setPosition(pos);
}

void GraphicManager::setCameraTarget(const irr::core::vector3df &pos)
{
	_camera->setTarget(pos);
}

void GraphicManager::render()
{
	_driver->beginScene(true, true, irr::video::SColor(255,113,113,133));
	_smgr->drawAll();
	_driver->endScene();
}

void GraphicManager::addToDeletionQueue(irr::scene::ISceneNode *node)
{
	_smgr->addToDeletionQueue(node);
}

bool GraphicManager::isActive()
{
	return _device->run();
}
