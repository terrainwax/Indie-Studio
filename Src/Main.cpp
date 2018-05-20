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
	if (argc != 2)
		return 84;
	Map map(atoi(argv[1]));
	ActionManager action;
	GraphicManager graphic(action);	

	graphic.setCameraPosition(irr::core::vector3df(40, 40, 0));
	graphic.setCameraTarget(irr::core::vector3df(40, 0, 40));
	while(1) {
		map.renderMap(graphic);
		graphic.render();
	}
	return 0;
}