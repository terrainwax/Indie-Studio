/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <map>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include "FireUp.hpp"
#include "BombUp.hpp"
#include "SpeedUp.hpp"
#include "WallPass.hpp"
#include "IPowerUp.hpp"

#define POWERUP_BUILDER std::function<IPowerUp *()>
#define FACTORY_BIND(x) std::bind(x, this)

class PowerUpFactory {
private:
	std::vector<POWERUP_BUILDER> _managerVector;
	std::map<std::string, POWERUP_BUILDER> _managerMap;

	IPowerUp *createFireUp() const noexcept;
	IPowerUp *createBombUp() const noexcept;
	IPowerUp *createSpeedUp() const noexcept;
	IPowerUp *createWallPass() const noexcept;
public:
	PowerUpFactory();
	~PowerUpFactory();

	std::unique_ptr<IPowerUp> createRandomPowerUp();
	std::unique_ptr<IPowerUp> createPowerUpFromName(const std::string &s);
};