//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// Bomb class
//

#include "Game.hpp"
#include "Bomb.hpp"
#include "Clock.hpp"
#include "Map.hpp"
#include <iostream>

Game::Game() :
_map(Map(13)),
_skyView(true)
{
}

Game::~Game()
{
}

std::vector<APlayer*>           Game::getPlayers() const
{
	return _players;
}

Map Game::getMap() const
{
	return _map;
}

bool Game::isOnGoing() const
{
	if (_players[0]->isAlive() == false)
		return false;
	for (int i = 1; i < _players.size(); i++) {
		if (_players[i]->isAlive() == true)
			return true;
	}
	return _players.size() == 1;
}

void Game::setPlayers(std::vector<APlayer*> players)
{
	_players = players;
}

void Game::setMap(Map& map)
{
	_map = map;
}

void Game::setSkyView(bool view)
{
	_skyView = view;
}

void Game::addPlayer(APlayer* player)
{
	_players.push_back(player);
}

void Game::updateMap()
{
	int size = _map.getSize();
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (_map.getCell(irr::core::vector2di(i, j)) == Map::Cell::PowerUp) {
				_map.setCell(irr::core::vector2di(i, j), Map::Cell::Empty);
				if (rand() % 3 == 0)
					addPowerUp(irr::core::vector3df(j * 10, 0, i * 10));
			}
		}
	}
}

void	Game::pickUpBonus(APlayer &player)
{
	irr::core::vector3df playerPos = player.getPos();
	for (int j = 0; j < _powersUp.size(); j++) {
		irr::core::vector3df pos = _powersUp[j].get()->getPosition();
		if (playerPos.X < pos.X + 5 && playerPos.X > pos.X - 5 && playerPos.Z < pos.Z + 5 && playerPos.Z > pos.Z - 5 ) {	
			_powersUp[j].get()->onPickUp(player);
			_powersUp.erase(_powersUp.begin() + j--);
		}
	}
}

void Game::triggerBomb()
{
	for (int i = 0; i < _bomb.size(); i++) {
		if (_bomb[i]->update()) {
			_map.setCell(irr::core::vector2di(_bomb[i]->getYMapPos() / 10, _bomb[i]->getXMapPos() / 10), Map::Cell::Empty);
			_bomb[i]->explode(_map, _players, _bomb);
			delete _bomb[i];
			_bomb.erase(_bomb.begin() + i--);
		}
	}
}

void Game::update(ActionManager& action, GraphicManager& graph)
{
	for (int i = 0; i < _players.size(); i++) {
		_players[i]->update(action, graph, _map, _bomb);
		this->pickUpBonus(*_players[i]);
	}
	this->triggerBomb();
	updateMap();
}

void Game::display(GraphicManager& _graph)
{
	_map.renderMap(_graph);
	for (int i = 0; i < _powersUp.size(); i++)
		_powersUp[i]->renderPowerUp(_graph);
	if (_skyView)
		_map.setCameraFocus(_graph);
	else
		_players[0]->setCameraFocus(_graph);
}

void Game::addPowerUp(irr::core::vector3df pos)
{
	std::unique_ptr<APowerUp> powerup;

	powerup = _factory.createRandomPowerUp();
	powerup->setPosition(pos);
	_powersUp.push_back(std::move(powerup));
}
