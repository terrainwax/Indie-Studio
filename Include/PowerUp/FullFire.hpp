/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "APowerUp.hpp"

class FullFire : public APowerUp {
private:
public:
	FullFire();
	virtual ~FullFire();

	void onPickUp(APlayer &player) override;
};