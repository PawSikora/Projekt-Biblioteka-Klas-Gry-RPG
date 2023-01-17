#include "Consumables.h"

Consumables::Consumables(std::string name, int value, Effect effect, Ability ability)
	: Item(name, value), effect(effect),ability(ability)
{
}

Effect Consumables::getEffect()
{
    return effect;
}

Ability Consumables::getAbility()
{
    return ability;
}
