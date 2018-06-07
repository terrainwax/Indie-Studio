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

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_BITS 32

class GraphicManager final {
private:
	irr::IrrlichtDevice *_device;
	irr::video::E_DRIVER_TYPE _driverType;
	irr::scene::ISceneManager *_smgr;
	irr::video::IVideoDriver *_driver;
	irr::scene::ICameraSceneNode *_camera;
public:
	GraphicManager(irr::IrrlichtDevice *device);
	~GraphicManager();

	void render();
	bool isActive();
	void setCameraTarget(const irr::core::vector3df &pos);
	void setCameraPosition(const irr::core::vector3df &pos);

	irr::scene::ISceneNode *makeCubeNode(const Cube &cube);


	void createSkybox(std::string s);
	void drawCube(const Cube &cube);
	void drawSphere(const Sphere &sphere);
	void addToDeletionQueue(irr::scene::ISceneNode *node);
	irr::scene::ISceneManager *getSceneManager();
	irr::IrrlichtDevice *getDevice();
	irr::video::IVideoDriver  *getVideoDriver();
};