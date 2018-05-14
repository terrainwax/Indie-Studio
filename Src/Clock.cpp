/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "Clock.hpp"

Clock::Clock() : _currentTime(0), _lastTime(0), _elapsedTime(0), _totalTime(0)
{
	tick();
}

Clock::~Clock()
{
}

void Clock::tick()
{
	struct timeval currentTime;

	gettimeofday(&currentTime, nullptr);
	_currentTime = currentTime.tv_sec * 1e6 + currentTime.tv_usec;
	if (_lastTime == 0)
		_lastTime = _currentTime;

	_elapsedTime += _currentTime - _lastTime;
	_totalTime += _currentTime - _lastTime;
	_lastTime = _currentTime;
}

void Clock::frame()
{
	_elapsedTime = 0;
}

size_t Clock::elapsedMicroseconds() const
{
	return _elapsedTime;
}

size_t Clock::elapsedMilliseconds() const
{
	return _elapsedTime * 1e-3;
}

size_t Clock::elapsedSeconds() const
{
	return _elapsedTime * 1e-6;
}

size_t Clock::totalMicroseconds() const
{
	return _totalTime;
}

size_t Clock::totalMilliseconds() const
{
	return _totalTime * 1e-3;
}

size_t Clock::totalSeconds() const
{
	return _totalTime * 1e-6;
}