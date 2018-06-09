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
	for (std::size_t x = 0; x < SEQUENCE_SIZE; x++)
		_sequence[x] = irr::KEY_UP;
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
		if (e.KeyInput.PressedDown)
		{
			for (std::size_t x = 1; x < SEQUENCE_SIZE; x++)
				_sequence[x - 1] = _sequence[x];
			_sequence[SEQUENCE_SIZE - 1] = e.KeyInput.Key;
		}
	}
	return false;
}

bool ActionManager::isKonami()
{
	return (_sequence[0] == irr::KEY_UP
	&& _sequence[1] == irr::KEY_UP
	&& _sequence[2] == irr::KEY_DOWN
	&& _sequence[3] == irr::KEY_DOWN
	&& _sequence[4] == irr::KEY_LEFT
	&& _sequence[5] == irr::KEY_RIGHT
	&& _sequence[6] == irr::KEY_LEFT
	&& _sequence[7] == irr::KEY_RIGHT);
}

void ActionManager::flush()
{
	for (int key = 0; key < irr::KEY_KEY_CODES_COUNT; key = key + 1)
	{
		_previousState[key] = _currentState[key];
		_currentState[key] = false;
	}
}