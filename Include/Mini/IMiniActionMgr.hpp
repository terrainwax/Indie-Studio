/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "MiniBase.hpp"

class IMiniActionMgr : public irr::IEventReceiver {
public:
	IMiniActionMgr() = default;
	virtual ~IMiniActionMgr() = default;

	virtual bool isKeyUp(irr::EKEY_CODE key) = 0;
	virtual bool isKeyDown(irr::EKEY_CODE key) = 0;
	virtual bool isKeyPressed(irr::EKEY_CODE key) = 0;
	virtual bool isKeyReleased(irr::EKEY_CODE key) = 0;
	virtual void flush() = 0;

	virtual bool isKonami() = 0;

	virtual bool OnEvent(const irr::SEvent& event) override = 0;
};
