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

	const std::string getName() override;
	void onPickUp(Player &player) override;
};