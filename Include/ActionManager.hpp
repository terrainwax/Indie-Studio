/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#include <Keycodes.h>
#include <IEventReceiver.h>
#pragma GCC diagnostic warning "-Wunused-parameter"

class ActionManager final : public irr::IEventReceiver {
public:
	ActionManager();
	~ActionManager() override;

	bool isKeyUp(irr::EKEY_CODE key);
	bool isKeyDown(irr::EKEY_CODE key);
	bool isKeyPressed(irr::EKEY_CODE key);
	bool isKeyReleased(irr::EKEY_CODE key);
	virtual bool OnEvent(const irr::SEvent& event) override;
private:
	bool _currentState[irr::KEY_KEY_CODES_COUNT];
	bool _previousState[irr::KEY_KEY_CODES_COUNT];
};