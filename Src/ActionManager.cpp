/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "ActionManager.hpp"

ActionManager::ActionManager()
{
	for (int key = 0; key < irr::KEY_KEY_CODES_COUNT; key = key + 1)
		_currentState[key] = _previousState[key] = false;
}

ActionManager::~ActionManager()
{
}

bool ActionManager::isKeyPressed(irr::EKEY_CODE key)
{
	return (!_previousState[key] && _currentState[key]);
}

bool ActionManager::isKeyReleased(irr::EKEY_CODE key)
{
	return (_previousState[key] && !_currentState[key]);
}

bool ActionManager::isKeyDown(irr::EKEY_CODE key)
{
	return _currentState[key];
}

bool ActionManager::isKeyUp(irr::EKEY_CODE key)
{
	return !_currentState[key];
}

void ActionManager::flush()
{
	for (int i = irr::KEY_LBUTTON; i < irr::KEY_KEY_CODES_COUNT; i++) {
		//_previousState[i] = _currentState[i];
		//_currentState[key] = _input->isKeyDown(key);
	}
}

bool ActionManager::OnEvent(const irr::SEvent &e)
{
	 if (e.EventType == irr::EET_KEY_INPUT_EVENT)
            _currentState[e.KeyInput.Key] = e.KeyInput.PressedDown;
	return false;
}