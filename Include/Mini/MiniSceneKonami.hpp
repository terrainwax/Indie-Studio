/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniScene.hpp"
#include "MiniPlayer.hpp"
#include "MiniDino.hpp"
#include "MiniBomb.hpp"

#define PLAYER_SPEED 1.0f
#define BOMB_SPEED 1.0f

#define DINO_NBR 6
#define DINOS_ON_MAP 3

class MiniSceneKonami final : public MiniScene {
public:
	MiniSceneKonami();
	~MiniSceneKonami() override;

	MiniScene *clone() override;

	void start(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;
	void stop(IMiniCore *core, IMiniAudioMgr *audio, IMiniVideoMgr *video) override;

	void updateFrame(IMiniCore *core, IMiniActionMgr *action, IMiniAudioMgr *audio, const Clock &clock) override;
	void renderFrame(IMiniCore *core, IMiniVideoMgr *video, IMiniAudioMgr *audio, const Clock &clock) override;

	void updatePlayers(IMiniActionMgr *action);
	void updateDinos(IMiniCore *core);
	bool isGameEnded();
	float lePolynome(float size);


private:
	MiniSprite	_back;
	MiniSprite	_block;
	MiniPlayer	_playerWhite;
	MiniPlayer	_playerBlack;
	MiniBomb	_base_bomb;
	bool		_gameEnded;

	MiniDino	_dinos[DINO_NBR];
	int		_dinosOnMap;

	std::vector<MiniBomb> _bombs;
};
