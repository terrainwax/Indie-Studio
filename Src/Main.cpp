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
	irr::core::vector3df center = map.getCenter();

	PowerUpFactory factory;
	std::unique_ptr<APowerUp> powerUp = factory.createRandomPowerUp();
	Player player("test", graphic.getSceneManager());
	while (graphic.isActive() && action.isKeyPressed(irr::KEY_KEY_A) != true) {
		map.renderMap(graphic);
		powerUp.get()->renderPowerUp(graphic);
		player.update(action, map);
		player.setCameraFocus(graphic);
		graphic.render();
	}
	return 0;
}