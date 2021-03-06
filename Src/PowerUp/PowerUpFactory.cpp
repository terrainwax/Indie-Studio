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
	_managerMap["LifeUp"] = FACTORY_BIND(&PowerUpFactory::createLifeUp);
	_managerMap["BombUp"] = FACTORY_BIND(&PowerUpFactory::createBombUp);
	_managerMap["FireUp"] = FACTORY_BIND(&PowerUpFactory::createFireUp);
	_managerMap["SpeedUp"] = FACTORY_BIND(&PowerUpFactory::createSpeedUp);
	_managerMap["FullFire"] = FACTORY_BIND(&PowerUpFactory::createFullFire);
	_managerMap["PierceUp"] = FACTORY_BIND(&PowerUpFactory::createPierceUp);
	_managerMap["WallPass"] = FACTORY_BIND(&PowerUpFactory::createWallPass);

	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createLifeUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createBombUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createFireUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createSpeedUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createFullFire));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createPierceUp));
	_managerVector.push_back(FACTORY_BIND(&PowerUpFactory::createWallPass));
}

PowerUpFactory::~PowerUpFactory()
{
}

std::unique_ptr<APowerUp>
PowerUpFactory::createRandomPowerUp()
{
	int i = rand() % _managerVector.size();

	return std::unique_ptr<APowerUp>(_managerVector[i]());
}

std::unique_ptr<APowerUp>
PowerUpFactory::createPowerUpFromName(const std::string &s)
{
	if (_managerMap.find(s) == _managerMap.end())
		throw std::invalid_argument("Unknow PowerUp");
	return std::unique_ptr<APowerUp>(_managerMap[s]());
}

APowerUp *PowerUpFactory::createLifeUp() const noexcept
{
	return new LifeUp;
}

APowerUp *PowerUpFactory::createBombUp() const noexcept
{
	return new BombUp;
}

APowerUp *PowerUpFactory::createFireUp() const noexcept
{
	return new FireUp;
}

APowerUp *PowerUpFactory::createSpeedUp() const noexcept
{
	return new SpeedUp;
}

APowerUp *PowerUpFactory::createFullFire() const noexcept
{
	return new FullFire;
}

APowerUp *PowerUpFactory::createPierceUp() const noexcept
{
	return new PierceUp;
}

APowerUp *PowerUpFactory::createWallPass() const noexcept
{
	return new WallPass;
}