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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	MiniCore core;

	core.add(new MiniSceneIntro());
	core.add(new MiniSceneMenu());
	core.add(new MiniSceneOptions());
	core.add(new MiniScenePlayers());

	core.push("Intro");
	//core.push("Menu");

	core.enter();

	return 0;
}
