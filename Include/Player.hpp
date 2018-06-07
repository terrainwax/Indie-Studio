//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class
//

#pragma once

#include <stdexcept>
#include "APlayer.hpp"
#include "Bomb.hpp"

class Player : public APlayer {
private:
	KeySet _keySet;
	irr::scene::IAnimatedMesh *_mesh;

	void 	updateAnimation(ActionManager &actionManager);
	void 	updatePos(ActionManager &actionManager, Map &map);
public:
	Player(int posX = 1, int posY = 1, std::string name = "PlayerX", irr::scene::ISceneManager *_smgr = nullptr, KeySet keyset = KeySetUtils::dflKeySet2);
	~Player();

	virtual void update(ActionManager &actionManager, GraphicManager &graphicManager, Map &map, std::vector<Bomb *> &bomb);
};
