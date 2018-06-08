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

	virtual void quit() = 0;

	virtual irr::IrrlichtDevice *getVideoDevice() = 0;
	virtual irrklang::ISoundEngine *getAudioDevice() = 0;
};