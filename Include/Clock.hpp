/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <cstddef>
#include <sys/time.h>

class Clock final {
public:
	Clock();
	~Clock();

	void tick();
	void frame();

	size_t elapsedMicroseconds() const;
	size_t elapsedMilliseconds() const;
	size_t elapsedSeconds() const;

	size_t totalMicroseconds() const;
	size_t totalMilliseconds() const;
	size_t totalSeconds() const;

private:
	std::size_t _currentTime;
	std::size_t _lastTime;
	std::size_t _elapsedTime;
	std::size_t _totalTime;
};