//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// APlayer class implementation
//

#include "APlayer.hpp"

APlayer::APlayer(std::string name, int nbBomb, int fire, float speed, bool wallPass) :
_name(name),
_nbBomb(nbBomb),
_fire(fire),
_speed(speed),
_wallPass(wallPass)
{
}

APlayer::~APlayer()
{
}

std::string	APlayer::getName() const
{
	return this->_name;
}

float		APlayer::getSpeed() const
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

irr::core::vector3df		APlayer::getPos() const
{
	return _anode->getPosition();
}

bool		APlayer::getWallPass() const
{
	return this->_wallPass;
}

void		APlayer::setSpeed(float speed)
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