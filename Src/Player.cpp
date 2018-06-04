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

Player::Player(std::string name, irr::scene::ISceneManager *_smgr, KeySet keyset) :
APlayer(name),
_keySet(keyset)
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
}

Player::~Player()
{
}

void Player::updatePos(ActionManager &actionManager, Map &map)
{
	irr::core::vector3df pos = _anode->getPosition();
	irr::core::vector3df oldPos = pos;

	if (actionManager.isKeyDown(_keySet.upKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 0, 0));
		pos.Z += _speed;
	}
	if (actionManager.isKeyDown(_keySet.downKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 180, 0));
		pos.Z -= _speed;
	}
	if (actionManager.isKeyDown(_keySet.leftKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 270, 0));
		pos.X -= _speed;
	}
	if (actionManager.isKeyDown(_keySet.rightKey)) {
		_anode->setRotation(irr::core::vector3df(-90, 90, 0));
		pos.X += _speed;
	}
	if ((map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::Empty))
		_anode->setPosition(pos);
	if (map.getCell(irr::core::vector2di((((oldPos.Z / 10) + 0.5)), (oldPos.X / 10) + 0.5)) == Map::Cell::Bomb &&
		(map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::Empty ||
		map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::Bomb))
		_anode->setPosition(pos);
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
			_anode->setAnimationSpeed(30);
			_anode->setFrameLoop(100, 140);
		}
	}
	else {
		if (_anode->getFrameNr() < 250 && _anode->getEndFrame() == 258)
		{

		} else {
			_anode->setAnimationSpeed(30);
			_anode->setFrameLoop(0, 90);
		}
	}
}

void	Player::update(ActionManager &actionManager, GraphicManager &graphic, Map &map, std::vector<Bomb *> &bomb)
{
	irr::core::vector3df pos = _anode->getPosition();
	irr::scene::ISceneManager *_smgr = graphic.getSceneManager();
	irr::IrrlichtDevice *device = graphic.getDevice();

	this->updatePos(actionManager, map);
	this->updateAnimation(actionManager);
	if (actionManager.isKeyPressed(_keySet.bombKey) && _nbBomb != 0 && map.getCell(irr::core::vector2di((((pos.Z / 10) + 0.5)), (pos.X / 10) + 0.5)) != Map::Cell::Bomb) {
		_nbBomb -= 1;
		if (env == nullptr)
			env = device->getGUIEnvironment();
		if (font == nullptr)
			font = env->getFont("./Assets/Font/fonthaettenschweiler.bmp");
		std::string result = "Bombe NB : ";
		result = result + std::to_string(_nbBomb);
		if (nodeText == nullptr)
			nodeText = _smgr->addTextSceneNode(font, std::wstring(result.begin(), result.end()).c_str());
		nodeText->setScale(irr::core::vector3df(2,2,2));
		nodeText->setTextColor(irr::video::SColor(255, 255, 0, 0));
		nodeText->setPosition(irr::core::vector3df(pos.X, 10, pos.Z));
		_anode->setAnimationSpeed(60);
		_anode->setFrameLoop(200, 258);
		map.setCell(irr::core::vector2di((((pos.Z / 10) + 0.5)), (pos.X / 10) + 0.5), Map::Cell::Bomb);
		bomb.push_back(new Bomb(*this, _smgr));
	}
	if (nodeText != nullptr) {
		nodeText->setPosition(irr::core::vector3df(pos.X, 10, pos.Z));
		std::string result = "Bombe NB : ";
		result = result + std::to_string(_nbBomb);
		nodeText->setText(std::wstring(result.begin(), result.end()).c_str());
	}
}

void Player::setCameraFocus(GraphicManager &graphicManager)
{
	irr::core::vector3df pos = _anode->getPosition();

	graphicManager.setCameraTarget(pos);
	graphicManager.setCameraPosition(irr::core::vector3df(pos.X, pos.Y + 40 , pos.Z - 40));
}
