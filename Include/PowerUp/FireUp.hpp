/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IPowerUp.hpp"

class FireUp : public IPowerUp {
public:
	FireUp();
	virtual ~FireUp();

	const std::string getName() override;
	void onPickUp(Player &player) override;
};