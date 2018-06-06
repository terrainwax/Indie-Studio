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

bool ActionManager::OnEvent(const irr::SEvent &e)
{
	if (e.EventType == irr::EET_KEY_INPUT_EVENT) {
		_previousState[e.KeyInput.Key] = _currentState[e.KeyInput.Key];
           	_currentState[e.KeyInput.Key] = e.KeyInput.PressedDown;
	}
	return false;
}

void ActionManager::flush()
{
	for (int key = 0; key < irr::KEY_KEY_CODES_COUNT; key = key + 1)
	{
		_previousState[key] = _currentState[key];
		_currentState[key] = false;
	}
}