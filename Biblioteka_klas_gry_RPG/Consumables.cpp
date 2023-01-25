#include "Consumables.h"

Consumables::Consumables(std::string name, int value, Effect* effect)
	: Item(name, value), effect(effect) 
{
}

Effect* Consumables::getEffect()
{
    return effect;
}

