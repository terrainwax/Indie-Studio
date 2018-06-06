/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "APowerUp.hpp"

class PierceUp : public APowerUp {
private:
public:
	PierceUp();
	virtual ~PierceUp();

	void onPickUp(APlayer &player) override;
};