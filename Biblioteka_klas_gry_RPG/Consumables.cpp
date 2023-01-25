#include "Consumables.h"

Consumables::Consumables(std::string name, int value, Effect* effect)
	: Item(name, value), effect(effect) 
{
}

Effect* Consumables::getEffect()
{
    return effect;
}

void Consumables::useItem()
{
	used = true;
}

bool Consumables::getUsed()
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

