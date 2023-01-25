#include "GameCharacterClass.h"

#include <stdexcept>

GameCharacterClass::GameCharacterClass(ClassType classType, std::vector<Ability*> abilities)
	:classType(classType), abilities(abilities)
{
}

std::string GameCharacterClass::getName()
{
	switch(classType)
	{
		  case ClassType::Warrior: return "Wojownik";
		  case ClassType::Rogue: return "Lotrzyk";
		  case ClassType::Mage: return "Mag";
		  default: throw std::runtime_error("Unsupported type");
	}
}

ClassType GameCharacterClass::getClassType()
{
	return classType;
}

void GameCharacterClass::addAbility(Ability* ability)
{
	if(ability != nullptr)
		abilities.push_back(ability);
}

void GameCharacterClass::abilityUnlocked(Ability* ability)
{
	if (ability != nullptr)
		unlockedAbilities.push_back(ability);
}

Ability* GameCharacterClass::getAbility(int index)
{
	if(index >= 0 && index < abilities.size())
	{
		return abilities.at(index);
	}
	throw std::out_of_range("Przekroczono rozmiar tablicy");
}

Ability* GameCharacterClass::getUnlockedAbility(int index)
{
	if (index >= 0 && index < unlockedAbilities.size())
	{
		return unlockedAbilities.at(index);
	}
	throw std::out_of_range("Przekroczono rozmiar tablicy");
}

std::string GameCharacterClass::getAbilities()
{
	if(abilities.size() > 0)
	{
		std::string abilitiesList = "";
		int count = 0;

		if (this->getNumOfUnlockedAbilities() > 0)
		{
			int count = 0;
			abilitiesList += "== Posiadane zdolnosci ==\n";
			for (auto ability : abilities)
			{
				if (ability->getStatus())
				{
					count++;
					abilitiesList += std::to_string(count) + ". " + ability->getName() + '\n';
				}
			}
		}

		abilitiesList += "\n== Dostepne zdolnosci ==\n";
		for (auto ability : abilities)
		{
			if (!ability->getStatus())
			{
				count++;
				abilitiesList += std::to_string(count) + ". " + ability->getName() + '\n';
			}

		}

		return abilitiesList;
	}
	throw std::out_of_range("Tablica jest pusta");
}

std::string GameCharacterClass::getUnlockedAbilities()
{
	if (this->getNumOfUnlockedAbilities() > 0)
	{
		std::string abilitiesList = "";
		int count = 0;
		abilitiesList += "== Posiadane zdolnosci ==\n";
		for (auto ability : unlockedAbilities)
		{
			if (ability->getStatus())
			{
				count++;
				abilitiesList += std::to_string(count) + ". " + ability->getName() + '\n';
			}
		}
		return abilitiesList;
	}

	return "\n Brak posiadanych zdolnosci!\n";
	
}

int GameCharacterClass::getNumOfAvailableAbilities()
{
	int i = 0;
	for (auto ability : abilities)
		if (!ability->getStatus())
			i++;
	return i;
}

int GameCharacterClass::getNumOfUnlockedAbilities()
{
	int i = 0;
	for (auto ability : abilities)
		if (ability->getStatus())
			i++;
	return i;
}

