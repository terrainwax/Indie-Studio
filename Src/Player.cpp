//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class implementation
//

#include "Player.hpp"

Player::Player(std::string name, irr::scene::ISceneManager *_smgr) : APlayer(name)
{
	_mesh = _smgr->getMesh("./Assets/Models/0112.x");


	_anode = _smgr->addAnimatedMeshSceneNode(_mesh);
	_anode->setPosition(irr::core::vector3df(10,0,20));
	_anode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, false);
	_anode->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
	_anode->setAnimationSpeed(15);
	_anode->setRotation(irr::core::vector3df(-90,0,0));
	_anode->setScale(irr::core::vector3df(0.008,0.008,0.008));
	_anode->setFrameLoop(0, 90);
	//anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
}

Player::~Player()
{
}

void	Player::update(ActionManager &actionManager, Map &map)
{
	(void)map;
	(void)actionManager;
}