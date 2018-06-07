//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class implementation
//

#include <unistd.h>
#include <iostream>
#include "Player.hpp"
#include "GraphicManager.hpp"

Player::Player(int posX, int posY, std::string name, irr::scene::ISceneManager *smgr, KeySet keyset) :
APlayer(smgr, name),
_keySet(keyset)
{
	_mesh = _smgr->getMesh("./Assets/Models/0112.x");
	if (_mesh == nullptr)
		throw std::runtime_error("Cannot get mesh");
	_anode = _smgr->addAnimatedMeshSceneNode(_mesh);
	if (_anode == nullptr)
		throw std::runtime_error("Cannot get node");
	_anode->setPosition(irr::core::vector3df(10 * posX, -4, 10 * posY));
	_anode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, false);
	_anode->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
	_anode->setAnimationSpeed(30);
	_anode->setRotation(irr::core::vector3df(-90,0,0));
	_anode->setScale(irr::core::vector3df(0.008,0.008,0.008));
	_anode->setFrameLoop(0, 90);
}

Player::~Player()
{
}

void Player::updatePos(ActionManager &actionManager, Map &map)
{
	irr::core::vector3df pos = _anode->getPosition();

	if (actionManager.isKeyDown(_keySet.upKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 0, 0));
		pos.Z += _speed;
	}
	else if (actionManager.isKeyDown(_keySet.downKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 180, 0));
		pos.Z -= _speed;
	}
	else if (actionManager.isKeyDown(_keySet.leftKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 270, 0));
		pos.X -= _speed;
	}
	else if (actionManager.isKeyDown(_keySet.rightKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 90, 0));
		pos.X += _speed;
	}

	Map::Cell center = map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)(pos.X / 10 + 0.5)));
	Map::Cell top = map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.3), (int)(pos.X / 10 + 0.5)));
	Map::Cell bottom = map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.7), (int)(pos.X / 10 + 0.5)));
	Map::Cell left = map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)(pos.X / 10 + 0.3)));
	Map::Cell right = map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)(pos.X / 10 + 0.7)));

	if ((center == Map::Cell::Empty || center == Map::Cell::Bomb || (center == Map::Cell::Breakable && _wallPass)) && (left == Map::Cell::Empty || left == Map::Cell::Bomb || (left == Map::Cell::Breakable && _wallPass)) &&
	(right == Map::Cell::Empty || right == Map::Cell::Bomb || (right == Map::Cell::Breakable && _wallPass)) && (top == Map::Cell::Empty || top == Map::Cell::Bomb || (top == Map::Cell::Breakable && _wallPass)) && (bottom == Map::Cell::Empty || bottom == Map::Cell::Bomb || (bottom == Map::Cell::Breakable && _wallPass)))
	{
		_anode->setPosition(pos);
	}
}

void Player::updateAnimation(ActionManager &actionManager)
{
	if (actionManager.isKeyDown(_keySet.upKey) ||
		actionManager.isKeyDown(_keySet.downKey) ||
		actionManager.isKeyDown(_keySet.leftKey) ||
		actionManager.isKeyDown(_keySet.rightKey))
	{
		if (_anode->getFrameNr() < 250 && _anode->getEndFrame() == 258)
		{

		}
		else if (_anode->getStartFrame() != 100) {
			_anode->setAnimationSpeed(_speed * 60);
			_anode->setFrameLoop(100, 140);
		}
	}
	else {
		if (_anode->getFrameNr() < 250 && _anode->getEndFrame() == 258)
		{

		} else {
			_anode->setAnimationSpeed(_speed * 60);
			_anode->setFrameLoop(0, 90);
		}
	}
}

void	Player::update(ActionManager &actionManager, GraphicManager &graphic, Map &map, std::vector<Bomb *> &bomb)
{
	irr::scene::ISceneManager *_smgr = graphic.getSceneManager();
	if (_alive == false && _anode != nullptr) {
		_smgr->addToDeletionQueue(_anode);
		_anode = nullptr;
	}
	if (_alive == false)
		return;

	this->updatePos(actionManager, map);
	this->updateAnimation(actionManager);
	irr::core::vector3df pos = _anode->getPosition();
	if (actionManager.isKeyPressed(_keySet.bombKey) && _nbBomb != 0 && map.getCell(irr::core::vector2di((((pos.Z / 10) + 0.5)), (pos.X / 10) + 0.5)) != Map::Cell::Bomb) {
		_nbBomb -= 1;
		_anode->setAnimationSpeed(60);
		_anode->setFrameLoop(200, 258);
		map.setCell(irr::core::vector2di((((pos.Z / 10) + 0.5)), (pos.X / 10) + 0.5), Map::Cell::Bomb);
		bomb.push_back(new Bomb(*this, _smgr));
	}
}