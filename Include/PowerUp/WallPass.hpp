/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IPowerUp.hpp"

class WallPass : public IPowerUp {
public:
	WallPass();
	virtual ~WallPass();

	void onPickUp(Player &player) override;
};