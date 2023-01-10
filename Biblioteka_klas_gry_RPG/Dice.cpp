#include "Dice.h"

void Dice::setNumSides(int num_sides)
{
	if (num_sides <= 0) throw std::invalid_argument("Kostka musi miec dodatnia liczbe scian");
	this->num_sides = num_sides;
}

Dice::Dice(int num_sides)
	:generator(std::random_device()())
{
	setNumSides(num_sides);
}

Dice::Dice(int num_sides, int seed)
	:generator(seed)
{
	setNumSides(num_sides);
}

int Dice::roll()
{
	std::uniform_int_distribution<int> distribution(1, num_sides);
	return distribution(generator);
}
