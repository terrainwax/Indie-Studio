#pragma once

#include <string>

#include "APlayer.hpp"
#include "ActionManager.hpp"
#include "Map.hpp"

class AI : public APlayer
{
public:
	AI(std::string name, irr::scene::ISceneManager *smgr);
	~AI();
	
	void	update(ActionManager &actionManager, GraphicManager &graph, Map &map, std::vector<Bomb *> &bomb);

private:
	bool	isInDanger(Map &map);
	irr::core::vector2di	defend(Map &map, irr::core::vector2di safePos);
	void	attack(Map &map, std::vector<Bomb *> &bomb, irr::core::vector3df pos, GraphicManager &graph);
	void	updatePos(irr::core::vector2di safePos);
	bool	isCellSafe(irr::core::vector2di iaPos, Map &map);
};