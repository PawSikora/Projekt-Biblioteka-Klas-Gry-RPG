#include "Consumables.h"

Consumables::Consumables(std::string name, int value, Effect* effect)
	: Item(name, value), effect(effect) 
{
}

Effect* Consumables::getEffect() const
{
    return effect;
}

void Consumables::useItem()
{
	used = true;
}

bool Consumables::getUsed() const
{
	return used;
}

Consumables::~Consumables()
{
	if (effect != nullptr)
	{
		delete effect;
		effect = nullptr;
	}
}

