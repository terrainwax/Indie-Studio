/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IPowerUp.hpp"

class BombUp : public IPowerUp {
public:
	BombUp();
	virtual ~BombUp();

	const std::string getName() override;
	void onPickUp(Player &player) override;
};