/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <iostream>
#include <stdexcept>
#include "Map.hpp"

Map::Map(int size)
{
	int lineNbr = size - 2;

	if (size < 5)
		throw std::invalid_argument("Map size is too small");
	_map.push_back(std::string(size, '#'));
	for (int i = 0; i < lineNbr; i++)
		_map.push_back(this->makeLine(size, i + 1));
	_map.push_back(std::string(size, '#'));
	for (unsigned int i = 0; i < _map.size(); i++)
		std::cout << _map[i] << std::endl;
}

Map::~Map()
{
}

std::string Map::makeLine(int size, int lineIdx)
{
	std::string s = std::string(size, ' ');

	s[0] = '#';
	s[s.size() - 1] = '#';
	if (lineIdx % 2 == 1)
		return s;
	for (int j = 0; j < size; j++) {
		s[j] = j % 2 == 0 ? '#' : ' ';
	}
	s[s.size() - 1] = '#';
	return s;
}