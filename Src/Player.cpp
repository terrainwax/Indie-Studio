//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class implementation
//

#include "Player.hpp"

Player::Player(std::string name, irr::scene::ISceneManager *_smgr)
	: _name(name), _speed(1), _nbBomb(1), _fire(1), _wallPass(false)
{
	_mesh = _smgr->getMesh("./Assets/Models/0112.x");


	_anode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_anode->setPosition(irr::core::vector3df(10,0,20));
	_anode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, false);
	_anode->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
	_anode->setAnimationSpeed(15);
	_anode->setRotation(irr::core::vector3df(-90,0,0));
	_anode->setScale(irr::core::vector3df(0.008,0.008,0.008));
	_anode->setFrameLoop(0, 90);
	//anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
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