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

#ifndef SOUND
# define SOUND(x) (std::string("./Assets/Music/") + std::string(x))
#endif

class SoundManager {
private:
	irrklang::ISoundEngine *_engine;
	irrklang::ISound *_bgm;

public:
	SoundManager();
	~SoundManager();

	void stopBgm();
	void playBgm(std::string s);
	void playSound(std::string s);
};
