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
	(void)argc;
	(void)argv;
	srand(time(NULL));
	ActionManager action;
	GraphicManager graphic(action);
	Game game(graphic);
	game.addPlayer(new Player("test", graphic.getSceneManager()));

	while (graphic.isActive() && action.isKeyPressed(irr::KEY_KEY_A) != true) {
		game.display(graphic);
		game.update(action, graphic);
		graphic.render();
	}
	return 0;
}
