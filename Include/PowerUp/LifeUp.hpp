/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "APowerUp.hpp"

class LifeUp : public APowerUp {
private:
public:
	LifeUp();
	virtual ~LifeUp();

	void onPickUp(APlayer &player) override;
};