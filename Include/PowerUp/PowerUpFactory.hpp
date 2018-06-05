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
#include "LifeUp.hpp"
#include "FireUp.hpp"
#include "BombUp.hpp"
#include "SpeedUp.hpp"
#include "WallPass.hpp"
#include "APowerUp.hpp"

#define POWERUP_BUILDER std::function<APowerUp *()>
#define FACTORY_BIND(x) std::bind(x, this)

class PowerUpFactory {
private:
	std::vector<POWERUP_BUILDER> _managerVector;
	std::map<std::string, POWERUP_BUILDER> _managerMap;

	APowerUp *createLifeUp() const noexcept;
	APowerUp *createFireUp() const noexcept;
	APowerUp *createBombUp() const noexcept;
	APowerUp *createSpeedUp() const noexcept;
	APowerUp *createWallPass() const noexcept;
public:
	PowerUpFactory();
	~PowerUpFactory();

	std::unique_ptr<APowerUp> createRandomPowerUp();
	std::unique_ptr<APowerUp> createPowerUpFromName(const std::string &s);
};