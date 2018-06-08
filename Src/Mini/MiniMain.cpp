/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniCore.hpp"
#include "MiniSceneIntro.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	MiniCore core;

	core.add(new MiniSceneIntro());

	core.push("Intro");
	core.push("Intro");
	core.push("Intro");

	core.enter();

	return 0;
}
