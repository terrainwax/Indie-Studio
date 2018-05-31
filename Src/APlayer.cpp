//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// APlayer class implementation
//

#include "APlayer.hpp"

APlayer::APlayer(std::string name, int nbBomb, int fire, int speed, bool wallPass) :
_name(name),
_nbBomb(nbBomb),
_fire(fire),
_speed(speed),
_wallPass(wallPass),
_keySet()
{
}

APlayer::~APlayer()
{
}

std::string	APlayer::getName() const
{
	return this->_name;
}

char		APlayer::getSpeed() const
{
	return this->_speed;
}

char		APlayer::getNbBomb() const
{
	return this->_nbBomb;
}

char		APlayer::getFire() const
{
	return this->_fire;
}

bool		APlayer::getWallPass() const
{
	return this->_wallPass;
}

void		APlayer::setSpeed(char speed)
{
	this->_speed = speed;
}

void		APlayer::setNbBomb(char nbBomb)
{
	_nbBomb = nbBomb;
}

void		APlayer::setFire(char fire)
{
	_fire = fire;
}

void		APlayer::setWallPass(bool wallPass)
{
	this->_wallPass = wallPass;
}