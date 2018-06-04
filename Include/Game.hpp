//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// bomb class
//

#ifndef __GAME__
# define __GAME__

#include "APlayer.hpp"
#include "APowerUp.hpp"
#include "PowerUpFactory.hpp"

class Game
{
private:
	// ActionManager&		_actionManager;
	// GraphicManager&		_graphManager;
	std::vector<APlayer*>	_players;
	Map&			_map;
	PowerUpFactory		_factory;
	std::vector<std::unique_ptr<APowerUp>> _powersUp;

public:
	Game(Map&);
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
