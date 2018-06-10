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
	srand(time(nullptr));
}

AI::~AI()
{
}

void	AI::updatePos(irr::core::vector2di safePos, Map &map)
{
	irr::core::vector3df pos = this->_anode->getPosition();
	static char block = 0;
	char	check = 0;

	if (pos.X < safePos.X * 10 && (map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)((pos.X + this->_speed) / 10 + 0.5))) == Map::Cell::Empty
		|| map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)((pos.X + this->_speed) / 10 + 0.5))) == Map::Cell::PowerUp)) {
		this->_anode->setRotation(irr::core::vector3df(-90, 90, 0));
		pos.X += this->_speed;
		check++;
	} else if (pos.X > safePos.X * 10 && (map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)((pos.X - this->_speed) / 10 + 0.5))) == Map::Cell::Empty
		|| map.getCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)((pos.X - this->_speed) / 10 + 0.5))) == Map::Cell::PowerUp)) {
		this->_anode->setRotation(irr::core::vector3df(-90, 270, 0));
		pos.X -= this->_speed;
		check++;
	}
	if (pos.Z < safePos.Y * 10 && (map.getCell(irr::core::vector2di((int)((pos.Z + this->_speed) / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::Empty
		|| map.getCell(irr::core::vector2di((int)((pos.Z + this->_speed) / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::PowerUp)) {
		this->_anode->setRotation(irr::core::vector3df(-90, 0, 0));
		pos.Z += this->_speed;
		check++;
	} else if (pos.Z > safePos.Y * 10 && (map.getCell(irr::core::vector2di((int)((pos.Z - this->_speed) / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::Empty
		|| map.getCell(irr::core::vector2di((int)((pos.Z - this->_speed) / 10 + 0.5), (int)(pos.X / 10 + 0.5))) == Map::Cell::PowerUp)) {
		_anode->setRotation(irr::core::vector3df(-90, 180, 0));
		pos.Z -= this->_speed;
		check++;
	}
	if (pos.Z <= 10)
		pos.Z = 10;
	if (pos.X <= 10)
		pos.X = 10;
	if (check == 0)
		block++;
	if ((this->_isSet && (pos.Z - safePos.Y) <= 1 && (pos.Y - safePos.X) <= 1) || block == 10)
		this->_isSet = false;
	this->_anode->setPosition(pos);
}

irr::core::vector2di	AI::defend(Map &map, irr::core::vector2di safePos)
{
	int				size = map.getSize();
	char			newMap[size][size];
	char			d = 0;
	bool			safe = false;

	this->_isSet = false;
	memset(newMap, -1, size * size * sizeof(char));
	newMap[safePos.X][safePos.Y] = d;
	while (d <= size) {
		for (int x = 1; x < size - 1; x++) {
			for (int y = 1; y < size - 1; y++) {
				if (newMap[x][y] == d) {
					if (newMap[x][y + 1] == -1)
						newMap[x][y + 1] = d + 1;
               		if (newMap[x][y - 1] == -1)
               			newMap[x][y - 1] = d + 1;
           			if (newMap[x + 1][y] == -1)
               			newMap[x + 1][y] = d + 1;
           			if (newMap[x - 1][y] == -1)
               			newMap[x - 1][y] = d + 1;
               		if (this->isCellSafe({x, y}, map) && !safe) {
               			safePos.X = x;
               			safePos.Y = y;
               			safe = true;
               			break ;
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
	if (map.getCell(irr::core::vector2di(pos.Y, pos.X)) == Map::Cell::Wall
		|| map.getCell(irr::core::vector2di(pos.Y, pos.X)) == Map::Cell::Breakable
		|| map.getCell(irr::core::vector2di(pos.Y, pos.X)) == Map::Cell::Fire)
		return false;
  	for (int i = 0; i < size; i++) {
    	pos.Y = i;
    	if (map.getCell(irr::core::vector2di(pos.Y, pos.X)) == Map::Cell::Bomb)
      		return false;
  	}
  	pos.Y = (int) iaPos.Y;
  	for (int y = 0; y < size; y++) {
    	pos.X = y;
    	if (map.getCell(irr::core::vector2di(pos.Y, pos.X)) == Map::Cell::Bomb )
      		return false;
  	}
  	return true;
}

void	AI::attack(Map &map, std::vector<Bomb *> &bomb, irr::core::vector3df pos, GraphicManager &graph)
{
	irr::scene::ISceneManager *smgr = graph.getSceneManager();
	irr::core::vector2di	twodPos;
	int						nb = 0;

	twodPos.X = (int) (pos.X / 10 + 0.5);
	twodPos.Y = (int) (pos.Z / 10 + 0.5);
	if (this->_nbBomb != 0 && (map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X + 1)) == Map::Cell::Breakable
		|| map.getCell(irr::core::vector2di(twodPos.Y + 1, twodPos.X)) == Map::Cell::Breakable
		|| map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X -1)) == Map::Cell::Breakable
		|| map.getCell(irr::core::vector2di(twodPos.Y - 1, twodPos.X)) == Map::Cell::Breakable)) {
		this->_nbBomb--;
		map.setCell(irr::core::vector2di((int)(pos.Z / 10 + 0.5), (int)(pos.X / 10 + 0.5)), Map::Cell::Bomb);
		bomb.push_back(new Bomb(*this, smgr));
	//	twodPos = this->defend(map, twodPos);
	//	this->updatePos(twodPos, map);
	}
	//else {
		if (!this->_isSet) {
			this->_isSet = true;
			nb = rand() % 4;
			switch (nb) {
				case 0:
				if (map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X + 1)) != Map::Cell::Wall && map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X + 1)) != Map::Cell::Breakable && map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X + 1)) != Map::Cell::Bomb)
					this->_goal.X = twodPos.X + 10;
				break;
				case 1:
				if (map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X - 1)) != Map::Cell::Wall && map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X - 1)) != Map::Cell::Breakable && map.getCell(irr::core::vector2di(twodPos.Y, twodPos.X - 1)) != Map::Cell::Bomb)
					this->_goal.X = twodPos.X - 10;
				break;
				case 2:
				if (map.getCell(irr::core::vector2di(twodPos.Y + 1, twodPos.X)) != Map::Cell::Wall && map.getCell(irr::core::vector2di(twodPos.Y + 1, twodPos.X)) != Map::Cell::Breakable && map.getCell(irr::core::vector2di(twodPos.Y + 1, twodPos.X)) != Map::Cell::Bomb)
					this->_goal.Y = twodPos.Y + 10;
				break;
				case 3:
				if (map.getCell(irr::core::vector2di(twodPos.Y - 1, twodPos.X)) != Map::Cell::Wall && map.getCell(irr::core::vector2di(twodPos.Y - 1, twodPos.X)) != Map::Cell::Breakable && map.getCell(irr::core::vector2di(twodPos.Y - 1, twodPos.X)) != Map::Cell::Bomb)
					this->_goal.Y = twodPos.Y - 10;
				break;
			}
		}
		this->updatePos(this->_goal, map);
	//}
}

bool	AI::isInDanger(Map &map)
{
	int	size = map.getSize();
	irr::core::vector3df iaPos = this->_anode->getPosition();
	irr::core::vector2di pos;

	pos.X = (int) (iaPos.X / 10 + 0.5);
	pos.Y = (int) (iaPos.Z / 10 + 0.5);
	if (map.getCell(irr::core::vector2di(pos.Y, pos.X)) == Map::Cell::Bomb)
		return true;
	for (int i = 1; i < size - 1; i++) {
		if (map.getCell(irr::core::vector2di(i, pos.X)) == Map::Cell::Wall) {
			break ;
		}
		if (map.getCell(irr::core::vector2di(i, pos.X)) == Map::Cell::Bomb)
			return true;
	}
	pos.Y = (int) (iaPos.Z / 10 + 0.5);
	for (int y = 1; y < size - 1; y++) {
		if (map.getCell(irr::core::vector2di(pos.Y, y)) == Map::Cell::Wall) {
			break ;
		}
		if (map.getCell(irr::core::vector2di(pos.Y, y)) == Map::Cell::Bomb)
			return true;
	}
	return false;
}

void	AI::update(__attribute__((unused)) ActionManager &actionManager, GraphicManager &graph, Map &map, std::vector<Bomb *> &bomb)
{
	if (_alive == false && _anode != nullptr) {
		_smgr->addToDeletionQueue(_anode);
		_anode = nullptr;
	}
	if (_alive == false)
		return;
	irr::core::vector3df modPos = this->_anode->getPosition();
	irr::core::vector2di pos;

	pos.X = (int) modPos.X / 10 + 0.5;
	pos.Y = (int) modPos.Z / 10 + 0.5;
	if (this->isInDanger(map)) {
		pos = this->defend(map, pos);
		this->updatePos(pos, map);
	}
	else {
		this->attack(map, bomb, modPos, graph);
	}
}
