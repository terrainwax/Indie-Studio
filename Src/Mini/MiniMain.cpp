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
#include "MiniSceneKonami.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	try
	{
		MiniCore core;

		core.add(new MiniSceneIntro());
		core.add(new MiniSceneMenu());
		core.add(new MiniSceneOptions());
		core.add(new MiniScenePlayers());
		core.add(new MiniSceneBomber());
		core.add(new MiniSceneVictory());
		core.add(new MiniSceneKonami());

		core.push("Intro");

		core.enter();
	}
	catch (const std::exception &e)
	{
		std::cout << "An error occured. Exit 84." << std::endl;
		return 84;
	}
	catch (const std::runtime_error *e)
	{
		std::cout << "An error occured. Exit 84." << std::endl;
		return 84;
	}

	return 0;
}
