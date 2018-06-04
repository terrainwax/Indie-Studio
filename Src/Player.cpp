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
}

Player::~Player()
{
}

void Player::updatePos(ActionManager &actionManager, Map &map)
{
	irr::core::vector3df pos = _anode->getPosition();

	if (actionManager.isKeyDown(irr::KEY_KEY_Z)) {
		_anode->setRotation(irr::core::vector3df(-90, 0, 0));
		pos.Z += _speed;
	}
	if (actionManager.isKeyDown(irr::KEY_KEY_S)) {
		_anode->setRotation(irr::core::vector3df(-90, 180, 0));
		pos.Z -= _speed;
	}
	if (actionManager.isKeyDown(irr::KEY_KEY_Q)) {
		_anode->setRotation(irr::core::vector3df(-90, 270, 0));
		pos.X -= _speed;
	}
	if (actionManager.isKeyDown(irr::KEY_KEY_D)) {
		_anode->setRotation(irr::core::vector3df(-90, 90, 0));
		pos.X += _speed;
	}
	if ((map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5),
		(int)(pos.X / 10 + 0.5))) == Map::Cell::Empty) && (map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5),
		(int)(pos.X / 10 + 0.5))) == Map::Cell::Empty))
		_anode->setPosition(pos);
}

void Player::updateAnimation(ActionManager &actionManager)
{
	if (actionManager.isKeyDown(irr::KEY_KEY_Z) ||
		actionManager.isKeyDown(irr::KEY_KEY_S) ||
		actionManager.isKeyDown(irr::KEY_KEY_Q) ||
		actionManager.isKeyDown(irr::KEY_KEY_D))
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

void	Player::update(ActionManager &actionManager, Map &map, 	irr::scene::ISceneManager *_smgr, irr::IrrlichtDevice *device)
{
	(void)map;
	(void)actionManager;
	irr::core::vector3df pos = _anode->getPosition();

	this->updateAnimation(actionManager);
	if (actionManager.isKeyDown(irr::KEY_SPACE) && place == nullptr) {
		if (env == nullptr)
			env = device->getGUIEnvironment();
		if (font == nullptr)
			font = env->getFont("./Assets/Font/fonthaettenschweiler.bmp");
		_nbBomb -= 1;
		std::string result = "Bombe NB : ";
		result = result + std::to_string(_nbBomb);
		if (nodeText == nullptr)
			nodeText = _smgr->addTextSceneNode(font, std::wstring(result.begin(), result.end()).c_str());
		nodeText->setScale(irr::core::vector3df(2,2,2));
		nodeText->setTextColor(irr::video::SColor(255, 255, 0, 0));
		nodeText->setPosition(irr::core::vector3df(pos.X, 10, pos.Z));
		_anode->setAnimationSpeed(60);
		_anode->setFrameLoop(200, 258);
		place = new Bomb(1, (int)((pos.X / 10) + 0.5) * 10  ,(int)((pos.Z / 10) + 0.5) * 10 ,_smgr);
	}
	else if (place != nullptr) {
		if (place->update()) {
			place->explode(map);
			_smgr->addToDeletionQueue(place->getNode());
			place = nullptr;
			_nbBomb += 1;
		}
	}
	this->updatePos(actionManager, map);
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
