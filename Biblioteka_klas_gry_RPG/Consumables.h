#pragma once
#include "Ability.h"
#include "Item.h"

class Consumables : public Item
{
	Effect effect;

public:
	Consumables(std::string name, int value, Effect effect);
	Effect& getEffect();
};

