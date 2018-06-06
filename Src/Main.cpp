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
#include "SoundManager.hpp"
#include "GraphicManager.hpp"
#include "PowerUpFactory.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	srand(time(NULL));
	SoundManager sound;
	ActionManager action;
	GraphicManager graphic(action);
	graphic.createSkybox("Assets/Textures/skyfield.jpg");
	Game game;
	game.addPlayer(new Player(1, 1, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet1));
	game.addPlayer(new Player(1, 1, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet2));
	game.addPlayer(new Player(1, 2, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet2));

	sound.playBgm("./Assets/Music/GroSonSaRace.wav");
	while (graphic.isActive() &&
		game.isOnGoing() &&
		action.isKeyPressed(irr::KEY_KEY_A) != true) {
		game.display(graphic);
		game.update(action, graphic);
		graphic.render();
	}
	return 0;
}
