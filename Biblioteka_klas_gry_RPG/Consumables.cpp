#include "Consumables.h"

Consumables::Consumables(Effect effect, Ability ability)
	:effect(effect),ability(ability)
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
