/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "APowerUp.hpp"

class FireUp : public APowerUp {
private:
public:
	FireUp();
	virtual ~FireUp();

	void onPickUp(Player &player) override;
};