//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// bomb class
//

#ifndef __BOMB__
# define __BOMB__

#include "Clock.hpp"

class Map;

class Bomb
{
private:
	char		_radius;
	char		_xMapPos;
	char		_yMapPos;
	Clock		_clock;

public:
	Bomb(char, char, char);
	~Bomb();

	//getters
	char		getRadius() const;
	char		getXMapPos() const;
	char		getYMapPos() const;

	//setters
	void		setRadius(const char);
	void		setXMapPos(const char);
	void		setYMappos(const char);

	int		update();
	void		explode(Map&);
};

#endif // __BOMB__
