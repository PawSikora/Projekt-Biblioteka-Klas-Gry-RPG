#pragma once
#include "Ability.h"
#include "Item.h"

class Consumables : public Item
{
	Effect effect;
	Ability ability;

public:
	Consumables(std::string name, int value, Effect effect, Ability ability);
	Effect getEffect();
	Ability getAbility();
};

