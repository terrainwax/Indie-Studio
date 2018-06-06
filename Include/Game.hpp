//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// bomb class
//

#pragma once

#include "Bomb.hpp"
#include "APlayer.hpp"
#include "APowerUp.hpp"
#include "SoundManager.hpp"
#include "PowerUpFactory.hpp"

class Game
{
private:
	std::vector<APlayer*>	_players;
	Map			_map;
	PowerUpFactory		_factory;
	std::vector<std::unique_ptr<APowerUp>> _powersUp;
	std::vector<Bomb *> _bomb;
	irr::scene::ISceneNode* skydome;
	bool 	_skyView;

	void pickUpBonus(APlayer &player);
	void triggerBomb(SoundManager &sound);

public:
	Game();
	~Game();

	bool isOnGoing() const;
	//getters
	Map getMap() const;
	std::vector<APlayer*> getPlayers() const;

	//setters
	void setPlayers(std::vector<APlayer*>);
	void setMap(Map&);

	void setSkyView(bool view);
	void addPlayer(APlayer*);
	void addPowerUp(irr::core::vector3df);
	void update(ActionManager&, GraphicManager&, SoundManager&);
	void updateMap();
	void display(GraphicManager&);
};
