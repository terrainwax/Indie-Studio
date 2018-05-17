/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "Sphere.hpp"

Sphere::Sphere(irr::core::vector3df pos_,
	irr::core::vector3df rotation_,
	std::string texture_) :
texture(texture_),
pos(pos_),
rotation(rotation_)
{
}

Sphere::~Sphere()
{
}