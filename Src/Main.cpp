/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <ctime>
#include "Menu.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	srand(time(NULL));

	SoundManager sounds;
	ActionManager actions;

	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL,
	irr::core::dimension2d<irr::u32>(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_BITS, false, false, false, &actions);

	Menu menu(device, &actions, &sounds);

	menu.run();

	device->drop();

	return 0;
}
