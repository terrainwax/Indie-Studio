//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// Bomb class
//

#include <sstream>
#include <iostream>
#include "Bomb.hpp"
#include "Clock.hpp"
#include "Map.hpp"

# define PI           3.14159265358979323846

Bomb::Bomb(APlayer &player, irr::scene::ISceneManager *smgr) :
_smgr(smgr),
_player(player),
_radius(player.getFire()),
_xMapPos((int)((player.getPos().X / 10) + 0.5) * 10),
_yMapPos((int)((player.getPos().Z / 10) + 0.5) * 10)
{
	_node = _smgr->addMeshSceneNode(_smgr->getMesh("./Assets/Models/bombtext.obj"));
	_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, false);
	_node->setRotation(irr::core::vector3df(0, 0, 0));
	_node->setPosition(irr::core::vector3df(_xMapPos, -2, _yMapPos));
	_node->setScale(irr::core::vector3df(4, 4, 4));
}

Bomb::~Bomb()
{
	_smgr->addToDeletionQueue(_node);
	_player.setNbBomb(_player.getNbBomb() + 1);
}

char            Bomb::getRadius() const
{
	return _radius;
}

int            Bomb::getXMapPos() const
{
	return _xMapPos;
}

int		Bomb::getYMapPos() const
{
	return _yMapPos;
}

void            Bomb::setRadius(const char radius)
{
	_radius = radius;
}

void            Bomb::setXMapPos(const int pos)
{
	_xMapPos = pos;
}

void            Bomb::setYMappos(const int pos)
{
	_yMapPos = pos;
}

int		Bomb::update()
{
	size_t elapsed;

	_clock.tick();
	elapsed = _clock.elapsedMilliseconds();
	irr::u32 timetoexplode = static_cast<irr::u32>(3000 - elapsed);
	int bouncer = 3000 / 1000;
	double param, result;
	param = 360 * timetoexplode / 3000;
	result = cos(param * bouncer * PI / 180);


	_node->setScale(0.125 * 4 * irr::core::vector3df(result,
		result, result) + 4);
	if (elapsed >= 3000) {
		return 1;
	}
	return 0;
}

void Bomb::lineExplosion(Map &map, int incX, int incY)
{
	int posX = _xMapPos / 10;
	int posY = _yMapPos / 10;
	for (int i = 0; i < _radius; i++) {
		posX += incX;
		posY += incY;
		if (map.getCell(irr::core::vector2di(posY, posX)) == Map::Cell::Breakable) {
			map.setCell(irr::core::vector2di(posY, posX), Map::Cell::PowerUp);
			return;
		}
		if (map.getCell(irr::core::vector2di(posY, posX)) != Map::Cell::Empty)
			return;
	}
}

void Bomb::playerExplosion(APlayer *player)
{
	irr::core::vector3df pos = player->getPos();
	int playerPosX = (int)(pos.X / 10 + 0.5);
	int playerPosY = (int)(pos.Z / 10 + 0.5);
	if (playerPosY == _yMapPos / 10) {
		if (playerPosX >= _xMapPos / 10 - _radius && playerPosX <= _xMapPos / 10 + _radius)
			player->die();
	}
	if (playerPosX == _xMapPos / 10) {
		if (playerPosY >= _yMapPos / 10 - _radius && playerPosY <= _yMapPos / 10 + _radius)
			player->die();
	}
}

void	Bomb::explode(Map &map, std::vector<APlayer *> &players, std::vector<Bomb *> &bomb)
{
	(void)bomb;
	this->lineExplosion(map,  1,  0);
	this->lineExplosion(map, -1,  0);
	this->lineExplosion(map,  0,  1);
	this->lineExplosion(map,  0, -1);
	for (int i = 0; i < players.size(); i++)
		this->playerExplosion(players[i]);
}

irr::scene::ISceneNode *Bomb::getNode()
{
	return _node;
}