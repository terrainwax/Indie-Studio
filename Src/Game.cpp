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

Game::Game(int mapSize) :
_map(Map(mapSize, 60)),
_skyView(true)
{
}

Game::~Game()
{
	for (int i = 0; i < _bomb.size(); i++)
		delete _bomb[i];
	for (int i = 0; i < _players.size(); i++) {
		delete _players[i];
	}
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
				if (rand() % 100 < 70)
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

void Game::explodeBomb(int idx)
{
	Bomb *bomb = _bomb[idx];
	_bomb.erase(_bomb.begin() + idx);
	_map.setCell(irr::core::vector2di(bomb->getYMapPos() / 10, bomb->getXMapPos() / 10), Map::Cell::Empty);
	bomb->explode(_map, _players, _bomb);
	int posX = bomb->getXMapPos() / 10;
	int posY = bomb->getYMapPos() / 10;
	int radius = bomb->getRadius();
	delete bomb;
	for (int i = 0; i < _bomb.size(); i++) {
		int bombX = _bomb[i]->getXMapPos() / 10;
		int bombY = _bomb[i]->getYMapPos() / 10;
		if (bombX >= posX - radius && bombX <= posX + radius && posY == bombY) {
			this->explodeBomb(i);
			i = 0;
		}
		if (bombY >= posY - radius && bombY <= posY + radius && posX == bombX) {
			this->explodeBomb(i);
			i = 0;
		}
	}

}

void Game::triggerBomb(SoundManager &sound)
{
	for (int i = 0; i < _bomb.size(); i++) {
		if (_bomb[i]->update()) {
			sound.playSound(SOUND("Explosion.ogg"));	
			this->explodeBomb(i);
			i = 0;
		}
	}
}

void Game::update(ActionManager& action, GraphicManager& graph, SoundManager &sound)
{
	for (int i = 0; i < _players.size(); i++) {
		_players[i]->update(action, graph, _map, _bomb);
		this->pickUpBonus(*_players[i]);
	}
	this->triggerBomb(sound);
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
