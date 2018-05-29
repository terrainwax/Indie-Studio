//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class
//

#ifndef __PLAYER__
# define __PLAYER__

class Player
{
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
	void		setSpeed(char);
	void		incNbBomb();
	void		incFire();
	void		setWallPass();
	void		setXPos(float);
	void		setYpos(float);

	void		run();

private:
	void		moveLeft(float);
	void		moveRight(float);
	void		moveUp(float);
	void		moveDown(float);
};

#endif // __PLAYER__
