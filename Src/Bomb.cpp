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

Bomb::Bomb(char radius, int posX, int posY, irr::scene::ISceneManager *_smgr) : _radius(radius), _xMapPos(posX), _yMapPos(posY)
{
	printf("%d %d\n", posX, posY);
	node = _smgr->addMeshSceneNode(_smgr->getMesh("./Assets/Models/bombtext.obj"));
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, false);
	node->setRotation(irr::core::vector3df(0, 0, 0));
	node->setPosition(irr::core::vector3df(posX ,
		-2, posY));
	node->setScale(irr::core::vector3df(4, 4, 4));
}

Bomb::~Bomb()
{

}

char            Bomb::getRadius() const
{
	return _radius;
}

char            Bomb::getXMapPos() const
{
	return _xMapPos;
}

char		Bomb::getYMapPos() const
{
	return _yMapPos;
}

void            Bomb::setRadius(const char radius)
{
	_radius = radius;
}

void            Bomb::setXMapPos(const char pos)
{
	_xMapPos = pos;
}

void            Bomb::setYMappos(const char pos)
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


	node->setScale(0.125 * 4 * irr::core::vector3df(result,
		result, result) + 4);
	if (elapsed >= 3000) {
		return 1;
	}
	return 0;
}

void		Bomb::explode(Map &map)
{
	bool zn = false;
	bool zs = false;
	bool xo = false;
	bool xe = false;
	std::cout <<  (_xMapPos / 10) << " " << (_yMapPos / 10) << std::endl;
	for (int y = 0; y < 3 ; y++)
	{
		for(int x = 0 ;x < 3; x++)
		{

			if(map.getCell(irr::core::vector2di((_yMapPos / 10 - 1 + x),
				(_xMapPos / 10 - 1 + y))) == (Map::Cell::Breakable))
			{
				if (y == 0 && x == 1)
					xo = true;
				else if (y == 1 && x == 0)
					zs = true;
				else if (y == 1 && x == 2)
					zn = true;
				else if (y == 2 && x == 1)
					xe = true;
			}
		}
	}
	for (int i = 0; i <= _radius; i++)
	{
		if (zs)
			map.setCell(irr::core::vector2di((_yMapPos / 10 ) - i, (_xMapPos / 10)), Map::Cell::Empty);
		if (zn)
			map.setCell(irr::core::vector2di((_yMapPos / 10) + i, (_xMapPos / 10)), Map::Cell::Empty);
		if (xo)
			map.setCell(irr::core::vector2di((_yMapPos / 10), (_xMapPos / 10) - i), Map::Cell::Empty);
		if (xe)
			map.setCell(irr::core::vector2di((_yMapPos / 10 ), (_xMapPos / 10) + i), Map::Cell::Empty);
	}

}

irr::scene::ISceneNode *Bomb::getNode()
{
	return node;
}