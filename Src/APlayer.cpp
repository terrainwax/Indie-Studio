//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// APlayer class implementation
//

#include "APlayer.hpp"

APlayer::APlayer(irr::scene::ISceneManager *smgr, std::string name,GraphicManager graph, int nbBomb, int fire, float speed, bool wallPass) :
_smgr(smgr),
_name(name),
_speed(speed),
_nbBomb(nbBomb),
_fire(fire),
	_graph(graph),
_wallPass(wallPass),
_nbLife(0),
_alive(true),
_pierce(false)
{
}

APlayer::~APlayer()
{
	if (_anode != nullptr)
		_smgr->addToDeletionQueue(_anode);
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

char		APlayer::getNbLife() const
{
	return this->_nbLife;
}

char		APlayer::getFire() const
{
	return this->_fire;
}

irr::core::vector3df		APlayer::getPos() const
{
	if (_anode == nullptr)
		return irr::core::vector3df(0, 0, 0);
	return _anode->getPosition();
}

bool		APlayer::getPierce() const
{
	return _pierce;
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

void		APlayer::setNbLife(char life)
{
	_nbLife = life;
}

void		APlayer::setWallPass(bool wallPass)
{
	this->_wallPass = wallPass;
}

void APlayer::setPierce(bool pierce)
{
	_pierce = pierce;
}

void APlayer::die()
{
	if (_nbLife == 0)
		_alive = false;
	else
		_nbLife--;
}

bool APlayer::isAlive() const
{
	return _alive;
}

void APlayer::setCameraFocus(GraphicManager &graphicManager)
{
	if (_anode == nullptr)
		return;

	irr::core::vector3df pos = _anode->getPosition();

	graphicManager.setCameraTarget(pos);
	graphicManager.setCameraPosition(irr::core::vector3df(pos.X, pos.Y + 40 , pos.Z - 40));
}
