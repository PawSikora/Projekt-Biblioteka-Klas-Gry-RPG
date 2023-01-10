#pragma once
#include <random>

class Dice
{
	int num_sides;
	std::mt19937 generator;

	void setNumSides(int num_sides);
public:
	Dice(int num_sides);
	Dice(int num_sides, int seed);
	int roll();
};

