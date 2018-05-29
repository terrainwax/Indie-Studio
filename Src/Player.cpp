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

void		Player::incNbBomb()
{
	this->_nbBomb++;
}

void		Player::incFire()
{
	this->_fire++;
}

void		Player::setWallPass()
{
	this->_wallPass = true;
}

void		Player::run()
{

}

void		Player::moveLeft(float decr)
{
	this->_xPos -= decr;
}

void		Player::moveRight(float incr)
{
	this->_xPos += incr;
}

void		Player::moveUp(float decr)
{
	this->yPos -= decr;
}

void		Player::moveDown(float incr)
{
	this->yPos += incr;
}