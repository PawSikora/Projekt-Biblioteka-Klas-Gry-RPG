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

std::string GameCharacterClass::getAbilities()
{
	if(abilities.size() > 0)
	{
		std::string abilitiesList = "";
		int count = 0;
		for (auto ability : abilities)
		{
			count++;
			abilitiesList += std::to_string(count) + ". " + ability->getName() + '\n';
		}
		return abilitiesList;
	}
	throw std::out_of_range("Tablica jest pusta");
}

