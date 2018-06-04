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

class Bomb
{
private:
	char		_radius;
	int		_xMapPos;
	int		_yMapPos;
	Clock		_clock;
	irr::scene::ISceneNode *node;

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
