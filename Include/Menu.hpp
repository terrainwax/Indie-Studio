#pragma once

#include <stdexcept>

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#include <Keycodes.h>
#include <IEventReceiver.h>
#pragma GCC diagnostic warning "-Wunused-parameter"

#include "ActionManager.hpp"
#include "SoundManager.hpp"
#include "Game.hpp"

class Menu
{
public:
	Menu(irr::IrrlichtDevice *device, ActionManager *action, SoundManager *sound);
	~Menu();
	void run();
	void chooseScreen();
	void launchGame();
	void launchOptions();

private:
	irr::IrrlichtDevice *_device;
	ActionManager *_actions;
	SoundManager *_sounds;
};
