//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// APlayer class
//

#pragma once

#include <string>
#include "Map.hpp"
#include "ActionManager.hpp"

class APlayer {
protected:
	std::string	_name;
	char		_speed;
	char		_nbBomb;
	char		_fire;
	bool		_wallPass;
	float		_xPos;
	float		_yPos;
	irr::scene::IAnimatedMeshSceneNode* _anode;
	irr::scene::IAnimatedMesh* _mesh;

public:
	APlayer(std::string name = "APlayer", int nbBomb = 1, int fire = 1, int speed = 1, bool wallPass = false);
	~APlayer();

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
	void		setWallPass(bool);
	void		setXPos(float);
	void		setSpeed(char);
	void		setYpos(float);
	void		setNbBomb(char);

	virtual void	update(ActionManager &actionManager, Map &map) = 0;
};
