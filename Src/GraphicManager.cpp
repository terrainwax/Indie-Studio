/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "GraphicManager.hpp"

GraphicManager::GraphicManager(irr::IrrlichtDevice *device):
_device(device),
_smgr(device->getSceneManager()),
_driver(device->getVideoDriver()),
_camera(_smgr->addCameraSceneNode()) //FPS for debug
{
	if (_device == nullptr)
		throw std::runtime_error("Cannot get driver");
}

GraphicManager::~GraphicManager()
{
}

void GraphicManager::createSkybox(std::string s)
{
	_smgr->addSkyDomeSceneNode(_driver->getTexture(&s[0]));
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

irr::video::IVideoDriver *GraphicManager::getVideoDriver()
{
	return _driver;
}

irr::IrrlichtDevice *GraphicManager::getDevice()
{
	return _device;
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
