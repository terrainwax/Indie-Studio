/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <stdexcept>
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-function"
#include <irrlicht.h>
#include <Keycodes.h>
#include <IEventReceiver.h>
#pragma GCC diagnostic warning "-Wunused-function"
#pragma GCC diagnostic warning "-Wunused-parameter"

#include "ActionManager.hpp"

class BomberMan final {
public:
	BomberMan();
	~BomberMan();

	bool run();
public:
	ActionManager _action;
	irr::IrrlichtDevice *_device;
	irr::video::E_DRIVER_TYPE _driverType;
};