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

class GraphicManager final {
private:
	irr::IrrlichtDevice *_device;
	irr::video::E_DRIVER_TYPE _driverType;
	irr::scene::ISceneManager *_smgr;
	irr::video::IVideoDriver *_driver;	
public:
	GraphicManager(ActionManager &actionMgr);
	~GraphicManager();

	void render();
	bool isActive();
	irr::scene::ISceneNode *drawCube(const Cube &cube);
	irr::scene::ISceneNode *drawSphere(const Sphere &sphere);
};