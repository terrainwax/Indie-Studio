/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <stdexcept>

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#include <Keycodes.h>
#include <IEventReceiver.h>
#pragma GCC diagnostic warning "-Wunused-parameter"

#include "Cube.hpp"
#include "Sphere.hpp"
#include "ActionManager.hpp"

#ifndef TEXTURE
# define TEXTURE(x) (std::string("./Assets/Textures/") + std::string(x))
#endif 

class GraphicManager final {
private:
	irr::IrrlichtDevice *_device;
	irr::video::E_DRIVER_TYPE _driverType;
	irr::scene::ISceneManager *_smgr;
	irr::video::IVideoDriver *_driver;
	irr::scene::ICameraSceneNode *_camera;
public:
	GraphicManager(ActionManager &actionMgr);
	~GraphicManager();

	void render();
	bool isActive();
	void setCameraPosition(const irr::core::vector3df &pos);
	void setCameraRotation(const irr::core::vector3df &pos);
	irr::scene::ISceneNode *drawCube(const Cube &cube);
	irr::scene::ISceneNode *drawSphere(const Sphere &sphere);
};