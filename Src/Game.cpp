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

void				Game::update(ActionManager& _action, GraphicManager& _graph)
{
	for (int i = 0; i < _players.size(); i++)
		_players[i++]->update(_action, _map, _graph.getSceneManager(), _graph.getDevice());
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
	auto powerUp = _powersUp.end();

	*powerUp = _factory.createRandomPowerUp();
	(*powerUp)->setPosition(pos);
}
