#include "Resistances.h"

#include <stdexcept>

Resistances::Resistances(int fireResistance, int coldResistance, int poisonResistance, int magicResistance, int bleedResistance)
{
	setFireResistance(fireResistance);
	setColdResistance(coldResistance);
	setPoisonResistance(poisonResistance);
	setMagicResistance(magicResistance);
	setBleedResistance(bleedResistance);
}

void Resistances::setFireResistance(int fireResistance)
{
	if (fireResistance < 0) throw std::invalid_argument("Odpornosc na ogien musi byc liczba dodatnia");
	this->fireResistance = fireResistance;
}

void Resistances::setColdResistance(int coldResistance)
{
	if (coldResistance < 0) throw std::invalid_argument("Odpornosc na zimno musi byc liczba dodatnia");
	this->coldResistance = coldResistance;
}

void Resistances::setPoisonResistance(int poisonResistance)
{
	if (poisonResistance < 0) throw std::invalid_argument("Odpornosc na trucizne musi byc liczba dodatnia");
	this->poisonResistance = poisonResistance;
}

void Resistances::setMagicResistance(int magicResistance)
{
	if (magicResistance < 0) throw std::invalid_argument("Odpornosc na magie musi byc liczba dodatnia");
	this->magicResistance = magicResistance;
}

void Resistances::setBleedResistance(int bleedResistance)
{
	if (bleedResistance < 0) throw std::invalid_argument("Odpornosc na krwawienie musi byc liczba dodatnia");
	this->bleedResistance = bleedResistance;
}

int Resistances::getFireResistance() const
{
	return fireResistance;
}

int Resistances::getColdResistance() const
{
	return coldResistance;
}

int Resistances::getPoisonResistance() const
{
	return poisonResistance;
}

int Resistances::getMagicResistance() const
{
	return magicResistance;
}

int Resistances::getBleedResistance() const
{
	return bleedResistance;
}

