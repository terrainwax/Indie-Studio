#include <iostream>

#include "AI.hpp"

AI::AI(int posX, int posY, std::string name, irr::scene::ISceneManager *smgr) :
APlayer(smgr, name)
{
	this->_mesh = smgr->getMesh("./Assets/Models/0113.x");
	this->_anode = smgr->addAnimatedMeshSceneNode(this->_mesh);
	this->_anode->setPosition(irr::core::vector3df(10 * posX, -4, 10 * posY));
	this->_anode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	this->_anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, false);
	this->_anode->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
	this->_anode->setAnimationSpeed(30);
	this->_anode->setRotation(irr::core::vector3df(-90,0,0));
	this->_anode->setScale(irr::core::vector3df(0.008,0.008,0.008));
	this->_anode->setFrameLoop(0, 90);
}

AI::~AI()
{
}

void	AI::updatePos(irr::core::vector2di safePos)
{
	irr::core::vector3df pos = this->_anode->getPosition();

	if (pos.X < safePos.X) {
		this->_anode->setRotation(irr::core::vector3df(-90, 90, 0));
		pos.X += this->_speed;
	} else {
		this->_anode->setRotation(irr::core::vector3df(-90, 270, 0));
		pos.X -= this->_speed;
	}
	if (pos.Z < safePos.Y) {
		this->_anode->setRotation(irr::core::vector3df(-90, 0, 0));
		pos.Z += this->_speed;
	} else {
		_anode->setRotation(irr::core::vector3df(-90, 180, 0));
		pos.Z -= this->_speed;
	}
	this->_anode->setPosition(pos);
}

irr::core::vector2di	AI::defend(Map &map, irr::core::vector2di safePos)
{
	int				size = map.getSize();
	char			newMap[size][size] = {{-1}};
	char			d = 0;

	newMap[safePos.X][safePos.Y] = d;
	while (1) {
		for (int x = 0; x < (size * 10); x++) {
			for (int y = 0; y < (size * 10); y++) {
				if (newMap[x][y] == d) {
					if (newMap[y][x + 1] == -1)
						newMap[y][x + 1] = d + 1;
               		if (newMap[y][x - 1] == -1)
               			newMap[y][x - 1] = d + 1;
           			if (newMap[y + 1][x] == -1)
               			newMap[y + 1][x] = d + 1;
           			if (newMap[y - 1][x] == -1)
               			newMap[y - 1][x] = d + 1;
               		if (this->isCellSafe({x, y}, map)) {
               			safePos.X = x;
               			safePos.Y = y;
               			break;
               		}
               	}
			}
		}
		d++;
	}
	return safePos;
}

bool	AI::isCellSafe(irr::core::vector2di iaPos, Map &map)
{
	int	size = map.getSize();
	irr::core::vector2di pos;

	pos.X = (int) iaPos.X;
	pos.Y = (int) iaPos.Y;
	for (int i = 0; i < size; i++) {
		pos.Y = i;
		if (map.getCell(irr::core::vector2di((int)(pos.Y / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::Bomb)
			return false;
	}
	pos.Y = (int) iaPos.Y;
	for (int y = 0; y < size; y++) {
		pos.X = y;
		if (map.getCell(irr::core::vector2di((int)(pos.Y / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::Bomb)
			return false;
	}
	return true;
}

void	AI::attack(Map &map, std::vector<Bomb *> &bomb, irr::core::vector3df pos, GraphicManager &graph)
{
/*	irr::scene::ISceneManager *smgr = graph.getSceneManager();

	if (this->_nbBomb != 0) {
		this->_nbBomb--;
		map.setCell(irr::core::vector2di((((pos.Z / 10) + 0.5)), (pos.X / 10) + 0.5), Map::Cell::Bomb);
		bomb.push_back(new Bomb(*this, smgr));
		this->updatePos(irr::core::vector2di(pos.Z - 5, pos.X));
	}*/
}

bool	AI::isInDanger(Map &map)
{
	int	size = map.getSize();
	irr::core::vector3df iaPos = this->_anode->getPosition();
	irr::core::vector2di pos;

	pos.X = (int) (iaPos.X / 10) + 0.5;
	pos.Y = (int) (iaPos.Z / 10) + 0.5;
	for (int i = 0; i < size; i++) {
		//std::cout << "ai: pos.Y:" << (pos.Y / 10) + 0.5 << " pos.X:" << (pos.X / 10) + 0.5 << std::endl;
		if (map.getCell(irr::core::vector2di(i, pos.X)) == Map::Cell::Bomb)
			return true;
	}
	pos.Y = (int) (iaPos.Z / 10) + 0.5;
	for (int y = 0; y < size; y++) {
		//std::cout << "ai: pos.Y:" << (pos.Y / 10) + 0.5 << " pos.X:" << (pos.X / 10) + 0.5 << std::endl;
		if (map.getCell(irr::core::vector2di(pos.Y, y)) == Map::Cell::Bomb)
			return true;
	}
	return false;
}

void	AI::update(__attribute__((unused)) ActionManager &actionManager, GraphicManager &graph, Map &map, std::vector<Bomb *> &bomb)
{
	irr::scene::ISceneManager *_smgr = graph.getSceneManager();
	if (_alive == false && _anode != nullptr) {
		_smgr->addToDeletionQueue(_anode);
		_anode = nullptr;
	}
	if (_alive == false)
		return;
	irr::core::vector3df modPos = this->_anode->getPosition();
	irr::core::vector2di pos;

	pos.X = modPos.X;
	pos.Y = modPos.Z;
	if (this->isInDanger(map)) {
		//std::cout << "danger" << std::endl;
		//pos = this->defend(map, pos);
		//this->updatePos(pos);
	}
	else {
		//std::cout << "attack" << std::endl;
		this->attack(map, bomb, modPos, graph);
	}
}