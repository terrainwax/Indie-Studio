//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class
//

#pragma once

#include "APlayer.hpp"

class Player : public APlayer {
private:
	irr::scene::IAnimatedMeshSceneNode* _anode;
	irr::scene::IAnimatedMesh* _mesh;

public:
	Player(std::string name = "PlayerX", irr::scene::ISceneManager *_smgr = nullptr);
	~Player();

	void 	setCameraFocus(GraphicManager &graphicManager);
	virtual void update(ActionManager &actionManager, Map &map);
};
