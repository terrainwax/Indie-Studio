/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "Map.hpp"
#include "GraphicManager.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	if (argc != 2)
		return 84;
	Map map(atoi(argv[1]));
	ActionManager action;
	GraphicManager graphic(action);	

	graphic.setCameraPosition(irr::core::vector3df(40, 40, 0));
	graphic.setCameraRotation(irr::core::vector3df(3.14 / 2, 3.14 / 2, 3.14 / 2));
	while(1) {
		map.renderMap(graphic);
		graphic.render();
	}
	return 0;
}