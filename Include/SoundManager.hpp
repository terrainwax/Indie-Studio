//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// bomb class
//

#pragma once

#include <string>
#include <stdio.h>
#include <stdexcept>
#include <irrKlang.h>


class SoundManager {
private:
	irrklang::ISoundEngine* _engine;

public:
	SoundManager();
	~SoundManager();

	void playBgm(std::string s);
	void playSound(std::string s);
};
