//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class implementation
//

#include "Player.hpp"
#include "GraphicManager.hpp"
#include <iostream>

Player::Player(std::string name, irr::scene::ISceneManager *_smgr) : APlayer(name)
{
	_mesh = _smgr->getMesh("./Assets/Models/0112.x");


	_anode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_anode->setPosition(irr::core::vector3df(10,-4,20));
	_anode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, false);
	_anode->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
	_anode->setAnimationSpeed(30);
	_anode->setRotation(irr::core::vector3df(-90,0,0));
	_anode->setScale(irr::core::vector3df(0.008,0.008,0.008));
	_anode->setFrameLoop(0, 90);
	this->place = nullptr;
	this->_smgr = _smgr;
}

Player::~Player()
{
}

void	Player::update(ActionManager &actionManager, Map &map)
{
	(void)map;
	(void)actionManager;
	irr::core::vector3df pos = _anode->getPosition();

	if (actionManager.isKeyDown(irr::KEY_KEY_Z) ||
		actionManager.isKeyDown(irr::KEY_KEY_S) ||
		actionManager.isKeyDown(irr::KEY_KEY_Q) ||
		actionManager.isKeyDown(irr::KEY_KEY_D))
	{
		if (_anode->getStartFrame() != 100)
		_anode->setFrameLoop(100, 140);
	}
	else
		_anode->setFrameLoop(0, 90);
		if (actionManager.isKeyDown(irr::KEY_SPACE) && place == nullptr)
		{
			place = new Bomb(1, (int)((pos.X / 10) + 0.5) * 10  ,(int)((pos.Z / 10) + 0.5) * 10 ,_smgr);
		}
		else if (place != nullptr) {
			if (place->update()) {
				place->explode(map);
				_smgr->addToDeletionQueue(place->getNode());
				place = nullptr;
			}
		}
		if (actionManager.isKeyDown(irr::KEY_KEY_Z)) {
			_anode->setRotation(irr::core::vector3df(-90, 0, 0));
			pos.Z += _speed;
		} else if (actionManager.isKeyDown(irr::KEY_KEY_S)) {
			_anode->setRotation(irr::core::vector3df(-90, 180, 0));
			pos.Z -= _speed;
		} else if (actionManager.isKeyDown(irr::KEY_KEY_Q)) {
			_anode->setRotation(irr::core::vector3df(-90, 270, 0));
			pos.X -= _speed;
		} else if (actionManager.isKeyDown(irr::KEY_KEY_D)) {
			_anode->setRotation(irr::core::vector3df(-90, 90, 0));
			pos.X += _speed;
		}
	if ((map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5),
		(int)(pos.X / 10 + 0.5))) == Map::Cell::Empty) && (map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5),
		(int)(pos.X / 10 + 0.5))) == Map::Cell::Empty))
		_anode->setPosition(pos);
}


void Player::setCameraFocus(GraphicManager &graphicManager)
{
	irr::core::vector3df pos = _anode->getPosition();

	graphicManager.setCameraTarget(pos);
	graphicManager.setCameraPosition(irr::core::vector3df(pos.X, pos.Y + 40 , pos.Z - 40));
}