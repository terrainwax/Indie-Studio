/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <string>
#include "Player.hpp"

class IPowerUp {
public:
	virtual ~IPowerUp() = default;
	//model getModel ou un truc du genre
	virtual const std::string getName() = 0;
	virtual void onPickUp(Player &player) = 0;
};