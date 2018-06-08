/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include "IMiniActionMgr.hpp"

class MiniActionMgr final : public IMiniActionMgr {
public:
	MiniActionMgr();
	~MiniActionMgr() override;

	bool isKeyUp(irr::EKEY_CODE key) override;
	bool isKeyDown(irr::EKEY_CODE key) override;
	bool isKeyPressed(irr::EKEY_CODE key) override;
	bool isKeyReleased(irr::EKEY_CODE key) override;

	virtual bool OnEvent(const irr::SEvent& event) override;

	void flush() override;
private:
	bool _currentState[irr::KEY_KEY_CODES_COUNT];
	bool _previousState[irr::KEY_KEY_CODES_COUNT];
};