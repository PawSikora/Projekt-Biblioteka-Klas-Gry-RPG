#include "GameCharacterClass.h"

#include <stdexcept>

GameCharacterClass::GameCharacterClass(std::string name, std::vector<Ability*> abilities)
	:name(name), abilities(abilities)
{
}

std::string GameCharacterClass::getName()
{
	return name;
}

Ability* GameCharacterClass::getAbility(int index)
{
	if(index > 0 && index < abilities.size())
	{
		return abilities.at(index);
	}
	throw std::out_of_range("Przekroczono rozmiar tablicy");
}

