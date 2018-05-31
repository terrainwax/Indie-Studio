/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <string>

#include "Cube.hpp"
#include "Player.hpp"
#include "GraphicManager.hpp"

class APowerUp {
protected:
	std::string _name;
	Cube _cube;
public:
	APowerUp(const std::string &name);
	virtual ~APowerUp() = default;

	const std::string getName();
	virtual void onPickUp(Player &player) = 0;
	void renderPowerUp(GraphicManager &graphicManager);
};