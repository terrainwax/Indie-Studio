/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "APowerUp.hpp"

class SpeedUp : public APowerUp {
private:
public:
	SpeedUp();
	virtual ~SpeedUp();

	void onPickUp(Player &player) override;
};