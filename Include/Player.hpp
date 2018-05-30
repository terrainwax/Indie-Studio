//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class
//

#pragma once

#include <string>
#include "Map.hpp"
#include "ActionManager.hpp"

class Player {
private:
	std::string	_name;
	char		_speed;
	char		_nbBomb;
	char		_fire;
	bool		_wallPass;
	float		_xPos;
	float		_yPos;

public:
	Player(std::string name = "PlayerX");
	~Player();

	//getters
	std::string	getName() const;
	char		getSpeed() const;
	char		getNbBomb() const;
	char		getFire() const;
	bool		getWallPass() const;
	float		getXPos() const;
	float		getYPos() const;

	//setters
	void		setFire(char);
	void		setWallPass();
	void		setXPos(float);
	void		setSpeed(char);
	void		setYpos(float);
	void		setNbBomb(char);

	void		update(ActionManager &actionManager, Map &map);
};
