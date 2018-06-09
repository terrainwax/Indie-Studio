/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniCore.hpp"
#include "MiniSceneIntro.hpp"
#include "MiniSceneMenu.hpp"
#include "MiniSceneOptions.hpp"
#include "MiniScenePlayers.hpp"
#include "MiniSceneBomber.hpp"
#include "MiniSceneVictory.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	MiniCore core;

	core.add(new MiniSceneIntro());
	core.add(new MiniSceneMenu());
	core.add(new MiniSceneOptions());
	core.add(new MiniScenePlayers());
	core.add(new MiniSceneBomber());
	core.add(new MiniSceneVictory());

	core.push("Intro");

	core.enter();

	return 0;
}
