/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <iostream>
#include <stdexcept>
#include "Map.hpp"

Map::Map(int size, int density)
{
	int lineNbr = size - 2;
	std::vector<irr::core::vector2di> breakableSpawn;

	_mapSize = size;
	if (size < 5)
		throw std::invalid_argument("Map size is too small");
	_map.push_back(std::string(size, Wall));
	for (int i = 0; i < lineNbr; i++)
		_map.push_back(this->makeLine(size, i + 1));
	_map.push_back(std::string(size, Wall));
	for (int i = 0; i < lineNbr; i++)
		for (int j = 0; j < lineNbr; j++)
			if (i > 1 && j > 1 && i < lineNbr && j < lineNbr && _map[i][j] != Wall)
				breakableSpawn.push_back(irr::core::vector2di(i, j));
	for (unsigned int i = 0; i < breakableSpawn.size(); i++)
		if (rand() % 100 <= density)
			_map[breakableSpawn[i].X][breakableSpawn[i].Y] = Breakable;
}

Map::~Map()
{
}

std::string Map::makeLine(int size, int lineIdx)
{
	std::string s = std::string(size, Empty);

	s[0] = Wall;
	s[s.size() - 1] = Wall;
	if (lineIdx % 2 == 1)
		return s;
	for (int j = 0; j < size; j++)
		s[j] = j % 2 == 0 ? Wall : Empty;
	s[s.size() - 1] = Wall;
	return s;
}

void Map::renderMap(GraphicManager &graph)
{
	Cube wall(irr::core::vector3df(0,0,30), irr::core::vector3df(1, 1, 1), irr::core::vector3df(0, 0, 0), TEXTURE("Wall.jpg"));
	Cube grass(irr::core::vector3df(0,0,30), irr::core::vector3df(1, 0.1, 1), irr::core::vector3df(0, 0, 0), TEXTURE("Grass.jpg"));
	Cube breakable(irr::core::vector3df(0,0,30), irr::core::vector3df(1, 1, 1), irr::core::vector3df(0, 0, 0), TEXTURE("Breakable.jpg"));

	for (unsigned int i = 0; i < _map.size(); i++) {
		for (unsigned int j = 0; j < _map[j].size(); j++) {
			if (_map[i][j] == Wall) {
				wall.pos = irr::core::vector3df(i * 10, 0, j * 10);
				graph.drawCube(wall);
			} else if (_map[i][j] == Breakable) {
				breakable.pos = irr::core::vector3df(i * 10, 0, j * 10);
				graph.drawCube(breakable);
			}
			grass.pos = irr::core::vector3df(i * 10, 0 - 10 / 2, j * 10);
			graph.drawCube(grass);
		}
	}
}

void Map::checkBound(irr::core::vector2di pos)
{
	if (pos.X < 0 || pos.Y < 0 || pos.X >= _mapSize || pos.Y >= _mapSize)
		throw std::invalid_argument("Invalid x or y : Out of bound");
}

Map::Cell Map::getCell(irr::core::vector2di pos)
{
	Map::Cell cell[] = {
		Wall,
		Empty,
		Breakable,
		DFL,
	};
	this->checkBound(pos);
	for (int i = 0; cell[i] != DFL; i++)
		if (_map[pos.Y][pos.X] == cell[i])
			return cell[i];
	return DFL;
}

void Map::setCell(irr::core::vector2di pos, Map::Cell cell)
{
	this->checkBound(pos);
	_map[pos.Y][pos.X] = cell;
}