#include "Statistics.h"

#include <stdexcept>

Statistics::Statistics(int strength, int dexterity, int consitution, int intelligence, int wisdom, int charisma)
{
	setStrength(strength);
	setDexterity(dexterity);
	setConsitution(consitution);
	setIntelligence(intelligence);
	setWisdom(wisdom);
	setCharisma(charisma);
}

int Statistics::getStrength()
{
	return strength;
}

int Statistics::getDexterity()
{
	return dexterity;
}

int Statistics::getConsitution()
{
	return consitution;
}

int Statistics::getIntelligence()
{
	return intelligence;
}

int Statistics::getWisdom()
{
	return wisdom;
}

int Statistics::getCharisma()
{
	return charisma;
}

void Statistics::setStrength(int strength)
{
	if (strength < 0) throw std::invalid_argument("Sila musi byc liczba dodatnia");
	this->strength = strength;
}

void Statistics::setDexterity(int dexterity)
{
	if (dexterity < 0) throw std::invalid_argument("Zrecznosc musi byc liczba dodatnia");
	this->dexterity = dexterity;
}

void Statistics::setConsitution(int consitution)
{
	if (consitution < 0) throw std::invalid_argument("Kondycja musi byc liczba dodatnia");
	this->consitution = consitution;
}

void Statistics::setIntelligence(int intelligence)
{
	if (intelligence < 0) throw std::invalid_argument("Inteligencja musi byc liczba dodatnia");
	this->intelligence = intelligence;
}

void Statistics::setWisdom(int wisdom)
{
	if (wisdom < 0) throw std::invalid_argument("Madrosc musi byc liczba dodatnia");
	this->wisdom = wisdom;
}

void Statistics::setCharisma(int charisma)
{
	if (charisma < 0) throw std::invalid_argument("Charyzma musi byc liczba dodatnia");
	this->charisma = charisma;
}
