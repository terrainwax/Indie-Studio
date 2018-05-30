/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <stdexcept>
#include "PowerUpFactory.hpp"

PowerUpFactory::PowerUpFactory()
{
	_managerMap["BombUp"] = FACTORY_BIND(&PowerUpFactory::createBombUp);
	_managerMap["FireUp"] = FACTORY_BIND(&PowerUpFactory::createFireUp);
	_managerMap["SpeedUp"] = FACTORY_BIND(&PowerUpFactory::createSpeedUp);
	_managerMap["WallPass"] = FACTORY_BIND(&PowerUpFactory::createWallPass);

	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createBombUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createFireUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createSpeedUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createWallPass));
}

PowerUpFactory::~PowerUpFactory()
{
}

std::unique_ptr<IPowerUp>
PowerUpFactory::createRandomPowerUp()
{
	int i = rand() % _managerVector.size();

	return std::unique_ptr<IPowerUp>(_managerVector[i]());
}

std::unique_ptr<IPowerUp>
PowerUpFactory::createPowerUpFromName(const std::string &s)
{
	if (_managerMap.find(s) == _managerMap.end())
		throw std::invalid_argument("Unknow PowerUp");
	return std::unique_ptr<IPowerUp>(_managerMap[s]());
}

IPowerUp *PowerUpFactory::createBombUp() const noexcept
{
	return new BombUp;
}

IPowerUp *PowerUpFactory::createFireUp() const noexcept
{
	return new FireUp;
}

IPowerUp *PowerUpFactory::createSpeedUp() const noexcept
{
	return new SpeedUp;
}

IPowerUp *PowerUpFactory::createWallPass() const noexcept
{
	return new WallPass;
}