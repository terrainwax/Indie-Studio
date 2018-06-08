/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniCore.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	MiniCore core;

	core.add(MiniSceneIntro());

	core.push("Intro");

	core.enter();

	return 0;
}
