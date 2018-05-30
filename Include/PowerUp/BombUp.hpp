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

	void onPickUp(Player &player) override;
};