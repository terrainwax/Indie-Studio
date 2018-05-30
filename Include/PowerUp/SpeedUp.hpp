/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IPowerUp.hpp"

class SpeedUp : public IPowerUp {
public:
	SpeedUp();
	virtual ~SpeedUp();

	void onPickUp(Player &player) override;
};