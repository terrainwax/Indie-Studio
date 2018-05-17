/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-function"
#include <irrlicht.h>
#pragma GCC diagnostic warning "-Wunused-function"
#pragma GCC diagnostic warning "-Wunused-parameter"

#include <string>

#ifndef DFL_VECTOR
# define DFL_VECTOR irr::core::vector3df(0, 0 , 0)
#endif

class Cube {
public:
	Cube(irr::core::vector3df pos = DFL_VECTOR,
		irr::core::vector3df rotation = DFL_VECTOR,
		std::string texture = "");
	~Cube();

	std::string texture;
	irr::core::vector3df pos;
	irr::core::vector3df rotation;
};