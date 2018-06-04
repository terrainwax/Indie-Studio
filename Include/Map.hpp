/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <string>
#include <vector>

#include "GraphicManager.hpp"

class Map final {
private:
	int _mapSize;
	std::vector<std::string> _map;

	void checkBound(irr::core::vector2di pos);
	std::string makeLine(int size, int lineIdx);
public:
	Map(int size, int density = 40);
	~Map();

	enum Cell {
		Wall = '#',
		Breakable = 'B',
		Empty = ' ',
		Bomb = 'E',
		DFL = 0
	};
	Cell getCell(irr::core::vector2di pos);
	void setCell(irr::core::vector2di pos, Cell cell);
	void renderMap(GraphicManager &graph);
	irr::core::vector3df getCenter() const;

};
