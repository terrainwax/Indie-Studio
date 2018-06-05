/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <ctime>
#include "Game.hpp"
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
	Player *player = new Player("test", graphic.getSceneManager());
	Game game(graphic, map);

	game.addPlayer(player);
	while (graphic.isActive() && action.isKeyPressed(irr::KEY_KEY_A) != true) {
		game.display(graphic);
		game.update(action, graphic);
		graphic.render();
	}
	return 0;
}
