/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <ctime>
#include "Map.hpp"
#include "BombUp.hpp"
#include "GraphicManager.hpp"
#include "PowerUpFactory.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 84;
	srand(time(NULL));
	Map map(atoi(argv[1]));
	ActionManager action;
	GraphicManager graphic(action);	

	PowerUpFactory factory;
	printf("%s\n", factory.createRandomPowerUp().get()->getName().c_str());
	graphic.setCameraPosition(irr::core::vector3df(40, 40, 0));
	graphic.setCameraTarget(irr::core::vector3df(40, 0, 40));
	while (graphic.isActive() && action.isKeyPressed(irr::KEY_KEY_Q) != true) {
		map.renderMap(graphic);
		graphic.render();
	}
	return 0;
}