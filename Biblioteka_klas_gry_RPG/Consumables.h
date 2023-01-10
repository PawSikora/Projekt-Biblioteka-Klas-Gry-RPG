#pragma once
#include "Ability.h"

class Consumables
{
	Effect effect;
	Ability ability;

public:
	Consumables(Effect effect, Ability ability);
	Effect getEffect();
	Ability getAbility();
};

