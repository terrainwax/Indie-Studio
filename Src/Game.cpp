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

Game::Game(// ActionManager& _action, GraphicManager& _graph, 
	   Map& map) : // _actionManager(_action), _graphManager(_graph),
								       _map(map)
{
}

Game::~Game()
{
}

std::vector<APlayer*>           Game::getPlayers() const
{
	return _players;
}

Map&                             Game::getMap() const
{
	return _map;
}

void                            Game::setPlayers(std::vector<APlayer*> players)
{
	_players = players;
}

void				Game::setMap(Map& map)
{
	_map = map;
}

void				Game::addPlayer(APlayer* player)
{
	_players.push_back(player);
}

void				Game::updateMap()
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

void				Game::update(ActionManager& _action, GraphicManager& _graph)
{
	for (int i = 0; i < _players.size(); i++)
		_players[i++]->update(_action, _map, _graph.getSceneManager(),
				      _graph.getDevice());
	updateMap();
}

void				Game::display(GraphicManager& _graph)
{
	_map.renderMap(_graph);
	for (int i = 0; i < _powersUp.size(); i++)
		_powersUp[i]->renderPowerUp(_graph);
	dynamic_cast<Player *>(_players[0])->setCameraFocus(_graph);
}

void                            Game::addPowerUp(irr::core::vector3df pos)
{
	std::unique_ptr<APowerUp> powerup;
	
	powerup = _factory.createRandomPowerUp();
	powerup->setPosition(pos);
	_powersUp.push_back(std::move(powerup));
}
