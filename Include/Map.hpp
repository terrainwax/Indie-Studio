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
	std::vector<std::string> _map;

	std::string makeLine(int size, int lineIdx);
public:
	Map(int size);
	~Map();

	void renderMap(GraphicManager &graph);

	enum Cell {
		Wall = '#',
		Breakable = 'B',
		Empty = ' ',
	};
};