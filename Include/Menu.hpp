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

#include "AI.hpp"
#include "Game.hpp"
#include "SoundManager.hpp"
#include "ActionManager.hpp"

#define PLAYER_NUMBER 4

class Menu
{
public:
	Menu(irr::IrrlichtDevice *device, ActionManager *action, SoundManager *sound);
	~Menu();

	void run();
	void chooseScreen();
	void launchGame();
	void launchPlayerChoice();
	void launchOptions();
	void togglePlayer(char player);
	void addPlayer(Game &game, GraphicManager &graphics, int mapSize);


private:
	bool			_com[PLAYER_NUMBER];
	irr::IrrlichtDevice	*_device;
	ActionManager		*_actions;
	SoundManager		*_sounds;
};

void displayChecks(irr::video::IVideoDriver *driver, irr::video::ITexture *com1, irr::video::ITexture *com2, irr::video::ITexture *com3, irr::video::ITexture *com4, irr::video::SColor *blanc);
