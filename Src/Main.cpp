/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "GraphicManager.hpp"
#include "BomberMan.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	ActionManager action;
	GraphicManager graphic(action);	
	Sphere cube(irr::core::vector3df(0,0,30), irr::core::vector3df(30,30,30), "/home/reimua/irrlicht-1.8.4/media/irrlichtlogoalpha2.tga");

	while(1) {
		graphic.drawSphere(cube);
		graphic.render();
	}
	return 0;
}