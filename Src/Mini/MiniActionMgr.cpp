/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "MiniActionMgr.hpp"

MiniActionMgr::MiniActionMgr()
{
	for (std::size_t key = 0; key < irr::KEY_KEY_CODES_COUNT; key++)
		_currentState[key] = _previousState[key] = false;
}

MiniActionMgr::~MiniActionMgr()
{
	for (std::size_t key = 0; key < irr::KEY_KEY_CODES_COUNT; key++)
		_currentState[key] = _previousState[key] = false;
}

bool MiniActionMgr::isKeyPressed(irr::EKEY_CODE key)
{
	return (!_previousState[key] && _currentState[key]);
}

bool MiniActionMgr::isKeyReleased(irr::EKEY_CODE key)
{
	return (_previousState[key] && !_currentState[key]);
}

bool MiniActionMgr::isKeyDown(irr::EKEY_CODE key)
{
	return _currentState[key];
}

bool MiniActionMgr::isKeyUp(irr::EKEY_CODE key)
{
	return !_currentState[key];
}

bool MiniActionMgr::OnEvent(const irr::SEvent &e)
{
	if (e.EventType == irr::EET_KEY_INPUT_EVENT && e.KeyInput.PressedDown)
           	_currentState[e.KeyInput.Key] = true;

	return false;
}

void MiniActionMgr::flush()
{
	for (std::size_t key = 0; key < irr::KEY_KEY_CODES_COUNT; key++) {
		_previousState[key] = _currentState[key];
		_currentState[key] = false;
	}
}