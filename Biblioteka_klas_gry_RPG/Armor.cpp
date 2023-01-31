#include "Armor.h"

#include <stdexcept>

Armor::Armor(std::string name, int value, int defense, int mobilityPenalty, Resistances resistances)
	:Item(name,value),resistances(resistances)
{
	setDefense(defense);
	setMobilityPenalty(mobilityPenalty);
}

void Armor::setDefense(int defense)
{
	if (defense < 0) throw std::invalid_argument("Kara do obrony nie moze byc ujemna");
	this->defense = defense;
}

void Armor::setMobilityPenalty(int mobilityPenalty)
{
	if (mobilityPenalty < 0) throw std::invalid_argument("Kara do poruszania sie  nie moze byc ujemna");
	this->mobilityPenalty = mobilityPenalty;
}

int Armor::getDefense() const
{
	return defense;
}

int Armor::getMobilityPenalty() const
{
	return mobilityPenalty;
}

Resistances Armor::getResistances() const
{
	return resistances;
}

bool Armor::equipArmor()
{
	if (!equip)
		equip = true;
	return equip;
}

bool Armor::unequipArmor()
{
	if (equip)
		equip = false;
	return equip;
}

bool Armor::isEquipped() const
{
	return equip;
}
