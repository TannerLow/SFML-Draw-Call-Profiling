#include "Timer.h"
#include <stdio.h>

void Timer::start() {
	clock.restart();
}

void Timer::stop() {
	timeTracked += clock.getElapsedTime().asSeconds();
	clock.stop();
	count++;
	if (count >= maxCount) {
		printStats();
		clear();
	}
}

double Timer::getTicksPerSecond() const {
	return 1.0 / (timeTracked / maxCount);
}

void Timer::printStats() const {
	printf("Timer [%s] average ticks per second across %d ticks: %.2f\n", name.c_str(), maxCount, getTicksPerSecond());
}

void Timer::clear() {
	count = 0;
	timeTracked = 0;
	clock.reset();
}

void Timer::setMaxCount(int maxCount) {
	this->maxCount = maxCount;
}

void Timer::setName(std::string name) {
	this->name = name;
}

void Timer::set(std::string name, int maxCount) {
	setName(name);
	setMaxCount(maxCount);
}
