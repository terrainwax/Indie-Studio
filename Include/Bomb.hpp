//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// bomb class
//

#pragma once

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic warning "-Wunused-parameter"

#include "Clock.hpp"
#include "APlayer.hpp"
#include "ParticleFire.hpp"

class Map;
class APlayer;

class Bomb
{
private:
	irr::scene::ISceneManager *_smgr;
	APlayer& 	_player;
	char		_radius;
	bool 		_pierce;
	int		_xMapPos;
	int		_yMapPos;
	Clock		_clock;
	irr::scene::ISceneNode *_node;
	GraphicManager	_graph;

	void lineExplosion(Map &map, int incX, int incY, std::vector<APlayer *> &, std::vector<ParticleFire*> &particles);
	void playersExplosion(std::vector<APlayer *> &players, int posX, int posY);


	public:
	Bomb(APlayer &player, irr::scene::ISceneManager *, GraphicManager graph);
	~Bomb();

	//getters
	char		getRadius() const;
	int		getXMapPos() const;
	int		getYMapPos() const;
	irr::scene::ISceneNode * getNode();

	//setters
	void		setRadius(const char);
	void		setXMapPos(const int);
	void		setYMappos(const int);


	int		update();
	void		explode(Map&, std::vector<APlayer *> &players, std::vector<Bomb *> &bomb, std::vector<ParticleFire*> &particles);
};
