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

#include "ActionManager.hpp"
#include "SoundManager.hpp"
#include "Game.hpp"

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

private:
	bool			_com[PLAYER_NUMBER];
	irr::IrrlichtDevice	*_device;
	ActionManager		*_actions;
	SoundManager		*_sounds;
};
