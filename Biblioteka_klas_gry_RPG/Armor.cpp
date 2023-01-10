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

void Armor::setMobilityPenalty(int MobilityPenalty)
{
	if (mobilityPenalty < 0) throw std::invalid_argument("Kara do poruszania sie  nie moze byc ujemna");
	this->mobilityPenalty = mobilityPenalty;
}

int Armor::getDefense()
{
	return defense;
}

int Armor::getMobilityPenalty()
{
	return mobilityPenalty;
}

Resistances Armor::getResistances()
{
	return resistances;
}
