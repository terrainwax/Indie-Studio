//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class implementation
//

#include "Player.hpp"

Player::Player(std::string name)
	: _name(name), _speed(1), _nbBomb(1), _fire(1), _wallPass(false)
{

}

Player::~Player()
{
	
}

std::string	Player::getName() const
{
	return this->_name;
}

char		Player::getSpeed() const
{
	return this->_speed;
}

char		Player::getNbBomb() const
{
	return this->_nbBomb;
}

char		Player::getFire() const
{
	return this->_fire;
}

bool		Player::getWallPass() const
{
	return this->_wallPass;
}

void		Player::setSpeed(char speed)
{
	this->_speed = speed;
}

void		Player::setNbBomb(char nbBomb)
{
	_nbBomb = nbBomb;
}

void		Player::setFire(char fire)
{
	_fire = fire;
}

void		Player::setWallPass(bool wallPass)
{
	this->_wallPass = wallPass;
}

void		Player::update(ActionManager &actionManager, Map &map)
{
	(void)map;
	(void)actionManager;
}