//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// Bomb class
//

#include "Bomb.hpp"
#include "Clock.hpp"
#include "Map.hpp"

Bomb::Bomb(char radius, char posX, char posY) : _radius(radius), _xMapPos(posX), _yMapPos(posY)
{

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
        elapsed = _clock.elapsedSeconds();
	if (elapsed >= 5)
		return 1;
	return 0;
}

void		Bomb::explode(Map &map)
{
	size_t i;

	for (i = 0; i < _radius && map.getCell(irr::core::vector2di(_xMapPos - i, _yMapPos)) == Map::Cell::Empty; i++)
		map.setCell(irr::core::vector2di(_xMapPos - i, _yMapPos), Map::Cell::Fire);
	if (map.getCell(irr::core::vector2di(_xMapPos - i, _yMapPos)) == Map::Cell::Breakable)
		map.setCell(irr::core::vector2di(_xMapPos - i, _yMapPos), Map::Cell::Fire);
	for (i = 0; i < _radius && map.getCell(irr::core::vector2di(_xMapPos + i, _yMapPos)) == Map::Cell::Empty; i++)
		map.setCell(irr::core::vector2di(_xMapPos + i, _yMapPos), Map::Cell::Fire);
	if (map.getCell(irr::core::vector2di(_xMapPos + i, _yMapPos)) == Map::Cell::Breakable)
		map.setCell(irr::core::vector2di(_xMapPos + i, _yMapPos), Map::Cell::Fire);
	for (i = 0; i < _radius && map.getCell(irr::core::vector2di(_xMapPos, _yMapPos - i)) == Map::Cell::Empty; i++)
		map.setCell(irr::core::vector2di(_xMapPos, _yMapPos - i), Map::Cell::Fire);
	if (map.getCell(irr::core::vector2di(_xMapPos, _yMapPos - i)) == Map::Cell::Breakable)
		map.setCell(irr::core::vector2di(_xMapPos, _yMapPos - i), Map::Cell::Fire);
	for (i = 0; i < _radius && map.getCell(irr::core::vector2di(_xMapPos, _yMapPos + i)) == Map::Cell::Empty; i++)
		map.setCell(irr::core::vector2di(_xMapPos, _yMapPos + i), Map::Cell::Fire);
	if (map.getCell(irr::core::vector2di(_xMapPos, _yMapPos + i)) == Map::Cell::Breakable)
		map.setCell(irr::core::vector2di(_xMapPos, _yMapPos + i), Map::Cell::Fire);
}
