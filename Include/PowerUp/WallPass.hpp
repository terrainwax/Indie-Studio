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

	const std::string getName() override;
	void onPickUp(Player &player) override;
};