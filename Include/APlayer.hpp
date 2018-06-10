//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// APlayer class
//

#pragma once

#include <string>
#include <vector>
#include "Map.hpp"
#include "Bomb.hpp"
#include "KeySet.hpp"
#include "ActionManager.hpp"
#include "GraphicManager.hpp"

class Bomb;

class APlayer {
protected:
	std::string	_name;
	float		_speed;
	char		_nbBomb;
	char		_fire;
	bool		_wallPass;
	float		_xPos;
	float		_yPos;
	irr::scene::IAnimatedMeshSceneNode* _anode;
	irr::scene::IAnimatedMesh* _mesh;
	irr::scene::ISceneManager *_smgr;
	GraphicManager	_graph;
	char 		_nbLife;
	bool 		_alive;
	bool		_pierce;

public:
	APlayer(irr::scene::ISceneManager *_smgr,
		std::string name = "APlayer",GraphicManager graph = nullptr, int nbBomb = 1, int fire = 1,
		float speed = 0.5, bool wallPass = false);
	~APlayer();

	//getters
	std::string	getName() const;
	float		getSpeed() const;
	char		getNbBomb() const;
	char		getNbLife() const;
	char		getFire() const;
	char		getLife() const;
	bool		getPierce() const;
	bool		getWallPass() const;
	bool		isAlive() const;
	irr::core::vector3df	getPos() const;

	//setters
	void		setFire(char);
	void		setWallPass(bool);
	void		setPierce(bool);
	void		setSpeed(float);
	void		setNbBomb(char);
	void		setNbLife(char);
	void 		die();
	void 		setCameraFocus(GraphicManager &graphicManager);

	virtual void	update(ActionManager &actionManager, GraphicManager &graph, Map &map, std::vector<Bomb *> &bomb) = 0;
};
