#pragma once
#include <string>
#include <vector>

#include "Ability.h"

class GameCharacterClass
{
	std::string name;
	std::vector<Ability*> abilities;

public:
	GameCharacterClass(std::string name, std::vector<Ability*> abilities);
	std::string getName();
	Ability* getAbility(int index);
	std::string getAbilities();
};

