/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <ctime>
#include "AI.hpp"
#include "Map.hpp"
#include "Game.hpp"
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
	game.setSkyView(false);
	game.addPlayer(new Player(4, 1, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet1));
	game.addPlayer(new Player(4, 1, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet2));

	sound.playBgm(SOUND("GroSonSaRace.ogg"));
	while (graphic.isActive() && game.isOnGoing()) {
		game.display(graphic);
		game.update(action, graphic, sound);
		graphic.render();
	}
	return 0;
}
