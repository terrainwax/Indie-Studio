/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "Cube.hpp"

Cube::Cube(irr::core::vector3df pos_,
	irr::core::vector3df scale_,
	irr::core::vector3df rotation_,
	std::string texture_) :
texture(texture_),
pos(pos_),
scale(scale_),
rotation(rotation_)
{
}

Cube::~Cube()
{
}