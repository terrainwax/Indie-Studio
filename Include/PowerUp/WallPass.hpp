/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "APowerUp.hpp"

class WallPass : public APowerUp {
private:
public:
	WallPass();
	virtual ~WallPass();

	void onPickUp(APlayer &player) override;
};