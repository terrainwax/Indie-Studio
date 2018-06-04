/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "APowerUp.hpp"

class BombUp : public APowerUp {
private:
public:
	BombUp();
	virtual ~BombUp();

	void onPickUp(APlayer &player) override;
};