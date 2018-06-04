//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// bomb class
//

#pragma once

#include <irrlicht.h>
#include "Clock.hpp"
#include "APlayer.hpp"

class Map;
class APlayer;

class Bomb
{
private:
	irr::scene::ISceneManager *_smgr;
	APlayer& 	_player;
	char		_radius;
	int		_xMapPos;
	int		_yMapPos;
	Clock		_clock;
	irr::scene::ISceneNode *_node;

	void lineExplosion(Map &map, int incX, int incY);

	public:
	Bomb(APlayer &player, irr::scene::ISceneManager *);
	~Bomb();

	//getters
	char		getRadius() const;
	char		getXMapPos() const;
	char		getYMapPos() const;
	irr::scene::ISceneNode * getNode();

	//setters
	void		setRadius(const char);
	void		setXMapPos(const char);
	void		setYMappos(const char);


	int		update();
	void		explode(Map&);
};
