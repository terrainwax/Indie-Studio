//
// EPITECH PROJECT, 2018
// indie studio
// File description:
// player class
//

#pragma once

#include "APlayer.hpp"
#include "Bomb.hpp"

class Player : public APlayer {
private:
	irr::scene::IAnimatedMesh* _mesh;
	Bomb *place;
	irr::gui::IGUIEnvironment* env = nullptr;
	irr::gui::IGUIFont* font = nullptr;
	irr::scene::ITextSceneNode* nodeText = nullptr;
	KeySet _keySet;

	void 	updateAnimation(ActionManager &actionManager);
	void 	updatePos(ActionManager &actionManager, Map &map);
public:
	Player(std::string name = "PlayerX", irr::scene::ISceneManager *_smgr = nullptr, KeySet keyset = KeySetUtils::dflKeySet2);
	~Player();

	void 	setCameraFocus(GraphicManager &graphicManager);
	virtual void update(ActionManager &actionManager, Map &map, irr::scene::ISceneManager *_smgr, irr::IrrlichtDevice *device);
};
