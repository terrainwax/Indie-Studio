/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniBase.hpp"

class MiniRectangle final {
public:
	MiniRectangle(std::size_t x = 0, std::size_t y = 0, std::size_t width = 0, std::size_t height = 0);
	~MiniRectangle();

	std::size_t x;
	std::size_t y;
	std::size_t width;
	std::size_t height;
};