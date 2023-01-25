#include "Ability.h"

#include <stdexcept>

void Ability::setDmg(int dmg)
{
    if (dmg < 0) throw std::invalid_argument("Obrazenia nie moga byc ujemne");
    this->damage = dmg;
}

Ability::Ability(std::string name, AbilityType type, int damage, Effect effect)
	:name(name),type(type),effect(effect)
{
    setDmg(damage);
}

std::string Ability::getName()
{
    return name;
}

AbilityType Ability::getType()
{
    return type;
}

int Ability::getDmg()
{
    return damage;
}

Effect& Ability::getEffect()
{
    return effect;
}

bool Ability::getStatus()
{
    return unlocked;
}

Ability* Ability::unlockAbility()
{
    unlocked = true;
    return this;
}
