#include "Ability.h"

#include <stdexcept>

Ability::Ability(std::string name, AbilityType type, int damage, int mpCost, Effect effect)
    :name(name), type(type), mpCost(mpCost), effect(effect)
{
    setDmg(damage);
}

void Ability::setDmg(int dmg)
{
    if (dmg < 0) throw std::invalid_argument("Obrazenia nie moga byc ujemne");
    this->damage = dmg;
}

void Ability::setMpCost(int mpCost)
{
    if (mpCost < 0) throw std::invalid_argument("Koszt many nie moze byc ujemny");
    this->mpCost = mpCost;
}

std::string Ability::getName()
{
    return name;
}

AbilityType Ability::getType() const
{
    return type;
}

int Ability::getDmg() const
{
    return damage;
}

int Ability::getMpCost() const
{
    return mpCost;
}


Effect& Ability::getEffect()
{
    return effect;
}

bool Ability::getStatus() const
{
    return unlocked;
}

Ability* Ability::unlockAbility()
{
    unlocked = true;
    return this;
}
