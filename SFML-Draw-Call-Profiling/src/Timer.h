#pragma once
#include <SFML/System.hpp>

class Timer {
private:
	int count = 0;
	int maxCount;
	double timeTracked = 0;
	sf::Clock clock;
	std::string name;

public:

	Timer(std::string name, int maxCount) : name(name), maxCount(maxCount) {}
	~Timer() {}

	void start();
	void stop();

	void clear();
	void setMaxCount(int maxCount);

private:
	double getTicksPerSecond() const;
	void printStats() const;
};