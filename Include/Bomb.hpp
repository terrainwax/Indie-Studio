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

	void lineExplosion(Map &map, int incX, int incY, std::vector<APlayer *> &);
	void playersExplosion(std::vector<APlayer *> &players, int posX, int posY);


	public:
	Bomb(APlayer &player, irr::scene::ISceneManager *);
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
	void		explode(Map&, std::vector<APlayer *> &players, std::vector<Bomb *> &bomb);
};
