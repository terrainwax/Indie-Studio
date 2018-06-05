//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// bomb class
//

#ifndef __GAME__
# define __GAME__

#include "Bomb.hpp"
#include "APlayer.hpp"
#include "APowerUp.hpp"
#include "PowerUpFactory.hpp"

class Game
{
private:
	std::vector<APlayer*>	_players;
	Map&			_map;
	PowerUpFactory		_factory;
	std::vector<std::unique_ptr<APowerUp>> _powersUp;
	std::vector<Bomb *> _bomb;
	irr::scene::ISceneNode* skydome;
	

	void pickUpBonus(APlayer &player);
	void triggerBomb();

public:
	Game(GraphicManager&, Map&);
	~Game();

	//getters
	std::vector<APlayer*>		getPlayers() const;
	Map&				getMap() const;

	//setters
	void				setPlayers(std::vector<APlayer*>);
	void				setMap(Map&);

	void				addPlayer(APlayer*);
	void				addPowerUp(irr::core::vector3df);
	void				update(ActionManager&, GraphicManager&);
	void				updateMap();
	void				display(GraphicManager&);

private:
};

#endif // __Game__
