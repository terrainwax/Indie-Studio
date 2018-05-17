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
	Cube cube(irr::core::vector3df(0,0,30));

	while(1) {
		graphic.drawCube(cube);
		graphic.render();
	}
	return 0;
}