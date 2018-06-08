/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniBase.hpp"

class IMiniCore {
public:
	IMiniCore() = default;
	virtual ~IMiniCore() = default;

	virtual void push(const std::string &sceneName) = 0;
	virtual void pop() = 0;
};